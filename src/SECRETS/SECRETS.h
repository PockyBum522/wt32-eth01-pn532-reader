#ifndef WT32_ETH01_PN532_READER_SECRETS_H
#define WT32_ETH01_PN532_READER_SECRETS_H

#include <Arduino.h>

class SECRETS
{
public:

    // MQTT Broker
    static const char* MqttBroker;
    static const char* MqttUsername;
    static const char* MqttPassword;
    static const int   MqttPort;

    // Device publish topics
    static const char* MqttTopicGeneralStatus;
    static const char* MqttTopicDeviceStatus;
    static const char* MqttTopicTagScanned;
    static const char* MqttTopicDebug;

};


#endif //WT32_ETH01_PN532_READER_SECRETS_H
