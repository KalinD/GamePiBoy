#include <stdio.h>
#include <fstream>
#include <ctime>
#include "pico/stdlib.h"
#include "pico/time.h"
#include "hardware/spi.h"
#include "GC9A01.hpp"
#include "GB.hpp"
#include "clock.hpp"

#define SPI_PORT spi0
#define PIN_MISO 16
#define PIN_CS   17
#define PIN_SCK  18
#define PIN_MOSI 19
#define PIN_RST  20
#define PIN_DC   16

int main()
{
    stdio_init_all();
    GC9A01 display(SPI_PORT, PIN_MISO, PIN_CS, PIN_SCK, PIN_MOSI, PIN_RST, PIN_DC);

    GB gameboy;

    display.Init();
    display.TearingEffectOff();

    while (true) {
        display.RainbowTest();
        sleep_ms(2000);
        display.CheckerboardTest();
        sleep_ms(2000);
    }
}
