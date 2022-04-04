#include <bus.h>
#include <cart.h>
#include <ram.h>
#include <cpu.h>

// Memory Map from GB Pandocs:
// 0x0000 - 0x3FFF : ROM Bank 0 (16KiB), From cartridge, usually a fixed bank
// 0x4000 - 0x7FFF : ROM Bank 1 - Switchable, (16KiB), From cartridge, switchable bank via mapper (if any)
// 0x8000 - 0x97FF : CHR RAM
// 0x9800 - 0x9BFF : BG Map 1
// 0x9C00 - 0x9FFF : BG Map 2
// 0xA000 - 0xBFFF : Cartridge RAM
// 0xC000 - 0xCFFF : RAM Bank 0
// 0xD000 - 0xDFFF : RAM Bank 1-7 - switchable - Color only
// 0xE000 - 0xFDFF : Reserved - Echo RAM
// 0xFE00 - 0xFE9F : Object Attribute Memory
// 0xFEA0 - 0xFEFF : Reserved - Unusable
// 0xFF00 - 0xFF7F : I/O Registers
// 0xFF80 - 0xFFFE : Zero Page (HRAM)

//cart header is contained in the first ROM bank.

//cart_read and write methods to be added to the cart codes. 

//so far, only implemented ROM
u8 bus_read(u16 address){
    if(address < 0x8000){
        //ROM data
        return cart_read(address); // return the cart read at that address
    }
    else if (address < 0xA000) { //char/map data
        //TODO: Done alongside PPU...
        printf("[!]UNSUPPORTED bus_read(%04X)\n", address);
        NO_IMPL
    }
    else if (address < 0xC000) {
        //Cartridge RAM
        return cart_read(address);
    }
    else if (address < 0xE000) {
        //Working RAM (WRAM)
        return wram_read(address);
    }
    else if (address < 0xFE00) {
        //reserved echo RAM, this is not needed.
        return 0;
    }
    else if (address < 0xFEA0) {
        //Object Attribute Memory
        //TODO: this will be started later as its PPU dependant...
        printf("[!]UNSUPPORTED bus_read(%04X)\n", address);
        NO_IMPL
    }
    else if (address < 0xFF00) {
        //reserved and unusable
        return 0;
    }
    else if (address < 0xFF80) {
        //IO registers
        //TODO: implement controllers etc
        printf("[!]UNSUPPORTED bus_read(%04X)\n", address);
        NO_IMPL
    }
    else if (address == 0xFFFF) {
        //CPU ENABLE REGISTER (CPU Interrupt enable regiister)
        // printf("[!]UNSUPPORTED bus_read(%04X)\n", address);
        // NO_IMPL
        return cpu_get_ie_register();
    }
    
    return hram_read(address);
    //NO_IMPL

}

//May seem strange to write to ROM, but it gives special instructions that get run when trying to doing so
void bus_write(u16 address, u8 value){
    if(address < 0x8000){
        cart_write(address, value);
    }
    else if (address < 0xA000) {
        // Char/Map data
        //TODO:Done with PPU
        printf("[!]UNSUPPORTED bus_write(%04X)\n", address);
        NO_IMPL
    }
    else if (address < 0xC000) {
        //EXT RAM or CART RAM
        cart_write(address, value);
    }
    else if (address < 0xE000) {
        //WRAM region
        wram_write(address, value);
    }
    else if (address < 0xFE00) {
        //echo ram (reserved)
    }
    else if (address < 0xFEA0) {
        //OAM
        //TODO:
        printf("[!]UNSUPPORTED bus_write(%04X)\n", address);
        NO_IMPL
    }
    else if (address < 0xFF00) {
        //reserved and unusable
    }
    else if (address < 0xFF80) {
        //IO Registers
        //TODO:
        printf("[!]UNSUPPORTED bus_write(%04X)\n", address);
        //NO_IMPL
    }
    else if (address == 0xFFFF) {
        //CPU ENABLE REGISTER (CPU Interrupt enable regiister)
        // printf("[!]UNSUPPORTED bus_write(%04X)\n", address);
        // NO_IMPL
        cpu_set_ie_register(value);
    }
    else {
        hram_write(address, value);
    }
    //printf("[!]UNSUPPORTED bus_write(%04X)\n", address);
    //NO_IMPL
}

u16 bus_read16(u16 address) {
    u16 lo = bus_read(address);
    u16 hi = bus_read(address + 1);

    return lo | (hi << 8);
}

void bus_write16(u16 address, u16 value) {
    bus_write(address + 1, (value >> 8) & 0xFF); //write top byte
    bus_write(address, value & 0xFF);
}
