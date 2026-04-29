// #ifdef BUILD
#include "ppu.hpp"
#include "GC9A01.hpp"
// #else
// #include "./GameBoyEmulator/includes/ppu.hpp"
// #endif


class PPUImpl : PPU
{
private:
    std::unique_ptr<GC9A01> display;
public:
    PPUImpl(std::unique_ptr<GC9A01> dispplay, std::shared_ptr<Memory> memory) : PPU(memory) {
        this->display = std::move(display);
    }
    uint16 run() noexcept override;
};


uint16 PPUImpl::run() noexcept {
    
}
