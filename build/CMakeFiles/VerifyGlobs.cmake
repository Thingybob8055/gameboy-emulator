# CMAKE generated file: DO NOT EDIT!
# Generated by CMake Version 3.16

# headers at lib/CMakeLists.txt:5 (file)
file(GLOB NEW_GLOB LIST_DIRECTORIES true "/home/akshay/projects/gbemu/code/include/*.h")
set(OLD_GLOB
  "/home/akshay/projects/gbemu/code/include/bus.h"
  "/home/akshay/projects/gbemu/code/include/cart.h"
  "/home/akshay/projects/gbemu/code/include/common.h"
  "/home/akshay/projects/gbemu/code/include/cpu.h"
  "/home/akshay/projects/gbemu/code/include/dbg.h"
  "/home/akshay/projects/gbemu/code/include/emu.h"
  "/home/akshay/projects/gbemu/code/include/instructions.h"
  "/home/akshay/projects/gbemu/code/include/interrupts.h"
  "/home/akshay/projects/gbemu/code/include/io.h"
  "/home/akshay/projects/gbemu/code/include/ppu.h"
  "/home/akshay/projects/gbemu/code/include/ram.h"
  "/home/akshay/projects/gbemu/code/include/stack.h"
  "/home/akshay/projects/gbemu/code/include/timer.h"
  "/home/akshay/projects/gbemu/code/include/ui.h"
  )
if(NOT "${NEW_GLOB}" STREQUAL "${OLD_GLOB}")
  message("-- GLOB mismatch!")
  file(TOUCH_NOCREATE "/home/akshay/projects/gbemu/code/build/CMakeFiles/cmake.verify_globs")
endif()

# sources at lib/CMakeLists.txt:3 (file)
file(GLOB NEW_GLOB LIST_DIRECTORIES true "/home/akshay/projects/gbemu/code/lib/*.c")
set(OLD_GLOB
  "/home/akshay/projects/gbemu/code/lib/bus.c"
  "/home/akshay/projects/gbemu/code/lib/cart.c"
  "/home/akshay/projects/gbemu/code/lib/cpu.c"
  "/home/akshay/projects/gbemu/code/lib/cpu_fetch.c"
  "/home/akshay/projects/gbemu/code/lib/cpu_proc.c"
  "/home/akshay/projects/gbemu/code/lib/cpu_util.c"
  "/home/akshay/projects/gbemu/code/lib/dbg.c"
  "/home/akshay/projects/gbemu/code/lib/emu.c"
  "/home/akshay/projects/gbemu/code/lib/instructions.c"
  "/home/akshay/projects/gbemu/code/lib/interrupts.c"
  "/home/akshay/projects/gbemu/code/lib/io.c"
  "/home/akshay/projects/gbemu/code/lib/ppu.c"
  "/home/akshay/projects/gbemu/code/lib/ram.c"
  "/home/akshay/projects/gbemu/code/lib/stack.c"
  "/home/akshay/projects/gbemu/code/lib/timer.c"
  "/home/akshay/projects/gbemu/code/lib/ui.c"
  )
if(NOT "${NEW_GLOB}" STREQUAL "${OLD_GLOB}")
  message("-- GLOB mismatch!")
  file(TOUCH_NOCREATE "/home/akshay/projects/gbemu/code/build/CMakeFiles/cmake.verify_globs")
endif()
