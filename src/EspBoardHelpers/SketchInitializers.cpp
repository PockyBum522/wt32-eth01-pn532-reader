#include <Arduino.h>
#include "SketchInitializers.h"

void SketchInitializers::InitializeSpiPins()
{
    constexpr const static uint8_t spi_host = 0;

    constexpr const static int8_t pin_cs = 14;

    constexpr const static int8_t pin_sclk = 32;

    constexpr const static int8_t pin_mosi = 4;

    constexpr const static int8_t pin_miso = 36;
}
