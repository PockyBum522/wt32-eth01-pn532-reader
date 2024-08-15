#include <Arduino.h>
#include <Adafruit_SPIDevice.h>
#include <Adafruit_PN532.h>
#include <ETH.h>
#include <ElegantOTA.h>
#include <PubSubClient.h>
#include <iostream>
#include <backtrace_saver.hpp>
#include <ESP32Time.h>

#include "SECRETS/SECRETS.h"

// TO USE CRASH ADDRESSES REPORTED ON STARTUP, RUN:
// C:\Users\David\.platformio\packages\toolchain-xtensa-esp-elf\bin\xtensa-esp32-elf-addr2line.exe -pfiaC -e D:\repos\wt32-eth01-pn532-reader\.pio\build\wt32-eth01\firmware.elf -a

// EXAMPLE ADDRESSES: C:\Users\David\.platformio\packages\toolchain-xtensa-esp-elf\bin\xtensa-esp32-elf-addr2line.exe -pfiaC -e D:\repos\wt32-eth01-pn532-reader\.pio\build\wt32-eth01\firmware.elf -a 400d41b3 400e854f 4008308d 40084b88 40082c35 4008de91 40082ca6 400d3aa5 400d4132 400dfbed 0 0 0 0 0 0 0 0 0 0

// Replace the addresses on the end with the crash data, obviously.

String m_versionMessage = "v0.01";

// SET THESE TWO TO FALSE BEFORE UPLOADING OTA OR TO REAL BOARD
bool m_debug_on = false;
bool m_test_mode_no_network_no_nfc = false;

bool m_nfcInitializedOnBoot = false;

WebServer server(80);
String header;      // Variable to store the HTTP request

WiFiClient ethernetClient;
PubSubClient mqttClient(ethernetClient);

ESP32Time rtc(0);

#define PN532_MOSI 4
#define PN532_SS   14
#define PN532_MISO 36
#define PN532_SCK  32

auto spiDevice = new Adafruit_SPIDevice(PN532_SS, PN532_SCK, PN532_MISO, PN532_MOSI,
    300000, SPI_BITORDER_LSBFIRST, SPI_MODE0);

Adafruit_PN532 m_nfc(PN532_SS, spiDevice);

String decToHex(byte decValue, byte desiredStringLength);
void mqttCallback(const char *topic, const byte *payload, unsigned int length);
void dumpLastCrashDataToMqtt();

void delayBootForSerialStart();
void serialPrintNetworkInformation();
void initializeNfcBoard();
void setupElegantOtaServer();
void connectToMqtt();
void sendNetworkInfoToMqtt();
void warnIfTestModeEnabled();

void setup()
{
    Serial.begin(115200);

    delayBootForSerialStart();

    warnIfTestModeEnabled();

    if (m_test_mode_no_network_no_nfc) return;

    ETH.begin(ETH_PHY_ADDR, ETH_PHY_POWER);
    serialPrintNetworkInformation();

    initializeNfcBoard();

    setupElegantOtaServer();

    connectToMqtt();

    sendNetworkInfoToMqtt();
}

void CheckForNfcTag();
void Log(const std::string& message);
void Log(const StringSumHelper &message);
void checkIfShouldAutoReset();

void loop()
{
    checkIfShouldAutoReset();

    if (m_test_mode_no_network_no_nfc) return;

    CheckForNfcTag();

    server.handleClient();

    CheckForNfcTag();

    ElegantOTA.loop();

    CheckForNfcTag();

    mqttClient.loop();

    CheckForNfcTag();
}

String getIncomingPayloadAsString(const uint8_t *payload, unsigned int payloadLength);
String getIncomingTopicAsString(const char *topic);

void mqttCallback(const char *topic, const byte *payload, unsigned int length)
{
    const String topicStr = getIncomingTopicAsString(topic);
    const String payloadStr = getIncomingPayloadAsString(payload, length);

    String newMessage = "New message on: '";
    newMessage += topicStr;
    newMessage += "' with payload of: '";
    newMessage += payloadStr;
    newMessage += "'";

    Log(newMessage);

    if (topicStr == SECRETS::MqttTopicGeneralStatus)
    {
        if (payloadStr == "info") {
            String incomingMessage = payloadStr;
            incomingMessage += " <= General status request seen | NFC board found on boot: ";

            if (m_nfcInitializedOnBoot)
            {
                incomingMessage += "True";
            }
            else
            {
                incomingMessage += "False";
            }

            incomingMessage += " | At IP: ";
            incomingMessage += String(ETH.localIP().toString());

            incomingMessage += " | Local epoch (seconds): ";
            incomingMessage += String(rtc.getLocalEpoch());

            mqttClient.publish(SECRETS::MqttTopicDeviceStatus, incomingMessage.c_str());
            Log(incomingMessage);
        }
    }
}

String decToHex(const byte decValue, const byte desiredStringLength)
{
    auto hexString = String(decValue, HEX);

    while (hexString.length() < desiredStringLength) hexString = "0" + hexString;

    return hexString;
}

void CheckForNfcTag()
{
    uint8_t uid[] = { 0, 0, 0, 0, 0, 0, 0 };	// Buffer to store the returned UID
    uint8_t uidLength;				            // Length of the UID (4 or 7 bytes depending on ISO14443A card type)

    const boolean success = m_nfc.readPassiveTargetID(PN532_MIFARE_ISO14443A, &uid[0], &uidLength);   // Wait for an ISO14443A type cards (Mifare, etc.).  When one is found 'uid' will be populated with the UID, and uidLength will indicate if the uid is 4 bytes (Mifare Classic) or 7 bytes (Mifare Ultralight)

    if (!success) return;

    // Otherwise:
    String UIDString = "";

    for (uint8_t i = 0; i < uidLength; i++)
    {
        UIDString += decToHex(uid[i], 2);

        if (i >= uidLength - 1) continue;

        // Otherwise:
        UIDString += ':';
    }

    UIDString.toUpperCase();

    Log("New tag scanned: " + UIDString);
    mqttClient.publish(SECRETS::MqttTopicTagScanned, UIDString.c_str());
}

void initializeNfcBoard()
{
    m_nfc.begin();

    const uint32_t versiondata = m_nfc.getFirmwareVersion();

    if (!versiondata)
    {
        Serial.println("Didn't find PN53x board");
    }
    else
    {
        Serial.println("Found chip PN5" + String((versiondata>>24) & 0xFF, HEX));
        Serial.println("Firmware ver: " + String((versiondata>>16) & 0xFF, DEC) + "." + String((versiondata>>8) & 0xFF, DEC));

        m_nfcInitializedOnBoot = true;

        m_nfc.setPassiveActivationRetries(0x01);        // Set the max number of retry attempts to read from a card, preventing us from waiting forever for a card, which is the default behaviour of the PN532
    }
}

void delayBootForSerialStart()
{
    int countDown = 5;

    while (countDown-- > 0)
    {
        Serial.print("Boot delay...");
        yield();
        delay(100);
    }
}

void serialPrintNetworkInformation()
{
    Serial.println();
    Serial.print("Version: ");
    Serial.println(m_versionMessage);
    Serial.println();

    // Print local IP address
    Serial.println("");
    Serial.println("Ethernet connected.");
    Serial.println("IP address: ");
    Serial.println(ETH.localIP());
}

void setupElegantOtaServer()
{
    server.on("/", []()
    {
        server.send(200, "text/plain", "Hi! This is PN532 NFC reader");
    });

    ElegantOTA.begin(&server);    // Start ElegantOTA
    server.begin();
}

void connectToMqtt()
{
    mqttClient.setServer(SECRETS::MqttBroker, SECRETS::MqttPort);
    mqttClient.setCallback(mqttCallback);

    while (!mqttClient.connected())
    {
        server.handleClient();
        ElegantOTA.loop();

        String client_id = "esp32-client-";
        client_id += String(ETH.macAddress());

        Serial.printf("The client %s connects to the MQTT broker\n", client_id.c_str());

        if (mqttClient.connect(client_id.c_str(), SECRETS::MqttUsername, SECRETS::MqttPassword))
        {
            Serial.println("MQTT broker connected");
        }
        else
        {
            Serial.print("failed with state ");
            Serial.print(mqttClient.state());

            delay(50);
        }
    }

    mqttClient.subscribe(SECRETS::MqttTopicGeneralStatus);
    // mqttClient.publish(SECRETS::MqttTopicGeneralStatus, subscribeMessage.c_str());

    mqttClient.subscribe(SECRETS::MqttTopicDeviceStatus);
    //mqttClient.subscribe(SECRETS::MqttTopicTagScanned);

    dumpLastCrashDataToMqtt();

    String helloMessage = "NFC reader ESP32 up! ";
    helloMessage += m_versionMessage;
    helloMessage += " @ ";
    helloMessage += String(ETH.localIP().toString());

    mqttClient.publish(SECRETS::MqttTopicGeneralStatus, helloMessage.c_str());
    mqttClient.publish(SECRETS::MqttTopicDeviceStatus, helloMessage.c_str());
}

String getIncomingPayloadAsString(const uint8_t *payload, unsigned int payloadLength)
{
    String payloadStr = "";

    // Convert payload to string
    for (int i = 0; i < payloadLength; i++)
    {
        payloadStr += static_cast<char>(payload[i]);
    }

    return payloadStr;
}

String getIncomingTopicAsString(const char *topic)
{
    String topicStr = "";

    // Convert topic to string
    for (int i = 0; i < strlen(topic); i++)
    {
        topicStr += topic[i];
    }

    return topicStr;
}

void dumpLastCrashDataToMqtt()
{
    // Last crash dump to MQTT
    backtrace_saver::re_restart_debug_t current_debug_info = backtrace_saver::debugGet();

    std::string crashDumpAddresses;

#if CONFIG_RESTART_DEBUG_STACK_DEPTH > 0
    for (int i = 0; i < CONFIG_RESTART_DEBUG_STACK_DEPTH; i++)
    {
        // Had to add .first here to get the first of the pair. Not sure how this was working before.
        // If addresses are not looking correct, then just try .second. No idea where the pair came from
        uint32_t backtraceAddress = current_debug_info.backtrace[i].first;

        crashDumpAddresses += String(backtraceAddress, HEX).c_str();

        crashDumpAddresses += " ";
    }
#endif

    crashDumpAddresses += String("PLEASE FIX THIS IN dumpLastCrashDataToMqtt() in main.cpp, may need .second on the backtrace address fetch if addresses do not look right").c_str();

    mqttClient.publish(SECRETS::MqttTopicDebug, " ");
    mqttClient.publish(SECRETS::MqttTopicDebug, "-----========== LAST CRASH DATA ==========-----");
    mqttClient.publish(SECRETS::MqttTopicDebug, crashDumpAddresses.c_str());
    mqttClient.publish(SECRETS::MqttTopicDebug, "-----========== END LAST CRASH DATA ==========-----");
    mqttClient.publish(SECRETS::MqttTopicDebug, " ");
}

void Log(const std::string &message)
{
    if (!m_debug_on) return;

    Serial.print("[LOG] ");
    Serial.println(message.c_str());

    const auto mqttLogMessage = String("[LOG] ") + String (message.c_str());
    mqttClient.publish(SECRETS::MqttTopicDebug, mqttLogMessage.c_str());
}

void Log(const StringSumHelper &message)
{
    if (!m_debug_on) return;

    Serial.print("[LOG] ");
    Serial.println(message.c_str());

    const auto mqttLogMessage = String("[LOG] ") + String (message.c_str());
    mqttClient.publish(SECRETS::MqttTopicDebug, mqttLogMessage.c_str());
}

void sendNetworkInfoToMqtt()
{
    String message = "Front Door NFC Reader Version: ";
    message += m_versionMessage;

    message += " - IP address: ";
    message += ETH.localIP().toString();

    mqttClient.publish(SECRETS::MqttTopicGeneralStatus, message.c_str());
    mqttClient.publish(SECRETS::MqttTopicDeviceStatus, message.c_str());
}

void checkIfShouldAutoReset()
{
    if (rtc.getLocalEpoch() <= 3000) return;    // An hour-ish

    Serial.println("Auto-restarting due to local epoch!");

    rtc.setTime(0);

    ESP.restart();
}

void warnIfTestModeEnabled()
{
    if (!m_test_mode_no_network_no_nfc) return;

    for (int i = 0; i < 100; i++)
        Serial.println("WARNING: m_test_mode_no_network_no_nfc IS ENABLED. DISABLE BEFORE UPLOADING OTA");
}
