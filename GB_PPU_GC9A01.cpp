#include "GB_PPU_GC9A01.hpp"
#include <stdio.h>

void GB_PPU_GC9A01::writePixels(std::vector<ePixelColor> pixels) noexcept {
    uint8 image[pixels.size() * 3];
    for(uint8 i = 0U; i < pixels.size(); ++i) {
        uint8 r = 0U, g = 0U, b = 0U;
        switch (pixels[i])
        {
        case White:
            r = 255U;
            g = 255U;
            b = 255U;
            break;
        case LightGray:
            r = 170U;
            g = 170U;
            b = 170U;
            break;
        case DarkGray:
            r = 85U;
            g = 85U;
            b = 85U;
            break;
        case Black:
            r = 0U;
            g = 0U;
            b = 0U;
            break;
        
        default:
            break;
        }
        image[i * 3U] = r;
        image[i * 3U + 1U] = g;
        image[i * 3U + 2U] = b;
    }
    // At most 1 row will be filled that's why it is 1px high
    this->FillImage(image, this->getScanlineX() + 40U, this->getScanlineY() + 44U, pixels.size(), 1U);
    this->setScanlineX(this->getScanlineX() + pixels.size());
}

void GB_PPU_GC9A01::writePixel(ePixelColor pixel) noexcept {
    uint8 r = 0U, g = 0U, b = 0U;
    switch (pixel)
    {
    case White:
        r = 255U;
        g = 255U;
        b = 255U;
        break;
    case LightGray:
        r = 170U;
        g = 170U;
        b = 170U;
        break;
    case DarkGray:
        r = 85U;
        g = 85U;
        b = 85U;
        break;
    case Black:
        r = 0U;
        g = 0U;
        b = 0U;
        break;
    
    default:
        break;
    }
    this->PutPixel(r, g, b, this->getScanlineX() + 40U, this->getScanlineY() + 44U);
    this->incrementScanlineX();
}
