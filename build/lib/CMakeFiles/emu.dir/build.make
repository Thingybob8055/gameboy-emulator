# CMAKE generated file: DO NOT EDIT!
# Generated by "Unix Makefiles" Generator, CMake Version 3.16

# Delete rule output on recipe failure.
.DELETE_ON_ERROR:


#=============================================================================
# Special targets provided by cmake.

# Disable implicit rules so canonical targets will work.
.SUFFIXES:


# Remove some rules from gmake that .SUFFIXES does not remove.
SUFFIXES =

.SUFFIXES: .hpux_make_needs_suffix_list


# Suppress display of executed commands.
$(VERBOSE).SILENT:


# A target that is always out of date.
cmake_force:

.PHONY : cmake_force

#=============================================================================
# Set environment variables for the build.

# The shell in which to execute make rules.
SHELL = /bin/sh

# The CMake executable.
CMAKE_COMMAND = /usr/bin/cmake

# The command to remove a file.
RM = /usr/bin/cmake -E remove -f

# Escaping for special characters.
EQUALS = =

# The top-level source directory on which CMake was run.
CMAKE_SOURCE_DIR = /home/akshay/projects/gbemu/code

# The top-level build directory on which CMake was run.
CMAKE_BINARY_DIR = /home/akshay/projects/gbemu/code/build

# Include any dependencies generated for this target.
include lib/CMakeFiles/emu.dir/depend.make

# Include the progress variables for this target.
include lib/CMakeFiles/emu.dir/progress.make

# Include the compile flags for this target's objects.
include lib/CMakeFiles/emu.dir/flags.make

lib/CMakeFiles/emu.dir/bus.c.o: lib/CMakeFiles/emu.dir/flags.make
lib/CMakeFiles/emu.dir/bus.c.o: ../lib/bus.c
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/home/akshay/projects/gbemu/code/build/CMakeFiles --progress-num=$(CMAKE_PROGRESS_1) "Building C object lib/CMakeFiles/emu.dir/bus.c.o"
	cd /home/akshay/projects/gbemu/code/build/lib && /usr/bin/cc $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -o CMakeFiles/emu.dir/bus.c.o   -c /home/akshay/projects/gbemu/code/lib/bus.c

lib/CMakeFiles/emu.dir/bus.c.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing C source to CMakeFiles/emu.dir/bus.c.i"
	cd /home/akshay/projects/gbemu/code/build/lib && /usr/bin/cc $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -E /home/akshay/projects/gbemu/code/lib/bus.c > CMakeFiles/emu.dir/bus.c.i

lib/CMakeFiles/emu.dir/bus.c.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling C source to assembly CMakeFiles/emu.dir/bus.c.s"
	cd /home/akshay/projects/gbemu/code/build/lib && /usr/bin/cc $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -S /home/akshay/projects/gbemu/code/lib/bus.c -o CMakeFiles/emu.dir/bus.c.s

lib/CMakeFiles/emu.dir/cart.c.o: lib/CMakeFiles/emu.dir/flags.make
lib/CMakeFiles/emu.dir/cart.c.o: ../lib/cart.c
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/home/akshay/projects/gbemu/code/build/CMakeFiles --progress-num=$(CMAKE_PROGRESS_2) "Building C object lib/CMakeFiles/emu.dir/cart.c.o"
	cd /home/akshay/projects/gbemu/code/build/lib && /usr/bin/cc $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -o CMakeFiles/emu.dir/cart.c.o   -c /home/akshay/projects/gbemu/code/lib/cart.c

lib/CMakeFiles/emu.dir/cart.c.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing C source to CMakeFiles/emu.dir/cart.c.i"
	cd /home/akshay/projects/gbemu/code/build/lib && /usr/bin/cc $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -E /home/akshay/projects/gbemu/code/lib/cart.c > CMakeFiles/emu.dir/cart.c.i

lib/CMakeFiles/emu.dir/cart.c.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling C source to assembly CMakeFiles/emu.dir/cart.c.s"
	cd /home/akshay/projects/gbemu/code/build/lib && /usr/bin/cc $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -S /home/akshay/projects/gbemu/code/lib/cart.c -o CMakeFiles/emu.dir/cart.c.s

lib/CMakeFiles/emu.dir/cpu.c.o: lib/CMakeFiles/emu.dir/flags.make
lib/CMakeFiles/emu.dir/cpu.c.o: ../lib/cpu.c
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/home/akshay/projects/gbemu/code/build/CMakeFiles --progress-num=$(CMAKE_PROGRESS_3) "Building C object lib/CMakeFiles/emu.dir/cpu.c.o"
	cd /home/akshay/projects/gbemu/code/build/lib && /usr/bin/cc $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -o CMakeFiles/emu.dir/cpu.c.o   -c /home/akshay/projects/gbemu/code/lib/cpu.c

lib/CMakeFiles/emu.dir/cpu.c.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing C source to CMakeFiles/emu.dir/cpu.c.i"
	cd /home/akshay/projects/gbemu/code/build/lib && /usr/bin/cc $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -E /home/akshay/projects/gbemu/code/lib/cpu.c > CMakeFiles/emu.dir/cpu.c.i

lib/CMakeFiles/emu.dir/cpu.c.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling C source to assembly CMakeFiles/emu.dir/cpu.c.s"
	cd /home/akshay/projects/gbemu/code/build/lib && /usr/bin/cc $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -S /home/akshay/projects/gbemu/code/lib/cpu.c -o CMakeFiles/emu.dir/cpu.c.s

lib/CMakeFiles/emu.dir/cpu_fetch.c.o: lib/CMakeFiles/emu.dir/flags.make
lib/CMakeFiles/emu.dir/cpu_fetch.c.o: ../lib/cpu_fetch.c
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/home/akshay/projects/gbemu/code/build/CMakeFiles --progress-num=$(CMAKE_PROGRESS_4) "Building C object lib/CMakeFiles/emu.dir/cpu_fetch.c.o"
	cd /home/akshay/projects/gbemu/code/build/lib && /usr/bin/cc $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -o CMakeFiles/emu.dir/cpu_fetch.c.o   -c /home/akshay/projects/gbemu/code/lib/cpu_fetch.c

lib/CMakeFiles/emu.dir/cpu_fetch.c.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing C source to CMakeFiles/emu.dir/cpu_fetch.c.i"
	cd /home/akshay/projects/gbemu/code/build/lib && /usr/bin/cc $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -E /home/akshay/projects/gbemu/code/lib/cpu_fetch.c > CMakeFiles/emu.dir/cpu_fetch.c.i

lib/CMakeFiles/emu.dir/cpu_fetch.c.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling C source to assembly CMakeFiles/emu.dir/cpu_fetch.c.s"
	cd /home/akshay/projects/gbemu/code/build/lib && /usr/bin/cc $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -S /home/akshay/projects/gbemu/code/lib/cpu_fetch.c -o CMakeFiles/emu.dir/cpu_fetch.c.s

lib/CMakeFiles/emu.dir/cpu_proc.c.o: lib/CMakeFiles/emu.dir/flags.make
lib/CMakeFiles/emu.dir/cpu_proc.c.o: ../lib/cpu_proc.c
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/home/akshay/projects/gbemu/code/build/CMakeFiles --progress-num=$(CMAKE_PROGRESS_5) "Building C object lib/CMakeFiles/emu.dir/cpu_proc.c.o"
	cd /home/akshay/projects/gbemu/code/build/lib && /usr/bin/cc $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -o CMakeFiles/emu.dir/cpu_proc.c.o   -c /home/akshay/projects/gbemu/code/lib/cpu_proc.c

lib/CMakeFiles/emu.dir/cpu_proc.c.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing C source to CMakeFiles/emu.dir/cpu_proc.c.i"
	cd /home/akshay/projects/gbemu/code/build/lib && /usr/bin/cc $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -E /home/akshay/projects/gbemu/code/lib/cpu_proc.c > CMakeFiles/emu.dir/cpu_proc.c.i

lib/CMakeFiles/emu.dir/cpu_proc.c.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling C source to assembly CMakeFiles/emu.dir/cpu_proc.c.s"
	cd /home/akshay/projects/gbemu/code/build/lib && /usr/bin/cc $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -S /home/akshay/projects/gbemu/code/lib/cpu_proc.c -o CMakeFiles/emu.dir/cpu_proc.c.s

lib/CMakeFiles/emu.dir/cpu_util.c.o: lib/CMakeFiles/emu.dir/flags.make
lib/CMakeFiles/emu.dir/cpu_util.c.o: ../lib/cpu_util.c
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/home/akshay/projects/gbemu/code/build/CMakeFiles --progress-num=$(CMAKE_PROGRESS_6) "Building C object lib/CMakeFiles/emu.dir/cpu_util.c.o"
	cd /home/akshay/projects/gbemu/code/build/lib && /usr/bin/cc $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -o CMakeFiles/emu.dir/cpu_util.c.o   -c /home/akshay/projects/gbemu/code/lib/cpu_util.c

lib/CMakeFiles/emu.dir/cpu_util.c.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing C source to CMakeFiles/emu.dir/cpu_util.c.i"
	cd /home/akshay/projects/gbemu/code/build/lib && /usr/bin/cc $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -E /home/akshay/projects/gbemu/code/lib/cpu_util.c > CMakeFiles/emu.dir/cpu_util.c.i

lib/CMakeFiles/emu.dir/cpu_util.c.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling C source to assembly CMakeFiles/emu.dir/cpu_util.c.s"
	cd /home/akshay/projects/gbemu/code/build/lib && /usr/bin/cc $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -S /home/akshay/projects/gbemu/code/lib/cpu_util.c -o CMakeFiles/emu.dir/cpu_util.c.s

lib/CMakeFiles/emu.dir/dbg.c.o: lib/CMakeFiles/emu.dir/flags.make
lib/CMakeFiles/emu.dir/dbg.c.o: ../lib/dbg.c
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/home/akshay/projects/gbemu/code/build/CMakeFiles --progress-num=$(CMAKE_PROGRESS_7) "Building C object lib/CMakeFiles/emu.dir/dbg.c.o"
	cd /home/akshay/projects/gbemu/code/build/lib && /usr/bin/cc $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -o CMakeFiles/emu.dir/dbg.c.o   -c /home/akshay/projects/gbemu/code/lib/dbg.c

lib/CMakeFiles/emu.dir/dbg.c.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing C source to CMakeFiles/emu.dir/dbg.c.i"
	cd /home/akshay/projects/gbemu/code/build/lib && /usr/bin/cc $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -E /home/akshay/projects/gbemu/code/lib/dbg.c > CMakeFiles/emu.dir/dbg.c.i

lib/CMakeFiles/emu.dir/dbg.c.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling C source to assembly CMakeFiles/emu.dir/dbg.c.s"
	cd /home/akshay/projects/gbemu/code/build/lib && /usr/bin/cc $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -S /home/akshay/projects/gbemu/code/lib/dbg.c -o CMakeFiles/emu.dir/dbg.c.s

lib/CMakeFiles/emu.dir/dma.c.o: lib/CMakeFiles/emu.dir/flags.make
lib/CMakeFiles/emu.dir/dma.c.o: ../lib/dma.c
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/home/akshay/projects/gbemu/code/build/CMakeFiles --progress-num=$(CMAKE_PROGRESS_8) "Building C object lib/CMakeFiles/emu.dir/dma.c.o"
	cd /home/akshay/projects/gbemu/code/build/lib && /usr/bin/cc $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -o CMakeFiles/emu.dir/dma.c.o   -c /home/akshay/projects/gbemu/code/lib/dma.c

lib/CMakeFiles/emu.dir/dma.c.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing C source to CMakeFiles/emu.dir/dma.c.i"
	cd /home/akshay/projects/gbemu/code/build/lib && /usr/bin/cc $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -E /home/akshay/projects/gbemu/code/lib/dma.c > CMakeFiles/emu.dir/dma.c.i

lib/CMakeFiles/emu.dir/dma.c.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling C source to assembly CMakeFiles/emu.dir/dma.c.s"
	cd /home/akshay/projects/gbemu/code/build/lib && /usr/bin/cc $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -S /home/akshay/projects/gbemu/code/lib/dma.c -o CMakeFiles/emu.dir/dma.c.s

lib/CMakeFiles/emu.dir/emu.c.o: lib/CMakeFiles/emu.dir/flags.make
lib/CMakeFiles/emu.dir/emu.c.o: ../lib/emu.c
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/home/akshay/projects/gbemu/code/build/CMakeFiles --progress-num=$(CMAKE_PROGRESS_9) "Building C object lib/CMakeFiles/emu.dir/emu.c.o"
	cd /home/akshay/projects/gbemu/code/build/lib && /usr/bin/cc $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -o CMakeFiles/emu.dir/emu.c.o   -c /home/akshay/projects/gbemu/code/lib/emu.c

lib/CMakeFiles/emu.dir/emu.c.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing C source to CMakeFiles/emu.dir/emu.c.i"
	cd /home/akshay/projects/gbemu/code/build/lib && /usr/bin/cc $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -E /home/akshay/projects/gbemu/code/lib/emu.c > CMakeFiles/emu.dir/emu.c.i

lib/CMakeFiles/emu.dir/emu.c.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling C source to assembly CMakeFiles/emu.dir/emu.c.s"
	cd /home/akshay/projects/gbemu/code/build/lib && /usr/bin/cc $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -S /home/akshay/projects/gbemu/code/lib/emu.c -o CMakeFiles/emu.dir/emu.c.s

lib/CMakeFiles/emu.dir/instructions.c.o: lib/CMakeFiles/emu.dir/flags.make
lib/CMakeFiles/emu.dir/instructions.c.o: ../lib/instructions.c
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/home/akshay/projects/gbemu/code/build/CMakeFiles --progress-num=$(CMAKE_PROGRESS_10) "Building C object lib/CMakeFiles/emu.dir/instructions.c.o"
	cd /home/akshay/projects/gbemu/code/build/lib && /usr/bin/cc $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -o CMakeFiles/emu.dir/instructions.c.o   -c /home/akshay/projects/gbemu/code/lib/instructions.c

lib/CMakeFiles/emu.dir/instructions.c.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing C source to CMakeFiles/emu.dir/instructions.c.i"
	cd /home/akshay/projects/gbemu/code/build/lib && /usr/bin/cc $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -E /home/akshay/projects/gbemu/code/lib/instructions.c > CMakeFiles/emu.dir/instructions.c.i

lib/CMakeFiles/emu.dir/instructions.c.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling C source to assembly CMakeFiles/emu.dir/instructions.c.s"
	cd /home/akshay/projects/gbemu/code/build/lib && /usr/bin/cc $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -S /home/akshay/projects/gbemu/code/lib/instructions.c -o CMakeFiles/emu.dir/instructions.c.s

lib/CMakeFiles/emu.dir/interrupts.c.o: lib/CMakeFiles/emu.dir/flags.make
lib/CMakeFiles/emu.dir/interrupts.c.o: ../lib/interrupts.c
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/home/akshay/projects/gbemu/code/build/CMakeFiles --progress-num=$(CMAKE_PROGRESS_11) "Building C object lib/CMakeFiles/emu.dir/interrupts.c.o"
	cd /home/akshay/projects/gbemu/code/build/lib && /usr/bin/cc $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -o CMakeFiles/emu.dir/interrupts.c.o   -c /home/akshay/projects/gbemu/code/lib/interrupts.c

lib/CMakeFiles/emu.dir/interrupts.c.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing C source to CMakeFiles/emu.dir/interrupts.c.i"
	cd /home/akshay/projects/gbemu/code/build/lib && /usr/bin/cc $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -E /home/akshay/projects/gbemu/code/lib/interrupts.c > CMakeFiles/emu.dir/interrupts.c.i

lib/CMakeFiles/emu.dir/interrupts.c.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling C source to assembly CMakeFiles/emu.dir/interrupts.c.s"
	cd /home/akshay/projects/gbemu/code/build/lib && /usr/bin/cc $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -S /home/akshay/projects/gbemu/code/lib/interrupts.c -o CMakeFiles/emu.dir/interrupts.c.s

lib/CMakeFiles/emu.dir/io.c.o: lib/CMakeFiles/emu.dir/flags.make
lib/CMakeFiles/emu.dir/io.c.o: ../lib/io.c
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/home/akshay/projects/gbemu/code/build/CMakeFiles --progress-num=$(CMAKE_PROGRESS_12) "Building C object lib/CMakeFiles/emu.dir/io.c.o"
	cd /home/akshay/projects/gbemu/code/build/lib && /usr/bin/cc $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -o CMakeFiles/emu.dir/io.c.o   -c /home/akshay/projects/gbemu/code/lib/io.c

lib/CMakeFiles/emu.dir/io.c.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing C source to CMakeFiles/emu.dir/io.c.i"
	cd /home/akshay/projects/gbemu/code/build/lib && /usr/bin/cc $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -E /home/akshay/projects/gbemu/code/lib/io.c > CMakeFiles/emu.dir/io.c.i

lib/CMakeFiles/emu.dir/io.c.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling C source to assembly CMakeFiles/emu.dir/io.c.s"
	cd /home/akshay/projects/gbemu/code/build/lib && /usr/bin/cc $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -S /home/akshay/projects/gbemu/code/lib/io.c -o CMakeFiles/emu.dir/io.c.s

lib/CMakeFiles/emu.dir/lcd.c.o: lib/CMakeFiles/emu.dir/flags.make
lib/CMakeFiles/emu.dir/lcd.c.o: ../lib/lcd.c
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/home/akshay/projects/gbemu/code/build/CMakeFiles --progress-num=$(CMAKE_PROGRESS_13) "Building C object lib/CMakeFiles/emu.dir/lcd.c.o"
	cd /home/akshay/projects/gbemu/code/build/lib && /usr/bin/cc $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -o CMakeFiles/emu.dir/lcd.c.o   -c /home/akshay/projects/gbemu/code/lib/lcd.c

lib/CMakeFiles/emu.dir/lcd.c.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing C source to CMakeFiles/emu.dir/lcd.c.i"
	cd /home/akshay/projects/gbemu/code/build/lib && /usr/bin/cc $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -E /home/akshay/projects/gbemu/code/lib/lcd.c > CMakeFiles/emu.dir/lcd.c.i

lib/CMakeFiles/emu.dir/lcd.c.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling C source to assembly CMakeFiles/emu.dir/lcd.c.s"
	cd /home/akshay/projects/gbemu/code/build/lib && /usr/bin/cc $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -S /home/akshay/projects/gbemu/code/lib/lcd.c -o CMakeFiles/emu.dir/lcd.c.s

lib/CMakeFiles/emu.dir/ppu.c.o: lib/CMakeFiles/emu.dir/flags.make
lib/CMakeFiles/emu.dir/ppu.c.o: ../lib/ppu.c
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/home/akshay/projects/gbemu/code/build/CMakeFiles --progress-num=$(CMAKE_PROGRESS_14) "Building C object lib/CMakeFiles/emu.dir/ppu.c.o"
	cd /home/akshay/projects/gbemu/code/build/lib && /usr/bin/cc $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -o CMakeFiles/emu.dir/ppu.c.o   -c /home/akshay/projects/gbemu/code/lib/ppu.c

lib/CMakeFiles/emu.dir/ppu.c.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing C source to CMakeFiles/emu.dir/ppu.c.i"
	cd /home/akshay/projects/gbemu/code/build/lib && /usr/bin/cc $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -E /home/akshay/projects/gbemu/code/lib/ppu.c > CMakeFiles/emu.dir/ppu.c.i

lib/CMakeFiles/emu.dir/ppu.c.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling C source to assembly CMakeFiles/emu.dir/ppu.c.s"
	cd /home/akshay/projects/gbemu/code/build/lib && /usr/bin/cc $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -S /home/akshay/projects/gbemu/code/lib/ppu.c -o CMakeFiles/emu.dir/ppu.c.s

lib/CMakeFiles/emu.dir/ppu_pipeline.c.o: lib/CMakeFiles/emu.dir/flags.make
lib/CMakeFiles/emu.dir/ppu_pipeline.c.o: ../lib/ppu_pipeline.c
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/home/akshay/projects/gbemu/code/build/CMakeFiles --progress-num=$(CMAKE_PROGRESS_15) "Building C object lib/CMakeFiles/emu.dir/ppu_pipeline.c.o"
	cd /home/akshay/projects/gbemu/code/build/lib && /usr/bin/cc $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -o CMakeFiles/emu.dir/ppu_pipeline.c.o   -c /home/akshay/projects/gbemu/code/lib/ppu_pipeline.c

lib/CMakeFiles/emu.dir/ppu_pipeline.c.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing C source to CMakeFiles/emu.dir/ppu_pipeline.c.i"
	cd /home/akshay/projects/gbemu/code/build/lib && /usr/bin/cc $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -E /home/akshay/projects/gbemu/code/lib/ppu_pipeline.c > CMakeFiles/emu.dir/ppu_pipeline.c.i

lib/CMakeFiles/emu.dir/ppu_pipeline.c.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling C source to assembly CMakeFiles/emu.dir/ppu_pipeline.c.s"
	cd /home/akshay/projects/gbemu/code/build/lib && /usr/bin/cc $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -S /home/akshay/projects/gbemu/code/lib/ppu_pipeline.c -o CMakeFiles/emu.dir/ppu_pipeline.c.s

lib/CMakeFiles/emu.dir/ppu_sm.c.o: lib/CMakeFiles/emu.dir/flags.make
lib/CMakeFiles/emu.dir/ppu_sm.c.o: ../lib/ppu_sm.c
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/home/akshay/projects/gbemu/code/build/CMakeFiles --progress-num=$(CMAKE_PROGRESS_16) "Building C object lib/CMakeFiles/emu.dir/ppu_sm.c.o"
	cd /home/akshay/projects/gbemu/code/build/lib && /usr/bin/cc $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -o CMakeFiles/emu.dir/ppu_sm.c.o   -c /home/akshay/projects/gbemu/code/lib/ppu_sm.c

lib/CMakeFiles/emu.dir/ppu_sm.c.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing C source to CMakeFiles/emu.dir/ppu_sm.c.i"
	cd /home/akshay/projects/gbemu/code/build/lib && /usr/bin/cc $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -E /home/akshay/projects/gbemu/code/lib/ppu_sm.c > CMakeFiles/emu.dir/ppu_sm.c.i

lib/CMakeFiles/emu.dir/ppu_sm.c.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling C source to assembly CMakeFiles/emu.dir/ppu_sm.c.s"
	cd /home/akshay/projects/gbemu/code/build/lib && /usr/bin/cc $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -S /home/akshay/projects/gbemu/code/lib/ppu_sm.c -o CMakeFiles/emu.dir/ppu_sm.c.s

lib/CMakeFiles/emu.dir/ram.c.o: lib/CMakeFiles/emu.dir/flags.make
lib/CMakeFiles/emu.dir/ram.c.o: ../lib/ram.c
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/home/akshay/projects/gbemu/code/build/CMakeFiles --progress-num=$(CMAKE_PROGRESS_17) "Building C object lib/CMakeFiles/emu.dir/ram.c.o"
	cd /home/akshay/projects/gbemu/code/build/lib && /usr/bin/cc $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -o CMakeFiles/emu.dir/ram.c.o   -c /home/akshay/projects/gbemu/code/lib/ram.c

lib/CMakeFiles/emu.dir/ram.c.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing C source to CMakeFiles/emu.dir/ram.c.i"
	cd /home/akshay/projects/gbemu/code/build/lib && /usr/bin/cc $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -E /home/akshay/projects/gbemu/code/lib/ram.c > CMakeFiles/emu.dir/ram.c.i

lib/CMakeFiles/emu.dir/ram.c.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling C source to assembly CMakeFiles/emu.dir/ram.c.s"
	cd /home/akshay/projects/gbemu/code/build/lib && /usr/bin/cc $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -S /home/akshay/projects/gbemu/code/lib/ram.c -o CMakeFiles/emu.dir/ram.c.s

lib/CMakeFiles/emu.dir/stack.c.o: lib/CMakeFiles/emu.dir/flags.make
lib/CMakeFiles/emu.dir/stack.c.o: ../lib/stack.c
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/home/akshay/projects/gbemu/code/build/CMakeFiles --progress-num=$(CMAKE_PROGRESS_18) "Building C object lib/CMakeFiles/emu.dir/stack.c.o"
	cd /home/akshay/projects/gbemu/code/build/lib && /usr/bin/cc $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -o CMakeFiles/emu.dir/stack.c.o   -c /home/akshay/projects/gbemu/code/lib/stack.c

lib/CMakeFiles/emu.dir/stack.c.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing C source to CMakeFiles/emu.dir/stack.c.i"
	cd /home/akshay/projects/gbemu/code/build/lib && /usr/bin/cc $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -E /home/akshay/projects/gbemu/code/lib/stack.c > CMakeFiles/emu.dir/stack.c.i

lib/CMakeFiles/emu.dir/stack.c.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling C source to assembly CMakeFiles/emu.dir/stack.c.s"
	cd /home/akshay/projects/gbemu/code/build/lib && /usr/bin/cc $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -S /home/akshay/projects/gbemu/code/lib/stack.c -o CMakeFiles/emu.dir/stack.c.s

lib/CMakeFiles/emu.dir/timer.c.o: lib/CMakeFiles/emu.dir/flags.make
lib/CMakeFiles/emu.dir/timer.c.o: ../lib/timer.c
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/home/akshay/projects/gbemu/code/build/CMakeFiles --progress-num=$(CMAKE_PROGRESS_19) "Building C object lib/CMakeFiles/emu.dir/timer.c.o"
	cd /home/akshay/projects/gbemu/code/build/lib && /usr/bin/cc $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -o CMakeFiles/emu.dir/timer.c.o   -c /home/akshay/projects/gbemu/code/lib/timer.c

lib/CMakeFiles/emu.dir/timer.c.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing C source to CMakeFiles/emu.dir/timer.c.i"
	cd /home/akshay/projects/gbemu/code/build/lib && /usr/bin/cc $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -E /home/akshay/projects/gbemu/code/lib/timer.c > CMakeFiles/emu.dir/timer.c.i

lib/CMakeFiles/emu.dir/timer.c.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling C source to assembly CMakeFiles/emu.dir/timer.c.s"
	cd /home/akshay/projects/gbemu/code/build/lib && /usr/bin/cc $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -S /home/akshay/projects/gbemu/code/lib/timer.c -o CMakeFiles/emu.dir/timer.c.s

lib/CMakeFiles/emu.dir/ui.c.o: lib/CMakeFiles/emu.dir/flags.make
lib/CMakeFiles/emu.dir/ui.c.o: ../lib/ui.c
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/home/akshay/projects/gbemu/code/build/CMakeFiles --progress-num=$(CMAKE_PROGRESS_20) "Building C object lib/CMakeFiles/emu.dir/ui.c.o"
	cd /home/akshay/projects/gbemu/code/build/lib && /usr/bin/cc $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -o CMakeFiles/emu.dir/ui.c.o   -c /home/akshay/projects/gbemu/code/lib/ui.c

lib/CMakeFiles/emu.dir/ui.c.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing C source to CMakeFiles/emu.dir/ui.c.i"
	cd /home/akshay/projects/gbemu/code/build/lib && /usr/bin/cc $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -E /home/akshay/projects/gbemu/code/lib/ui.c > CMakeFiles/emu.dir/ui.c.i

lib/CMakeFiles/emu.dir/ui.c.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling C source to assembly CMakeFiles/emu.dir/ui.c.s"
	cd /home/akshay/projects/gbemu/code/build/lib && /usr/bin/cc $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -S /home/akshay/projects/gbemu/code/lib/ui.c -o CMakeFiles/emu.dir/ui.c.s

# Object files for target emu
emu_OBJECTS = \
"CMakeFiles/emu.dir/bus.c.o" \
"CMakeFiles/emu.dir/cart.c.o" \
"CMakeFiles/emu.dir/cpu.c.o" \
"CMakeFiles/emu.dir/cpu_fetch.c.o" \
"CMakeFiles/emu.dir/cpu_proc.c.o" \
"CMakeFiles/emu.dir/cpu_util.c.o" \
"CMakeFiles/emu.dir/dbg.c.o" \
"CMakeFiles/emu.dir/dma.c.o" \
"CMakeFiles/emu.dir/emu.c.o" \
"CMakeFiles/emu.dir/instructions.c.o" \
"CMakeFiles/emu.dir/interrupts.c.o" \
"CMakeFiles/emu.dir/io.c.o" \
"CMakeFiles/emu.dir/lcd.c.o" \
"CMakeFiles/emu.dir/ppu.c.o" \
"CMakeFiles/emu.dir/ppu_pipeline.c.o" \
"CMakeFiles/emu.dir/ppu_sm.c.o" \
"CMakeFiles/emu.dir/ram.c.o" \
"CMakeFiles/emu.dir/stack.c.o" \
"CMakeFiles/emu.dir/timer.c.o" \
"CMakeFiles/emu.dir/ui.c.o"

# External object files for target emu
emu_EXTERNAL_OBJECTS =

lib/libemu.a: lib/CMakeFiles/emu.dir/bus.c.o
lib/libemu.a: lib/CMakeFiles/emu.dir/cart.c.o
lib/libemu.a: lib/CMakeFiles/emu.dir/cpu.c.o
lib/libemu.a: lib/CMakeFiles/emu.dir/cpu_fetch.c.o
lib/libemu.a: lib/CMakeFiles/emu.dir/cpu_proc.c.o
lib/libemu.a: lib/CMakeFiles/emu.dir/cpu_util.c.o
lib/libemu.a: lib/CMakeFiles/emu.dir/dbg.c.o
lib/libemu.a: lib/CMakeFiles/emu.dir/dma.c.o
lib/libemu.a: lib/CMakeFiles/emu.dir/emu.c.o
lib/libemu.a: lib/CMakeFiles/emu.dir/instructions.c.o
lib/libemu.a: lib/CMakeFiles/emu.dir/interrupts.c.o
lib/libemu.a: lib/CMakeFiles/emu.dir/io.c.o
lib/libemu.a: lib/CMakeFiles/emu.dir/lcd.c.o
lib/libemu.a: lib/CMakeFiles/emu.dir/ppu.c.o
lib/libemu.a: lib/CMakeFiles/emu.dir/ppu_pipeline.c.o
lib/libemu.a: lib/CMakeFiles/emu.dir/ppu_sm.c.o
lib/libemu.a: lib/CMakeFiles/emu.dir/ram.c.o
lib/libemu.a: lib/CMakeFiles/emu.dir/stack.c.o
lib/libemu.a: lib/CMakeFiles/emu.dir/timer.c.o
lib/libemu.a: lib/CMakeFiles/emu.dir/ui.c.o
lib/libemu.a: lib/CMakeFiles/emu.dir/build.make
lib/libemu.a: lib/CMakeFiles/emu.dir/link.txt
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --bold --progress-dir=/home/akshay/projects/gbemu/code/build/CMakeFiles --progress-num=$(CMAKE_PROGRESS_21) "Linking C static library libemu.a"
	cd /home/akshay/projects/gbemu/code/build/lib && $(CMAKE_COMMAND) -P CMakeFiles/emu.dir/cmake_clean_target.cmake
	cd /home/akshay/projects/gbemu/code/build/lib && $(CMAKE_COMMAND) -E cmake_link_script CMakeFiles/emu.dir/link.txt --verbose=$(VERBOSE)

# Rule to build all files generated by this target.
lib/CMakeFiles/emu.dir/build: lib/libemu.a

.PHONY : lib/CMakeFiles/emu.dir/build

lib/CMakeFiles/emu.dir/clean:
	cd /home/akshay/projects/gbemu/code/build/lib && $(CMAKE_COMMAND) -P CMakeFiles/emu.dir/cmake_clean.cmake
.PHONY : lib/CMakeFiles/emu.dir/clean

lib/CMakeFiles/emu.dir/depend:
	cd /home/akshay/projects/gbemu/code/build && $(CMAKE_COMMAND) -E cmake_depends "Unix Makefiles" /home/akshay/projects/gbemu/code /home/akshay/projects/gbemu/code/lib /home/akshay/projects/gbemu/code/build /home/akshay/projects/gbemu/code/build/lib /home/akshay/projects/gbemu/code/build/lib/CMakeFiles/emu.dir/DependInfo.cmake --color=$(COLOR)
.PHONY : lib/CMakeFiles/emu.dir/depend

