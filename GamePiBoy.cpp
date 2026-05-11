// Standard Libraries
#include <stdio.h>
#include <fstream>
#include <ctime>

// Raspberry Pi Pico specific libraries
#include "pico/stdlib.h"
#include "pico/time.h"
#include "hardware/spi.h"

// Other dependencies
#include "GC9A01.hpp"
#include "GB.hpp"
#include "GB_PPU_GC9A01.hpp"
#include "clock.hpp"
// #include "Tetris.hpp"

#define SPI_PORT spi0
#define PIN_MISO 16
#define PIN_CS   17
#define PIN_SCK  18
#define PIN_MOSI 19
#define PIN_RST  20
#define PIN_DC   16

int main() {
    stdio_init_all();
    
    std::shared_ptr<Memory> memory = std::make_shared<Memory>();
    std::unique_ptr<GB_PPU_GC9A01> ppu = std::make_unique<GB_PPU_GC9A01>(memory, SPI_PORT, PIN_MISO, PIN_CS, PIN_SCK, PIN_MOSI, PIN_RST, PIN_DC);
    std::unique_ptr<GB> gameboy = std::make_unique<GB>(memory, std::move(ppu));
    
    // uint32 index = 0U;
    // for (uint8 byte : Tetris) {
    //     gameboy->addByte(byte, index);
    //     ++index;
    // }
    while (true) {
        uint8 cycles = gameboy->run();
    }
}
