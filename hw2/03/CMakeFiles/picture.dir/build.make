# CMAKE generated file: DO NOT EDIT!
# Generated by "Unix Makefiles" Generator, CMake Version 3.25

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
CMAKE_COMMAND = /opt/homebrew/Cellar/cmake/3.25.2/bin/cmake

# The command to remove a file.
RM = /opt/homebrew/Cellar/cmake/3.25.2/bin/cmake -E rm -f

# Escaping for special characters.
EQUALS = =

# The top-level source directory on which CMake was run.
CMAKE_SOURCE_DIR = /Users/yokurawee/cpp_work/hw2/03

# The top-level build directory on which CMake was run.
CMAKE_BINARY_DIR = /Users/yokurawee/cpp_work/hw2/03

# Include any dependencies generated for this target.
include CMakeFiles/picture.dir/depend.make
# Include any dependencies generated by the compiler for this target.
include CMakeFiles/picture.dir/compiler_depend.make

# Include the progress variables for this target.
include CMakeFiles/picture.dir/progress.make

# Include the compile flags for this target's objects.
include CMakeFiles/picture.dir/flags.make

CMakeFiles/picture.dir/picture.cpp.o: CMakeFiles/picture.dir/flags.make
CMakeFiles/picture.dir/picture.cpp.o: picture.cpp
CMakeFiles/picture.dir/picture.cpp.o: CMakeFiles/picture.dir/compiler_depend.ts
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/Users/yokurawee/cpp_work/hw2/03/CMakeFiles --progress-num=$(CMAKE_PROGRESS_1) "Building CXX object CMakeFiles/picture.dir/picture.cpp.o"
	/Library/Developer/CommandLineTools/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -MD -MT CMakeFiles/picture.dir/picture.cpp.o -MF CMakeFiles/picture.dir/picture.cpp.o.d -o CMakeFiles/picture.dir/picture.cpp.o -c /Users/yokurawee/cpp_work/hw2/03/picture.cpp

CMakeFiles/picture.dir/picture.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/picture.dir/picture.cpp.i"
	/Library/Developer/CommandLineTools/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /Users/yokurawee/cpp_work/hw2/03/picture.cpp > CMakeFiles/picture.dir/picture.cpp.i

CMakeFiles/picture.dir/picture.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/picture.dir/picture.cpp.s"
	/Library/Developer/CommandLineTools/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /Users/yokurawee/cpp_work/hw2/03/picture.cpp -o CMakeFiles/picture.dir/picture.cpp.s

CMakeFiles/picture.dir/picture_functions.cpp.o: CMakeFiles/picture.dir/flags.make
CMakeFiles/picture.dir/picture_functions.cpp.o: picture_functions.cpp
CMakeFiles/picture.dir/picture_functions.cpp.o: CMakeFiles/picture.dir/compiler_depend.ts
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/Users/yokurawee/cpp_work/hw2/03/CMakeFiles --progress-num=$(CMAKE_PROGRESS_2) "Building CXX object CMakeFiles/picture.dir/picture_functions.cpp.o"
	/Library/Developer/CommandLineTools/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -MD -MT CMakeFiles/picture.dir/picture_functions.cpp.o -MF CMakeFiles/picture.dir/picture_functions.cpp.o.d -o CMakeFiles/picture.dir/picture_functions.cpp.o -c /Users/yokurawee/cpp_work/hw2/03/picture_functions.cpp

CMakeFiles/picture.dir/picture_functions.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/picture.dir/picture_functions.cpp.i"
	/Library/Developer/CommandLineTools/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /Users/yokurawee/cpp_work/hw2/03/picture_functions.cpp > CMakeFiles/picture.dir/picture_functions.cpp.i

CMakeFiles/picture.dir/picture_functions.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/picture.dir/picture_functions.cpp.s"
	/Library/Developer/CommandLineTools/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /Users/yokurawee/cpp_work/hw2/03/picture_functions.cpp -o CMakeFiles/picture.dir/picture_functions.cpp.s

# Object files for target picture
picture_OBJECTS = \
"CMakeFiles/picture.dir/picture.cpp.o" \
"CMakeFiles/picture.dir/picture_functions.cpp.o"

# External object files for target picture
picture_EXTERNAL_OBJECTS =

picture: CMakeFiles/picture.dir/picture.cpp.o
picture: CMakeFiles/picture.dir/picture_functions.cpp.o
picture: CMakeFiles/picture.dir/build.make
picture: CMakeFiles/picture.dir/link.txt
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --bold --progress-dir=/Users/yokurawee/cpp_work/hw2/03/CMakeFiles --progress-num=$(CMAKE_PROGRESS_3) "Linking CXX executable picture"
	$(CMAKE_COMMAND) -E cmake_link_script CMakeFiles/picture.dir/link.txt --verbose=$(VERBOSE)

# Rule to build all files generated by this target.
CMakeFiles/picture.dir/build: picture
.PHONY : CMakeFiles/picture.dir/build

CMakeFiles/picture.dir/clean:
	$(CMAKE_COMMAND) -P CMakeFiles/picture.dir/cmake_clean.cmake
.PHONY : CMakeFiles/picture.dir/clean

CMakeFiles/picture.dir/depend:
	cd /Users/yokurawee/cpp_work/hw2/03 && $(CMAKE_COMMAND) -E cmake_depends "Unix Makefiles" /Users/yokurawee/cpp_work/hw2/03 /Users/yokurawee/cpp_work/hw2/03 /Users/yokurawee/cpp_work/hw2/03 /Users/yokurawee/cpp_work/hw2/03 /Users/yokurawee/cpp_work/hw2/03/CMakeFiles/picture.dir/DependInfo.cmake --color=$(COLOR)
.PHONY : CMakeFiles/picture.dir/depend
