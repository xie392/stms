# CMAKE generated file: DO NOT EDIT!
# Generated by "MinGW Makefiles" Generator, CMake Version 3.24

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

SHELL = cmd.exe

# The CMake executable.
CMAKE_COMMAND = "E:\Program Files (x86)\CLion 2022.3.3\bin\cmake\win\x64\bin\cmake.exe"

# The command to remove a file.
RM = "E:\Program Files (x86)\CLion 2022.3.3\bin\cmake\win\x64\bin\cmake.exe" -E rm -f

# Escaping for special characters.
EQUALS = =

# The top-level source directory on which CMake was run.
CMAKE_SOURCE_DIR = F:\data_structure\stms

# The top-level build directory on which CMake was run.
CMAKE_BINARY_DIR = F:\data_structure\stms\cmake-build-debug

# Include any dependencies generated for this target.
include CMakeFiles/stms.dir/depend.make
# Include any dependencies generated by the compiler for this target.
include CMakeFiles/stms.dir/compiler_depend.make

# Include the progress variables for this target.
include CMakeFiles/stms.dir/progress.make

# Include the compile flags for this target's objects.
include CMakeFiles/stms.dir/flags.make

CMakeFiles/stms.dir/main.cpp.obj: CMakeFiles/stms.dir/flags.make
CMakeFiles/stms.dir/main.cpp.obj: F:/data_structure/stms/main.cpp
CMakeFiles/stms.dir/main.cpp.obj: CMakeFiles/stms.dir/compiler_depend.ts
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=F:\data_structure\stms\cmake-build-debug\CMakeFiles --progress-num=$(CMAKE_PROGRESS_1) "Building CXX object CMakeFiles/stms.dir/main.cpp.obj"
	"E:\Program Files (x86)\CLion 2022.3.3\bin\mingw\bin\g++.exe" $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -MD -MT CMakeFiles/stms.dir/main.cpp.obj -MF CMakeFiles\stms.dir\main.cpp.obj.d -o CMakeFiles\stms.dir\main.cpp.obj -c F:\data_structure\stms\main.cpp

CMakeFiles/stms.dir/main.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/stms.dir/main.cpp.i"
	"E:\Program Files (x86)\CLion 2022.3.3\bin\mingw\bin\g++.exe" $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E F:\data_structure\stms\main.cpp > CMakeFiles\stms.dir\main.cpp.i

CMakeFiles/stms.dir/main.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/stms.dir/main.cpp.s"
	"E:\Program Files (x86)\CLion 2022.3.3\bin\mingw\bin\g++.exe" $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S F:\data_structure\stms\main.cpp -o CMakeFiles\stms.dir\main.cpp.s

CMakeFiles/stms.dir/student.cpp.obj: CMakeFiles/stms.dir/flags.make
CMakeFiles/stms.dir/student.cpp.obj: F:/data_structure/stms/student.cpp
CMakeFiles/stms.dir/student.cpp.obj: CMakeFiles/stms.dir/compiler_depend.ts
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=F:\data_structure\stms\cmake-build-debug\CMakeFiles --progress-num=$(CMAKE_PROGRESS_2) "Building CXX object CMakeFiles/stms.dir/student.cpp.obj"
	"E:\Program Files (x86)\CLion 2022.3.3\bin\mingw\bin\g++.exe" $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -MD -MT CMakeFiles/stms.dir/student.cpp.obj -MF CMakeFiles\stms.dir\student.cpp.obj.d -o CMakeFiles\stms.dir\student.cpp.obj -c F:\data_structure\stms\student.cpp

CMakeFiles/stms.dir/student.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/stms.dir/student.cpp.i"
	"E:\Program Files (x86)\CLion 2022.3.3\bin\mingw\bin\g++.exe" $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E F:\data_structure\stms\student.cpp > CMakeFiles\stms.dir\student.cpp.i

CMakeFiles/stms.dir/student.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/stms.dir/student.cpp.s"
	"E:\Program Files (x86)\CLion 2022.3.3\bin\mingw\bin\g++.exe" $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S F:\data_structure\stms\student.cpp -o CMakeFiles\stms.dir\student.cpp.s

# Object files for target stms
stms_OBJECTS = \
"CMakeFiles/stms.dir/main.cpp.obj" \
"CMakeFiles/stms.dir/student.cpp.obj"

# External object files for target stms
stms_EXTERNAL_OBJECTS =

stms.exe: CMakeFiles/stms.dir/main.cpp.obj
stms.exe: CMakeFiles/stms.dir/student.cpp.obj
stms.exe: CMakeFiles/stms.dir/build.make
stms.exe: CMakeFiles/stms.dir/linklibs.rsp
stms.exe: CMakeFiles/stms.dir/objects1.rsp
stms.exe: CMakeFiles/stms.dir/link.txt
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --bold --progress-dir=F:\data_structure\stms\cmake-build-debug\CMakeFiles --progress-num=$(CMAKE_PROGRESS_3) "Linking CXX executable stms.exe"
	$(CMAKE_COMMAND) -E cmake_link_script CMakeFiles\stms.dir\link.txt --verbose=$(VERBOSE)

# Rule to build all files generated by this target.
CMakeFiles/stms.dir/build: stms.exe
.PHONY : CMakeFiles/stms.dir/build

CMakeFiles/stms.dir/clean:
	$(CMAKE_COMMAND) -P CMakeFiles\stms.dir\cmake_clean.cmake
.PHONY : CMakeFiles/stms.dir/clean

CMakeFiles/stms.dir/depend:
	$(CMAKE_COMMAND) -E cmake_depends "MinGW Makefiles" F:\data_structure\stms F:\data_structure\stms F:\data_structure\stms\cmake-build-debug F:\data_structure\stms\cmake-build-debug F:\data_structure\stms\cmake-build-debug\CMakeFiles\stms.dir\DependInfo.cmake --color=$(COLOR)
.PHONY : CMakeFiles/stms.dir/depend
