# CMAKE generated file: DO NOT EDIT!
# Generated by "Unix Makefiles" Generator, CMake Version 3.8

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
CMAKE_COMMAND = /home/robgrzel/.local/share/JetBrains/Toolbox/apps/CLion/ch-0/172.3544.40/bin/cmake/bin/cmake

# The command to remove a file.
RM = /home/robgrzel/.local/share/JetBrains/Toolbox/apps/CLion/ch-0/172.3544.40/bin/cmake/bin/cmake -E remove -f

# Escaping for special characters.
EQUALS = =

# The top-level source directory on which CMake was run.
CMAKE_SOURCE_DIR = /mnt/G/MEGASync/Sync/WORK/Proj/MyTesting

# The top-level build directory on which CMake was run.
CMAKE_BINARY_DIR = /mnt/G/MEGASync/Sync/WORK/Proj/MyTesting/cmake-build-debug

# Include any dependencies generated for this target.
include ../GTest/googletest-build/googlemock/CMakeFiles/gmock.dir/depend.make

# Include the progress variables for this target.
include ../GTest/googletest-build/googlemock/CMakeFiles/gmock.dir/progress.make

# Include the compile flags for this target's objects.
include ../GTest/googletest-build/googlemock/CMakeFiles/gmock.dir/flags.make

../GTest/googletest-build/googlemock/CMakeFiles/gmock.dir/__/googletest/src/gtest-all.cc.o: ../GTest/googletest-build/googlemock/CMakeFiles/gmock.dir/flags.make
../GTest/googletest-build/googlemock/CMakeFiles/gmock.dir/__/googletest/src/gtest-all.cc.o: ../GTest/googletest-src/googletest/src/gtest-all.cc
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/mnt/G/MEGASync/Sync/WORK/Proj/MyTesting/cmake-build-debug/CMakeFiles --progress-num=$(CMAKE_PROGRESS_1) "Building CXX object ../GTest/googletest-build/googlemock/CMakeFiles/gmock.dir/__/googletest/src/gtest-all.cc.o"
	cd /mnt/G/MEGASync/Sync/WORK/Proj/MyTesting/GTest/googletest-build/googlemock && /usr/bin/c++  $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -o CMakeFiles/gmock.dir/__/googletest/src/gtest-all.cc.o -c /mnt/G/MEGASync/Sync/WORK/Proj/MyTesting/GTest/googletest-src/googletest/src/gtest-all.cc

../GTest/googletest-build/googlemock/CMakeFiles/gmock.dir/__/googletest/src/gtest-all.cc.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/gmock.dir/__/googletest/src/gtest-all.cc.i"
	cd /mnt/G/MEGASync/Sync/WORK/Proj/MyTesting/GTest/googletest-build/googlemock && /usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /mnt/G/MEGASync/Sync/WORK/Proj/MyTesting/GTest/googletest-src/googletest/src/gtest-all.cc > CMakeFiles/gmock.dir/__/googletest/src/gtest-all.cc.i

../GTest/googletest-build/googlemock/CMakeFiles/gmock.dir/__/googletest/src/gtest-all.cc.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/gmock.dir/__/googletest/src/gtest-all.cc.s"
	cd /mnt/G/MEGASync/Sync/WORK/Proj/MyTesting/GTest/googletest-build/googlemock && /usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /mnt/G/MEGASync/Sync/WORK/Proj/MyTesting/GTest/googletest-src/googletest/src/gtest-all.cc -o CMakeFiles/gmock.dir/__/googletest/src/gtest-all.cc.s

../GTest/googletest-build/googlemock/CMakeFiles/gmock.dir/__/googletest/src/gtest-all.cc.o.requires:

.PHONY : ../GTest/googletest-build/googlemock/CMakeFiles/gmock.dir/__/googletest/src/gtest-all.cc.o.requires

../GTest/googletest-build/googlemock/CMakeFiles/gmock.dir/__/googletest/src/gtest-all.cc.o.provides: ../GTest/googletest-build/googlemock/CMakeFiles/gmock.dir/__/googletest/src/gtest-all.cc.o.requires
	$(MAKE) -f ../GTest/googletest-build/googlemock/CMakeFiles/gmock.dir/build.make ../GTest/googletest-build/googlemock/CMakeFiles/gmock.dir/__/googletest/src/gtest-all.cc.o.provides.build
.PHONY : ../GTest/googletest-build/googlemock/CMakeFiles/gmock.dir/__/googletest/src/gtest-all.cc.o.provides

../GTest/googletest-build/googlemock/CMakeFiles/gmock.dir/__/googletest/src/gtest-all.cc.o.provides.build: ../GTest/googletest-build/googlemock/CMakeFiles/gmock.dir/__/googletest/src/gtest-all.cc.o


../GTest/googletest-build/googlemock/CMakeFiles/gmock.dir/src/gmock-all.cc.o: ../GTest/googletest-build/googlemock/CMakeFiles/gmock.dir/flags.make
../GTest/googletest-build/googlemock/CMakeFiles/gmock.dir/src/gmock-all.cc.o: ../GTest/googletest-src/googlemock/src/gmock-all.cc
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/mnt/G/MEGASync/Sync/WORK/Proj/MyTesting/cmake-build-debug/CMakeFiles --progress-num=$(CMAKE_PROGRESS_2) "Building CXX object ../GTest/googletest-build/googlemock/CMakeFiles/gmock.dir/src/gmock-all.cc.o"
	cd /mnt/G/MEGASync/Sync/WORK/Proj/MyTesting/GTest/googletest-build/googlemock && /usr/bin/c++  $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -o CMakeFiles/gmock.dir/src/gmock-all.cc.o -c /mnt/G/MEGASync/Sync/WORK/Proj/MyTesting/GTest/googletest-src/googlemock/src/gmock-all.cc

../GTest/googletest-build/googlemock/CMakeFiles/gmock.dir/src/gmock-all.cc.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/gmock.dir/src/gmock-all.cc.i"
	cd /mnt/G/MEGASync/Sync/WORK/Proj/MyTesting/GTest/googletest-build/googlemock && /usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /mnt/G/MEGASync/Sync/WORK/Proj/MyTesting/GTest/googletest-src/googlemock/src/gmock-all.cc > CMakeFiles/gmock.dir/src/gmock-all.cc.i

../GTest/googletest-build/googlemock/CMakeFiles/gmock.dir/src/gmock-all.cc.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/gmock.dir/src/gmock-all.cc.s"
	cd /mnt/G/MEGASync/Sync/WORK/Proj/MyTesting/GTest/googletest-build/googlemock && /usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /mnt/G/MEGASync/Sync/WORK/Proj/MyTesting/GTest/googletest-src/googlemock/src/gmock-all.cc -o CMakeFiles/gmock.dir/src/gmock-all.cc.s

../GTest/googletest-build/googlemock/CMakeFiles/gmock.dir/src/gmock-all.cc.o.requires:

.PHONY : ../GTest/googletest-build/googlemock/CMakeFiles/gmock.dir/src/gmock-all.cc.o.requires

../GTest/googletest-build/googlemock/CMakeFiles/gmock.dir/src/gmock-all.cc.o.provides: ../GTest/googletest-build/googlemock/CMakeFiles/gmock.dir/src/gmock-all.cc.o.requires
	$(MAKE) -f ../GTest/googletest-build/googlemock/CMakeFiles/gmock.dir/build.make ../GTest/googletest-build/googlemock/CMakeFiles/gmock.dir/src/gmock-all.cc.o.provides.build
.PHONY : ../GTest/googletest-build/googlemock/CMakeFiles/gmock.dir/src/gmock-all.cc.o.provides

../GTest/googletest-build/googlemock/CMakeFiles/gmock.dir/src/gmock-all.cc.o.provides.build: ../GTest/googletest-build/googlemock/CMakeFiles/gmock.dir/src/gmock-all.cc.o


# Object files for target gmock
gmock_OBJECTS = \
"CMakeFiles/gmock.dir/__/googletest/src/gtest-all.cc.o" \
"CMakeFiles/gmock.dir/src/gmock-all.cc.o"

# External object files for target gmock
gmock_EXTERNAL_OBJECTS =

../GTest/googletest-build/googlemock/libgmock.a: ../GTest/googletest-build/googlemock/CMakeFiles/gmock.dir/__/googletest/src/gtest-all.cc.o
../GTest/googletest-build/googlemock/libgmock.a: ../GTest/googletest-build/googlemock/CMakeFiles/gmock.dir/src/gmock-all.cc.o
../GTest/googletest-build/googlemock/libgmock.a: ../GTest/googletest-build/googlemock/CMakeFiles/gmock.dir/build.make
../GTest/googletest-build/googlemock/libgmock.a: ../GTest/googletest-build/googlemock/CMakeFiles/gmock.dir/link.txt
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --bold --progress-dir=/mnt/G/MEGASync/Sync/WORK/Proj/MyTesting/cmake-build-debug/CMakeFiles --progress-num=$(CMAKE_PROGRESS_3) "Linking CXX static library libgmock.a"
	cd /mnt/G/MEGASync/Sync/WORK/Proj/MyTesting/GTest/googletest-build/googlemock && $(CMAKE_COMMAND) -P CMakeFiles/gmock.dir/cmake_clean_target.cmake
	cd /mnt/G/MEGASync/Sync/WORK/Proj/MyTesting/GTest/googletest-build/googlemock && $(CMAKE_COMMAND) -E cmake_link_script CMakeFiles/gmock.dir/link.txt --verbose=$(VERBOSE)

# Rule to build all files generated by this target.
../GTest/googletest-build/googlemock/CMakeFiles/gmock.dir/build: ../GTest/googletest-build/googlemock/libgmock.a

.PHONY : ../GTest/googletest-build/googlemock/CMakeFiles/gmock.dir/build

../GTest/googletest-build/googlemock/CMakeFiles/gmock.dir/requires: ../GTest/googletest-build/googlemock/CMakeFiles/gmock.dir/__/googletest/src/gtest-all.cc.o.requires
../GTest/googletest-build/googlemock/CMakeFiles/gmock.dir/requires: ../GTest/googletest-build/googlemock/CMakeFiles/gmock.dir/src/gmock-all.cc.o.requires

.PHONY : ../GTest/googletest-build/googlemock/CMakeFiles/gmock.dir/requires

../GTest/googletest-build/googlemock/CMakeFiles/gmock.dir/clean:
	cd /mnt/G/MEGASync/Sync/WORK/Proj/MyTesting/GTest/googletest-build/googlemock && $(CMAKE_COMMAND) -P CMakeFiles/gmock.dir/cmake_clean.cmake
.PHONY : ../GTest/googletest-build/googlemock/CMakeFiles/gmock.dir/clean

../GTest/googletest-build/googlemock/CMakeFiles/gmock.dir/depend:
	cd /mnt/G/MEGASync/Sync/WORK/Proj/MyTesting/cmake-build-debug && $(CMAKE_COMMAND) -E cmake_depends "Unix Makefiles" /mnt/G/MEGASync/Sync/WORK/Proj/MyTesting /mnt/G/MEGASync/Sync/WORK/Proj/MyTesting/GTest/googletest-src/googlemock /mnt/G/MEGASync/Sync/WORK/Proj/MyTesting/cmake-build-debug /mnt/G/MEGASync/Sync/WORK/Proj/MyTesting/GTest/googletest-build/googlemock /mnt/G/MEGASync/Sync/WORK/Proj/MyTesting/GTest/googletest-build/googlemock/CMakeFiles/gmock.dir/DependInfo.cmake --color=$(COLOR)
.PHONY : ../GTest/googletest-build/googlemock/CMakeFiles/gmock.dir/depend

