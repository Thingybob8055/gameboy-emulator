#include <bus.h>
#include <cart.h>

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
// 0xFF80 - 0xFFFE : Zero Page

//cart header is contained in the first ROM bank.

//cart_read and write methods to be added to the cart codes. 

//so far, only implemented ROM
u8 bus_read(u16 address){
    if(address < 0x8000){
        //ROM data
        return cart_read(address); // return the cart read at that address
    }

    NO_IMPL

}

//May seem strange to write to ROM, but it gives special instructions that get run when trying to doing so
void bus_write(u16 address, u8 value){
    if(address < 0x8000){
        return cart_write(address, value);
    }

    NO_IMPL

}
