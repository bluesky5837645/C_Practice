# CMAKE generated file: DO NOT EDIT!
# Generated by "Unix Makefiles" Generator, CMake Version 3.23

# Delete rule output on recipe failure.
.DELETE_ON_ERROR:

#=============================================================================
# Special targets provided by cmake.

# Disable implicit rules so canonical targets will work.
.SUFFIXES:

# Disable VCS-based implicit rules.
% : %,v

# Disable VCS-based implicit rules.
% : RCS/%

# Disable VCS-based implicit rules.
% : RCS/%,v

# Disable VCS-based implicit rules.
% : SCCS/s.%

# Disable VCS-based implicit rules.
% : s.%

.SUFFIXES: .hpux_make_needs_suffix_list

# Command-line flag to silence nested $(MAKE).
$(VERBOSE)MAKESILENT = -s

#Suppress display of executed commands.
$(VERBOSE).SILENT:

# A target that is always out of date.
cmake_force:
.PHONY : cmake_force

#=============================================================================
# Set environment variables for the build.

# The shell in which to execute make rules.
SHELL = /bin/sh

# The CMake executable.
CMAKE_COMMAND = "C:/Program Files/CMake/bin/cmake.exe"

# The command to remove a file.
RM = "C:/Program Files/CMake/bin/cmake.exe" -E rm -f

# Escaping for special characters.
EQUALS = =

# The top-level source directory on which CMake was run.
CMAKE_SOURCE_DIR = C:/Users/rong_he/Desktop/CPractice/Ch1

# The top-level build directory on which CMake was run.
CMAKE_BINARY_DIR = C:/Users/rong_he/Desktop/CPractice/Ch1/build

# Include any dependencies generated for this target.
include Hw1_16/CMakeFiles/Hw1_17.dir/depend.make
# Include any dependencies generated by the compiler for this target.
include Hw1_16/CMakeFiles/Hw1_17.dir/compiler_depend.make

# Include the progress variables for this target.
include Hw1_16/CMakeFiles/Hw1_17.dir/progress.make

# Include the compile flags for this target's objects.
include Hw1_16/CMakeFiles/Hw1_17.dir/flags.make

Hw1_16/CMakeFiles/Hw1_17.dir/main.obj: Hw1_16/CMakeFiles/Hw1_17.dir/flags.make
Hw1_16/CMakeFiles/Hw1_17.dir/main.obj: ../Hw1_16/main.c
Hw1_16/CMakeFiles/Hw1_17.dir/main.obj: Hw1_16/CMakeFiles/Hw1_17.dir/compiler_depend.ts
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=C:/Users/rong_he/Desktop/CPractice/Ch1/build/CMakeFiles --progress-num=$(CMAKE_PROGRESS_1) "Building C object Hw1_16/CMakeFiles/Hw1_17.dir/main.obj"
	cd C:/Users/rong_he/Desktop/CPractice/Ch1/build/Hw1_16 && C:/MinGW/bin/gcc.exe $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -MD -MT Hw1_16/CMakeFiles/Hw1_17.dir/main.obj -MF CMakeFiles/Hw1_17.dir/main.obj.d -o CMakeFiles/Hw1_17.dir/main.obj -c C:/Users/rong_he/Desktop/CPractice/Ch1/Hw1_16/main.c

Hw1_16/CMakeFiles/Hw1_17.dir/main.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing C source to CMakeFiles/Hw1_17.dir/main.i"
	cd C:/Users/rong_he/Desktop/CPractice/Ch1/build/Hw1_16 && C:/MinGW/bin/gcc.exe $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -E C:/Users/rong_he/Desktop/CPractice/Ch1/Hw1_16/main.c > CMakeFiles/Hw1_17.dir/main.i

Hw1_16/CMakeFiles/Hw1_17.dir/main.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling C source to assembly CMakeFiles/Hw1_17.dir/main.s"
	cd C:/Users/rong_he/Desktop/CPractice/Ch1/build/Hw1_16 && C:/MinGW/bin/gcc.exe $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -S C:/Users/rong_he/Desktop/CPractice/Ch1/Hw1_16/main.c -o CMakeFiles/Hw1_17.dir/main.s

# Object files for target Hw1_17
Hw1_17_OBJECTS = \
"CMakeFiles/Hw1_17.dir/main.obj"

# External object files for target Hw1_17
Hw1_17_EXTERNAL_OBJECTS =

Hw1_16/Hw1_17.exe: Hw1_16/CMakeFiles/Hw1_17.dir/main.obj
Hw1_16/Hw1_17.exe: Hw1_16/CMakeFiles/Hw1_17.dir/build.make
Hw1_16/Hw1_17.exe: Hw1_16/CMakeFiles/Hw1_17.dir/linklibs.rsp
Hw1_16/Hw1_17.exe: Hw1_16/CMakeFiles/Hw1_17.dir/objects1.rsp
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --bold --progress-dir=C:/Users/rong_he/Desktop/CPractice/Ch1/build/CMakeFiles --progress-num=$(CMAKE_PROGRESS_2) "Linking C executable Hw1_17.exe"
	cd C:/Users/rong_he/Desktop/CPractice/Ch1/build/Hw1_16 && "C:/Program Files/CMake/bin/cmake.exe" -E rm -f CMakeFiles/Hw1_17.dir/objects.a
	cd C:/Users/rong_he/Desktop/CPractice/Ch1/build/Hw1_16 && C:/MinGW/bin/ar.exe qc CMakeFiles/Hw1_17.dir/objects.a @CMakeFiles/Hw1_17.dir/objects1.rsp
	cd C:/Users/rong_he/Desktop/CPractice/Ch1/build/Hw1_16 && C:/MinGW/bin/gcc.exe -g -Wl,--whole-archive CMakeFiles/Hw1_17.dir/objects.a -Wl,--no-whole-archive -o Hw1_17.exe -Wl,--out-implib,libHw1_17.dll.a -Wl,--major-image-version,0,--minor-image-version,0 @CMakeFiles/Hw1_17.dir/linklibs.rsp

# Rule to build all files generated by this target.
Hw1_16/CMakeFiles/Hw1_17.dir/build: Hw1_16/Hw1_17.exe
.PHONY : Hw1_16/CMakeFiles/Hw1_17.dir/build

Hw1_16/CMakeFiles/Hw1_17.dir/clean:
	cd C:/Users/rong_he/Desktop/CPractice/Ch1/build/Hw1_16 && $(CMAKE_COMMAND) -P CMakeFiles/Hw1_17.dir/cmake_clean.cmake
.PHONY : Hw1_16/CMakeFiles/Hw1_17.dir/clean

Hw1_16/CMakeFiles/Hw1_17.dir/depend:
	$(CMAKE_COMMAND) -E cmake_depends "Unix Makefiles" C:/Users/rong_he/Desktop/CPractice/Ch1 C:/Users/rong_he/Desktop/CPractice/Ch1/Hw1_16 C:/Users/rong_he/Desktop/CPractice/Ch1/build C:/Users/rong_he/Desktop/CPractice/Ch1/build/Hw1_16 C:/Users/rong_he/Desktop/CPractice/Ch1/build/Hw1_16/CMakeFiles/Hw1_17.dir/DependInfo.cmake --color=$(COLOR)
.PHONY : Hw1_16/CMakeFiles/Hw1_17.dir/depend

