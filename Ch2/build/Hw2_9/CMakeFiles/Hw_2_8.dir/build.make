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
CMAKE_SOURCE_DIR = C:/Users/rong_he/Desktop/CPractice/Ch2

# The top-level build directory on which CMake was run.
CMAKE_BINARY_DIR = C:/Users/rong_he/Desktop/CPractice/Ch2/build

# Include any dependencies generated for this target.
include Hw2_9/CMakeFiles/Hw_2_8.dir/depend.make
# Include any dependencies generated by the compiler for this target.
include Hw2_9/CMakeFiles/Hw_2_8.dir/compiler_depend.make

# Include the progress variables for this target.
include Hw2_9/CMakeFiles/Hw_2_8.dir/progress.make

# Include the compile flags for this target's objects.
include Hw2_9/CMakeFiles/Hw_2_8.dir/flags.make

Hw2_9/CMakeFiles/Hw_2_8.dir/main.obj: Hw2_9/CMakeFiles/Hw_2_8.dir/flags.make
Hw2_9/CMakeFiles/Hw_2_8.dir/main.obj: ../Hw2_9/main.c
Hw2_9/CMakeFiles/Hw_2_8.dir/main.obj: Hw2_9/CMakeFiles/Hw_2_8.dir/compiler_depend.ts
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=C:/Users/rong_he/Desktop/CPractice/Ch2/build/CMakeFiles --progress-num=$(CMAKE_PROGRESS_1) "Building C object Hw2_9/CMakeFiles/Hw_2_8.dir/main.obj"
	cd C:/Users/rong_he/Desktop/CPractice/Ch2/build/Hw2_9 && C:/MinGW/bin/gcc.exe $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -MD -MT Hw2_9/CMakeFiles/Hw_2_8.dir/main.obj -MF CMakeFiles/Hw_2_8.dir/main.obj.d -o CMakeFiles/Hw_2_8.dir/main.obj -c C:/Users/rong_he/Desktop/CPractice/Ch2/Hw2_9/main.c

Hw2_9/CMakeFiles/Hw_2_8.dir/main.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing C source to CMakeFiles/Hw_2_8.dir/main.i"
	cd C:/Users/rong_he/Desktop/CPractice/Ch2/build/Hw2_9 && C:/MinGW/bin/gcc.exe $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -E C:/Users/rong_he/Desktop/CPractice/Ch2/Hw2_9/main.c > CMakeFiles/Hw_2_8.dir/main.i

Hw2_9/CMakeFiles/Hw_2_8.dir/main.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling C source to assembly CMakeFiles/Hw_2_8.dir/main.s"
	cd C:/Users/rong_he/Desktop/CPractice/Ch2/build/Hw2_9 && C:/MinGW/bin/gcc.exe $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -S C:/Users/rong_he/Desktop/CPractice/Ch2/Hw2_9/main.c -o CMakeFiles/Hw_2_8.dir/main.s

# Object files for target Hw_2_8
Hw_2_8_OBJECTS = \
"CMakeFiles/Hw_2_8.dir/main.obj"

# External object files for target Hw_2_8
Hw_2_8_EXTERNAL_OBJECTS =

Hw2_9/Hw_2_8.exe: Hw2_9/CMakeFiles/Hw_2_8.dir/main.obj
Hw2_9/Hw_2_8.exe: Hw2_9/CMakeFiles/Hw_2_8.dir/build.make
Hw2_9/Hw_2_8.exe: Hw2_9/CMakeFiles/Hw_2_8.dir/linklibs.rsp
Hw2_9/Hw_2_8.exe: Hw2_9/CMakeFiles/Hw_2_8.dir/objects1.rsp
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --bold --progress-dir=C:/Users/rong_he/Desktop/CPractice/Ch2/build/CMakeFiles --progress-num=$(CMAKE_PROGRESS_2) "Linking C executable Hw_2_8.exe"
	cd C:/Users/rong_he/Desktop/CPractice/Ch2/build/Hw2_9 && "C:/Program Files/CMake/bin/cmake.exe" -E rm -f CMakeFiles/Hw_2_8.dir/objects.a
	cd C:/Users/rong_he/Desktop/CPractice/Ch2/build/Hw2_9 && C:/MinGW/bin/ar.exe qc CMakeFiles/Hw_2_8.dir/objects.a @CMakeFiles/Hw_2_8.dir/objects1.rsp
	cd C:/Users/rong_he/Desktop/CPractice/Ch2/build/Hw2_9 && C:/MinGW/bin/gcc.exe -g -Wl,--whole-archive CMakeFiles/Hw_2_8.dir/objects.a -Wl,--no-whole-archive -o Hw_2_8.exe -Wl,--out-implib,libHw_2_8.dll.a -Wl,--major-image-version,0,--minor-image-version,0 @CMakeFiles/Hw_2_8.dir/linklibs.rsp

# Rule to build all files generated by this target.
Hw2_9/CMakeFiles/Hw_2_8.dir/build: Hw2_9/Hw_2_8.exe
.PHONY : Hw2_9/CMakeFiles/Hw_2_8.dir/build

Hw2_9/CMakeFiles/Hw_2_8.dir/clean:
	cd C:/Users/rong_he/Desktop/CPractice/Ch2/build/Hw2_9 && $(CMAKE_COMMAND) -P CMakeFiles/Hw_2_8.dir/cmake_clean.cmake
.PHONY : Hw2_9/CMakeFiles/Hw_2_8.dir/clean

Hw2_9/CMakeFiles/Hw_2_8.dir/depend:
	$(CMAKE_COMMAND) -E cmake_depends "Unix Makefiles" C:/Users/rong_he/Desktop/CPractice/Ch2 C:/Users/rong_he/Desktop/CPractice/Ch2/Hw2_9 C:/Users/rong_he/Desktop/CPractice/Ch2/build C:/Users/rong_he/Desktop/CPractice/Ch2/build/Hw2_9 C:/Users/rong_he/Desktop/CPractice/Ch2/build/Hw2_9/CMakeFiles/Hw_2_8.dir/DependInfo.cmake --color=$(COLOR)
.PHONY : Hw2_9/CMakeFiles/Hw_2_8.dir/depend

