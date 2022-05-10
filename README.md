# gameboy-emulator
Practicing C-Programming by developing a GameBoy Emulator.

I undertook this as a personal project purely for learning purposes, to gain a deeper understanding of C Programming, emulation and computer architecture in general. The emulator can play some games like Tetris.

# Build instructions

GCC tools and CMake is required to build.

## Linux

You need to have SDL2 installed to build the project. Install by using:
```bash
sudo apt install cmake
sudo apt install libsdl2-dev
sudo apt install libsdl2-ttf-dev
```
To build:

```bash
mkdir build
cd build
cmake ..
make
```
Run from the build directory using:
```bash
./gbemu/gbemu
```

## Windows

Windows dependancies are included.
Make is required to build, this can be installed in many ways such as GnuWin32.

To build (Powershell):

```bash
mkdir build
cd build
cmake .. -G "Unix Makefiles"
make
```
Run from the build directory using:
```bash
.\gbemu\gbemu.exe
```


Run by opening the .exe file.

## MacOS

Homebrew is required to install SDL2 and cmake. Homebrew insallation instructions can be found [here](https://brew.sh).

Install the following using the commands:
```bash
brew install sdl2
brew install sdl2_ttf
brew install cmake
```
To build from terminal:
```bash
mkdir build
cd build
cmake ..
make
```
Run from the build directory using:
```
./gbemu/gbemu 
```

# Project Status

- Passes all the Blaarg CPU Tests.
- Passes DMG Acid 2 PPU test.
- Plays **ROM only** GB games.
- Plays GB games that use the MBC1 mapper.
- Can display native file dialog using an open source library.

# A special thanks to:
- [LLD Youtube Channel](https://www.youtube.com/channel/UCRWXAQsN5S3FPDHY4Ttq1Xg)
- [javidx9 Youtube Channel](https://www.youtube.com/channel/UC-yuWVUplUJZvieEligKBkA)
- https://gbdev.io/pandocs/
- https://www.pastraiser.com/cpu/gameboy/gameboy_opcodes.html
- https://github.com/geaz/emu-gameboy/blob/master/docs/The%20Cycle-Accurate%20Game%20Boy%20Docs.pdf
- https://gekkio.fi/files/gb-docs/gbctr.pdf
- https://github.com/btzy/nativefiledialog-extended
