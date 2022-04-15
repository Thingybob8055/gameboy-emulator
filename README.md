# gameboy-emulator
Practicing C-Programming by developing a GameBoy Emulator.

I undertook this as a personal project purely for learning purposes, to gain a deeper understanding of C Programming, emulation and computer architecture in general. The emulator can play some games like Tetris.

# Build instructions

GCC tools and CMake is required to build.

## Linux

You need to have SDL2 installed to build the project.

```shell
mkdir build
cd build
cmake ..
build
```
Run from the build directory using:
```
./gbemu/gbemu
```

## Windows

I use Visual Studio Code, and it's CMAKE extension is what I use to build it, as it automatically configures the project. A link to the extension: [CMAKE VSCode Extension](https://marketplace.visualstudio.com/items?itemName=ms-vscode.cmake-tools).

Run by opening the .exe file.

## MacOS

I don't have a MacOS machine so I don't know what do to.

# Project Status

- Passes all the Blaarg CPU Tests.
- Passes DMG Acid 2 PPU test.
- Plays **ROM only** GB games.
- Can display native file dialog using an open source library.

# A special thanks to:
- [LLD Youtube Channel](https://www.youtube.com/channel/UCRWXAQsN5S3FPDHY4Ttq1Xg)
- [javi9dx Youtube Channel](https://www.youtube.com/channel/UC-yuWVUplUJZvieEligKBkA)
- https://gbdev.io/pandocs/
- https://www.pastraiser.com/cpu/gameboy/gameboy_opcodes.html
- https://github.com/geaz/emu-gameboy/blob/master/docs/The%20Cycle-Accurate%20Game%20Boy%20Docs.pdf
- https://gekkio.fi/files/gb-docs/gbctr.pdf
- https://github.com/btzy/nativefiledialog-extended