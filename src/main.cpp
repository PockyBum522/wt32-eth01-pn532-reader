#include <Arduino.h>
#include <ElegantOTA.h>
#include <ETH.h>
#include <PubSubClient.h>
#define PN532DEBUG
#include <External/Adafruit PN532/Adafruit_PN532.h>
#include <iostream>
#include <backtrace_saver.hpp>

#include "EspBoardHelpers/SketchInitializers.h"
#include "SECRETS/SECRETS.h"

// TO USE CRASH ADDRESSES REPORTED ON STARTUP, RUN:
// C:\Users\David\.platformio\packages\toolchain-xtensa-esp-elf\bin\xtensa-esp32-elf-addr2line.exe -pfiaC -e D:\repos\wt32-eth01-pn532-reader\.pio\build\wt32-eth01\firmware.elf -a

// EXAMPLE ADDRESSES: C:\Users\David\.platformio\packages\toolchain-xtensa-esp-elf\bin\xtensa-esp32-elf-addr2line.exe -pfiaC -e D:\repos\wt32-eth01-pn532-reader\.pio\build\wt32-eth01\firmware.elf -a 400d41b3 400e854f 4008308d 40084b88 40082c35 4008de91 40082ca6 400d3aa5 400d4132 400dfbed 0 0 0 0 0 0 0 0 0 0

// Replace the addresses on the end with the crash data, obviously.

bool m_foundNfcBoardOnBoot;

WebServer server(80);

// Variable to store the HTTP request
String header;

String m_versionMessage = "v0.01";

WiFiClient ethernetClient;
PubSubClient mqttClient(ethernetClient);

#define PN532_MOSI 4
#define PN532_SS   14
#define PN532_MISO 36
#define PN532_SCK  32

Adafruit_PN532 m_nfc(PN532_SCK, PN532_MISO, PN532_MOSI, PN532_SS);

void mqttCallback(const char *topic, const byte *payload, unsigned int length);
String decToHex(byte decValue, byte desiredStringLength);
void dumpLastCrashDataToMqtt();
void initializeNfcBoard();

void setup()
{
    backtrace_saver::init();

    Serial.begin(115200);

    int countDown = 5;

    while (countDown-- > 0)
    {
        Serial.print("Boot delay...");
        yield();
        delay(100);
    }

    Serial.println("About to init SPI pins");

    //SketchInitializers::InitializeSpiPins();

//    ETH.begin(ETH_PHY_ADDR, ETH_PHY_POWER);
//
//    // Print local IP address and start web server
//    Serial.println("");
//    Serial.println("Ethernet connected.");
//    Serial.println("IP address: ");
//    Serial.println(ETH.localIP());
//
//    Serial.println();
//    Serial.println();
//    Serial.println(m_versionMessage);
//    Serial.println();
//    Serial.println();

//    server.on("/", []()
//    {
//        server.send(200, "text/plain", "Hi! This is PN532 NFC reader");
//    });
//
//    ElegantOTA.begin(&server);    // Start ElegantOTA
//    server.begin();
//
//    mqttClient.setServer(SECRETS::MqttBroker, SECRETS::MqttPort);
//    mqttClient.setCallback(mqttCallback);
//
//    while (!mqttClient.connected())
//    {
//        server.handleClient();
//        ElegantOTA.loop();
//
//        String client_id = "esp32-client-";
//        client_id += String(ETH.macAddress());
//
//        //Serial.printf("The client %s connects to the public MQTT broker\n", client_id.c_str());
//
//        if (mqttClient.connect(client_id.c_str(), SECRETS::MqttUsername, SECRETS::MqttPassword))
//        {
//            Serial.println("Public EMQX MQTT broker connected");
//        }
//        else
//        {
//            Serial.print("failed with state ");
//            Serial.print(mqttClient.state());
//
//            delay(50);
//        }
//    }
//
//    String subscribeMessage = "Subscribing to: ";
//    mqttClient.subscribe(SECRETS::MqttTopicGeneralStatus);
//    mqttClient.publish(SECRETS::MqttTopicGeneralStatus, subscribeMessage.c_str());
//
//    mqttClient.subscribe(SECRETS::MqttTopicDeviceStatus);
//    mqttClient.subscribe(SECRETS::MqttTopicTagScanned);
//
//    dumpLastCrashDataToMqtt();

    initializeNfcBoard();

//    String helloMessage = "NFC reader ESP32 up! ";
//    helloMessage += m_versionMessage;
//    helloMessage += " @ ";
//    helloMessage += String(ETH.localIP());
//
//    mqttClient.publish(SECRETS::MqttTopicGeneralStatus, helloMessage.c_str());
//    mqttClient.publish(SECRETS::MqttTopicDeviceStatus, helloMessage.c_str());
//
//    mqttClient.publish(SECRETS::MqttTopicDeviceStatus, "ABOUT TO NFC INIT:" );
}

String getIncomingPayloadAsString(const uint8_t *payload, unsigned int payloadLength);
String getIncomingTopicAsString(const char *topic);
void CheckForNfcTag();

void loop()
{
//    if (m_foundNfcBoardOnBoot)

    CheckForNfcTag();

    Serial.print("Found NFC board on boot? ");

    if (m_foundNfcBoardOnBoot)
    {
        Serial.println("True");
    }
    else
    {
        Serial.println("False");

        while(true){
            delay(100);
            yield();
        }
    }

    // server.handleClient();
    //
    // CheckForNfcTag();
    //
    // ElegantOTA.loop();
    //
    // CheckForNfcTag();

    //mqttClient.loop();

    // mqttClient.publish(SECRETS::MqttTopicDeviceStatus, "Loop took millis: ");
    // mqttClient.publish(SECRETS::MqttTopicDeviceStatus, String(stopMillis).c_str());
}


void mqttCallback(const char *topic, const byte *payload, unsigned int length)
{
    // Serial.print("Message arrived in topic: ");
    // Serial.println(topic);
    //
    // Serial.print("Message:");
    //
    // String topicStr = getIncomingTopicAsString(topic);
    // String payloadStr = getIncomingPayloadAsString(payload, length);
    //
    // String newMessage = "New message on: '";
    // newMessage += topicStr;
    // newMessage += "' with payload of: '";
    // newMessage += payloadStr;
    // newMessage += "'";

    //mqttClient.publish(SECRETS::MqttTopicDeviceStatus,  newMessage.c_str());

    // if (topicStr == SECRETS::MqttTopicGeneralStatus)
    // {
    //     String incomingMessage = payloadStr;
    //     incomingMessage += " <= General status request seen";
    //
    //     mqttClient.publish(SECRETS::MqttTopicGeneralStatus,  incomingMessage.c_str());
    // }
    //
    // if (topicStr == SECRETS::MqttTopicDeviceStatus)
    // {
    //     String incomingMessage = payloadStr;
    //     incomingMessage += " <= Device status request seen";
    //
    //     mqttClient.publish(SECRETS::MqttTopicDeviceStatus,  incomingMessage.c_str());
    // }
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

String decToHex(byte decValue, byte desiredStringLength)
{
    String hexString = String(decValue, HEX);

    while (hexString.length() < desiredStringLength) hexString = "0" + hexString;

    return hexString;
}

void CheckForNfcTag()
{
    uint8_t uid[] = { 0, 0, 0, 0, 0, 0, 0 };	// Buffer to store the returned UID
    uint8_t uidLength;				// Length of the UID (4 or 7 bytes depending on ISO14443A card type)

    // Wait for an ISO14443A type cards (Mifare, etc.).  When one is found
    // 'uid' will be populated with the UID, and uidLength will indicate
    // if the uid is 4 bytes (Mifare Classic) or 7 bytes (Mifare Ultralight)

    boolean success = m_nfc.readPassiveTargetID(PN532_MIFARE_ISO14443A, &uid[0], &uidLength, 2);

    if (success)
    {
        String UIDString = "UID=";

        // for (uint8_t i = 0; i < uidLength; i++)
        // {
        //     UIDString += decToHex(uid[i], 2);
        //
        //     if (i < uidLength - 1)
        //     {
        //         UIDString += ':';
        //     }
        // }
        //
        // UIDString.toUpperCase();

        Serial.print("New tag scanned: ");
        Serial.println(UIDString);

        //mqttClient.publish(SECRETS::MqttTopicTagScanned, UIDString.c_str());
    }
}

void dumpLastCrashDataToMqtt()
{
    // Last crash dump to MQTT
    backtrace_saver::re_restart_debug_t current_debug_info = backtrace_saver::debugGet();

    std::string crashDumpAddresses;

    #if CONFIG_RESTART_DEBUG_STACK_DEPTH > 0
        for (int i = 0; i < CONFIG_RESTART_DEBUG_STACK_DEPTH; i++)
        {
            crashDumpAddresses += String(current_debug_info.backtrace[i], HEX).c_str();
            crashDumpAddresses += " ";
        }
    #endif

    mqttClient.publish(SECRETS::MqttTopicGeneralStatus, " ");
    mqttClient.publish(SECRETS::MqttTopicGeneralStatus, "-----========== LAST CRASH DATA ==========-----");
    mqttClient.publish(SECRETS::MqttTopicGeneralStatus, crashDumpAddresses.c_str());
    mqttClient.publish(SECRETS::MqttTopicGeneralStatus, "-----========== END LAST CRASH DATA ==========-----");
    mqttClient.publish(SECRETS::MqttTopicGeneralStatus, " ");
}

void initializeNfcBoard()
{
    m_nfc.begin();

    uint32_t versiondata = m_nfc.getFirmwareVersion();

    if (!versiondata)
    {
        Serial.println("Didn't find PN53x board");
        mqttClient.publish(SECRETS::MqttTopicDeviceStatus, "Didn't find PN53x board");
    }
    else
    {
        m_foundNfcBoardOnBoot = true;

        Serial.println("Found chip PN5" + String((versiondata>>24) & 0xFF, HEX));
        Serial.println("Firmware ver: " + String((versiondata>>16) & 0xFF, DEC) + "." + String((versiondata>>8) & 0xFF, DEC));

        mqttClient.publish(SECRETS::MqttTopicDeviceStatus, "Found chip PN5xx" );
    }

    // Set the max number of retry attempts to read from a card, preventing us from waiting forever for a card, which is the default behaviour of the PN532
    m_nfc.setPassiveActivationRetries(0x01);
}