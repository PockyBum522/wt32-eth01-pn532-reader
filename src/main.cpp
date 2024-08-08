#include <Arduino.h>
#include <ETH.h>
#include <External/Adafruit PN532/Adafruit_PN532.h>

String m_versionMessage = "v0.01";

WiFiClient ethernetClient;

#define PN532_MOSI 4
#define PN532_SS   14
#define PN532_MISO 36
#define PN532_SCK  32

Adafruit_PN532 m_nfc(PN532_SCK, PN532_MISO, PN532_MOSI, PN532_SS);

void initializeNfcBoard();

void setup()
{
    Serial.begin(115200);

    int countDown = 5;

    while (countDown-- > 0)
    {
        Serial.print("Boot delay...");
        yield();
        delay(100);
    }

    Serial.println("About to init SPI pins");

    initializeNfcBoard();
}

void CheckForNfcTag();

long successCount = 0;

void loop()
{
    CheckForNfcTag();

    Serial.print("loop: ");
    Serial.println(successCount++);
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

    if (success)
    {
        String UIDString = "UID=";

        for (uint8_t i = 0; i < uidLength; i++)
        {
            UIDString += decToHex(uid[i], 2);

            if (i < uidLength - 1)
            {
                UIDString += ':';
            }
        }

        UIDString.toUpperCase();

        Serial.print("New tag scanned: ");
        Serial.println(UIDString);
    }
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
    }

    m_nfc.setPassiveActivationRetries(0x01);        // Set the max number of retry attempts to read from a card, preventing us from waiting forever for a card, which is the default behaviour of the PN532
}