#ifndef GB_PPU_GC9A01_HPP
#define GB_PPU_GC9A01_HPP

#include "GC9A01.hpp"
#include "ppu.hpp"

class GB_PPU_GC9A01 : public PPU, public GC9A01
{
private:
public:
    GB_PPU_GC9A01(std::shared_ptr<Memory> memory, spi_inst_t* spi_instance, uint8 miso_pin, uint8 cs_pin, uint8 sck_pin, uint8 mosi_pin, uint8 rst_pin, uint8 dc_pin) : PPU(memory), GC9A01(spi_instance, miso_pin, cs_pin, sck_pin, mosi_pin, rst_pin, dc_pin) {
        this->Init();
        this->TearingEffectOff();
    }
    ~GB_PPU_GC9A01() {}

    void writePixel(ePixelColor pixel) noexcept override;
    void writePixels(std::vector<ePixelColor> pixels) noexcept override;
};

#endif // GB_PPU_GC9A01_HPP
