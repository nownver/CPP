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
CMAKE_SOURCE_DIR = /Users/yokurawee/cpp_work/lab9/02

# The top-level build directory on which CMake was run.
CMAKE_BINARY_DIR = /Users/yokurawee/cpp_work/lab9/02

# Include any dependencies generated for this target.
include CMakeFiles/hero_html.dir/depend.make
# Include any dependencies generated by the compiler for this target.
include CMakeFiles/hero_html.dir/compiler_depend.make

# Include the progress variables for this target.
include CMakeFiles/hero_html.dir/progress.make

# Include the compile flags for this target's objects.
include CMakeFiles/hero_html.dir/flags.make

CMakeFiles/hero_html.dir/hero.cpp.o: CMakeFiles/hero_html.dir/flags.make
CMakeFiles/hero_html.dir/hero.cpp.o: hero.cpp
CMakeFiles/hero_html.dir/hero.cpp.o: CMakeFiles/hero_html.dir/compiler_depend.ts
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/Users/yokurawee/cpp_work/lab9/02/CMakeFiles --progress-num=$(CMAKE_PROGRESS_1) "Building CXX object CMakeFiles/hero_html.dir/hero.cpp.o"
	/Library/Developer/CommandLineTools/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -MD -MT CMakeFiles/hero_html.dir/hero.cpp.o -MF CMakeFiles/hero_html.dir/hero.cpp.o.d -o CMakeFiles/hero_html.dir/hero.cpp.o -c /Users/yokurawee/cpp_work/lab9/02/hero.cpp

CMakeFiles/hero_html.dir/hero.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/hero_html.dir/hero.cpp.i"
	/Library/Developer/CommandLineTools/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /Users/yokurawee/cpp_work/lab9/02/hero.cpp > CMakeFiles/hero_html.dir/hero.cpp.i

CMakeFiles/hero_html.dir/hero.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/hero_html.dir/hero.cpp.s"
	/Library/Developer/CommandLineTools/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /Users/yokurawee/cpp_work/lab9/02/hero.cpp -o CMakeFiles/hero_html.dir/hero.cpp.s

CMakeFiles/hero_html.dir/nse/html.cpp.o: CMakeFiles/hero_html.dir/flags.make
CMakeFiles/hero_html.dir/nse/html.cpp.o: nse/html.cpp
CMakeFiles/hero_html.dir/nse/html.cpp.o: CMakeFiles/hero_html.dir/compiler_depend.ts
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/Users/yokurawee/cpp_work/lab9/02/CMakeFiles --progress-num=$(CMAKE_PROGRESS_2) "Building CXX object CMakeFiles/hero_html.dir/nse/html.cpp.o"
	/Library/Developer/CommandLineTools/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -MD -MT CMakeFiles/hero_html.dir/nse/html.cpp.o -MF CMakeFiles/hero_html.dir/nse/html.cpp.o.d -o CMakeFiles/hero_html.dir/nse/html.cpp.o -c /Users/yokurawee/cpp_work/lab9/02/nse/html.cpp

CMakeFiles/hero_html.dir/nse/html.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/hero_html.dir/nse/html.cpp.i"
	/Library/Developer/CommandLineTools/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /Users/yokurawee/cpp_work/lab9/02/nse/html.cpp > CMakeFiles/hero_html.dir/nse/html.cpp.i

CMakeFiles/hero_html.dir/nse/html.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/hero_html.dir/nse/html.cpp.s"
	/Library/Developer/CommandLineTools/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /Users/yokurawee/cpp_work/lab9/02/nse/html.cpp -o CMakeFiles/hero_html.dir/nse/html.cpp.s

# Object files for target hero_html
hero_html_OBJECTS = \
"CMakeFiles/hero_html.dir/hero.cpp.o" \
"CMakeFiles/hero_html.dir/nse/html.cpp.o"

# External object files for target hero_html
hero_html_EXTERNAL_OBJECTS =

hero_html: CMakeFiles/hero_html.dir/hero.cpp.o
hero_html: CMakeFiles/hero_html.dir/nse/html.cpp.o
hero_html: CMakeFiles/hero_html.dir/build.make
hero_html: CMakeFiles/hero_html.dir/link.txt
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --bold --progress-dir=/Users/yokurawee/cpp_work/lab9/02/CMakeFiles --progress-num=$(CMAKE_PROGRESS_3) "Linking CXX executable hero_html"
	$(CMAKE_COMMAND) -E cmake_link_script CMakeFiles/hero_html.dir/link.txt --verbose=$(VERBOSE)

# Rule to build all files generated by this target.
CMakeFiles/hero_html.dir/build: hero_html
.PHONY : CMakeFiles/hero_html.dir/build

CMakeFiles/hero_html.dir/clean:
	$(CMAKE_COMMAND) -P CMakeFiles/hero_html.dir/cmake_clean.cmake
.PHONY : CMakeFiles/hero_html.dir/clean

CMakeFiles/hero_html.dir/depend:
	cd /Users/yokurawee/cpp_work/lab9/02 && $(CMAKE_COMMAND) -E cmake_depends "Unix Makefiles" /Users/yokurawee/cpp_work/lab9/02 /Users/yokurawee/cpp_work/lab9/02 /Users/yokurawee/cpp_work/lab9/02 /Users/yokurawee/cpp_work/lab9/02 /Users/yokurawee/cpp_work/lab9/02/CMakeFiles/hero_html.dir/DependInfo.cmake --color=$(COLOR)
.PHONY : CMakeFiles/hero_html.dir/depend

