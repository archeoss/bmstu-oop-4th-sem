# CMAKE generated file: DO NOT EDIT!
# Generated by "Unix Makefiles" Generator, CMake Version 3.22

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
CMAKE_COMMAND = /usr/bin/cmake

# The command to remove a file.
RM = /usr/bin/cmake -E rm -f

# Escaping for special characters.
EQUALS = =

# The top-level source directory on which CMake was run.
CMAKE_SOURCE_DIR = /home/crypto_samurai/github-archeos/bmstu-oop-4th-sem/lab_02

# The top-level build directory on which CMake was run.
CMAKE_BINARY_DIR = /home/crypto_samurai/github-archeos/bmstu-oop-4th-sem/lab_02/build

# Include any dependencies generated for this target.
include CMakeFiles/lab_02.dir/depend.make
# Include any dependencies generated by the compiler for this target.
include CMakeFiles/lab_02.dir/compiler_depend.make

# Include the progress variables for this target.
include CMakeFiles/lab_02.dir/progress.make

# Include the compile flags for this target's objects.
include CMakeFiles/lab_02.dir/flags.make

CMakeFiles/lab_02.dir/src/main.cpp.o: CMakeFiles/lab_02.dir/flags.make
CMakeFiles/lab_02.dir/src/main.cpp.o: ../src/main.cpp
CMakeFiles/lab_02.dir/src/main.cpp.o: CMakeFiles/lab_02.dir/compiler_depend.ts
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/home/crypto_samurai/github-archeos/bmstu-oop-4th-sem/lab_02/build/CMakeFiles --progress-num=$(CMAKE_PROGRESS_1) "Building CXX object CMakeFiles/lab_02.dir/src/main.cpp.o"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -MD -MT CMakeFiles/lab_02.dir/src/main.cpp.o -MF CMakeFiles/lab_02.dir/src/main.cpp.o.d -o CMakeFiles/lab_02.dir/src/main.cpp.o -c /home/crypto_samurai/github-archeos/bmstu-oop-4th-sem/lab_02/src/main.cpp

CMakeFiles/lab_02.dir/src/main.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/lab_02.dir/src/main.cpp.i"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /home/crypto_samurai/github-archeos/bmstu-oop-4th-sem/lab_02/src/main.cpp > CMakeFiles/lab_02.dir/src/main.cpp.i

CMakeFiles/lab_02.dir/src/main.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/lab_02.dir/src/main.cpp.s"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /home/crypto_samurai/github-archeos/bmstu-oop-4th-sem/lab_02/src/main.cpp -o CMakeFiles/lab_02.dir/src/main.cpp.s

CMakeFiles/lab_02.dir/src/set/container.cpp.o: CMakeFiles/lab_02.dir/flags.make
CMakeFiles/lab_02.dir/src/set/container.cpp.o: ../src/set/container.cpp
CMakeFiles/lab_02.dir/src/set/container.cpp.o: CMakeFiles/lab_02.dir/compiler_depend.ts
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/home/crypto_samurai/github-archeos/bmstu-oop-4th-sem/lab_02/build/CMakeFiles --progress-num=$(CMAKE_PROGRESS_2) "Building CXX object CMakeFiles/lab_02.dir/src/set/container.cpp.o"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -MD -MT CMakeFiles/lab_02.dir/src/set/container.cpp.o -MF CMakeFiles/lab_02.dir/src/set/container.cpp.o.d -o CMakeFiles/lab_02.dir/src/set/container.cpp.o -c /home/crypto_samurai/github-archeos/bmstu-oop-4th-sem/lab_02/src/set/container.cpp

CMakeFiles/lab_02.dir/src/set/container.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/lab_02.dir/src/set/container.cpp.i"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /home/crypto_samurai/github-archeos/bmstu-oop-4th-sem/lab_02/src/set/container.cpp > CMakeFiles/lab_02.dir/src/set/container.cpp.i

CMakeFiles/lab_02.dir/src/set/container.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/lab_02.dir/src/set/container.cpp.s"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /home/crypto_samurai/github-archeos/bmstu-oop-4th-sem/lab_02/src/set/container.cpp -o CMakeFiles/lab_02.dir/src/set/container.cpp.s

# Object files for target lab_02
lab_02_OBJECTS = \
"CMakeFiles/lab_02.dir/src/main.cpp.o" \
"CMakeFiles/lab_02.dir/src/set/container.cpp.o"

# External object files for target lab_02
lab_02_EXTERNAL_OBJECTS =

lab_02: CMakeFiles/lab_02.dir/src/main.cpp.o
lab_02: CMakeFiles/lab_02.dir/src/set/container.cpp.o
lab_02: CMakeFiles/lab_02.dir/build.make
lab_02: CMakeFiles/lab_02.dir/link.txt
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --bold --progress-dir=/home/crypto_samurai/github-archeos/bmstu-oop-4th-sem/lab_02/build/CMakeFiles --progress-num=$(CMAKE_PROGRESS_3) "Linking CXX executable lab_02"
	$(CMAKE_COMMAND) -E cmake_link_script CMakeFiles/lab_02.dir/link.txt --verbose=$(VERBOSE)

# Rule to build all files generated by this target.
CMakeFiles/lab_02.dir/build: lab_02
.PHONY : CMakeFiles/lab_02.dir/build

CMakeFiles/lab_02.dir/clean:
	$(CMAKE_COMMAND) -P CMakeFiles/lab_02.dir/cmake_clean.cmake
.PHONY : CMakeFiles/lab_02.dir/clean

CMakeFiles/lab_02.dir/depend:
	cd /home/crypto_samurai/github-archeos/bmstu-oop-4th-sem/lab_02/build && $(CMAKE_COMMAND) -E cmake_depends "Unix Makefiles" /home/crypto_samurai/github-archeos/bmstu-oop-4th-sem/lab_02 /home/crypto_samurai/github-archeos/bmstu-oop-4th-sem/lab_02 /home/crypto_samurai/github-archeos/bmstu-oop-4th-sem/lab_02/build /home/crypto_samurai/github-archeos/bmstu-oop-4th-sem/lab_02/build /home/crypto_samurai/github-archeos/bmstu-oop-4th-sem/lab_02/build/CMakeFiles/lab_02.dir/DependInfo.cmake --color=$(COLOR)
.PHONY : CMakeFiles/lab_02.dir/depend
