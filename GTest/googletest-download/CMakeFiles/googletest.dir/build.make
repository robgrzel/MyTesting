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
CMAKE_SOURCE_DIR = /mnt/G/MEGASync/Sync/WORK/Proj/MyTesting/GTest/googletest-download

# The top-level build directory on which CMake was run.
CMAKE_BINARY_DIR = /mnt/G/MEGASync/Sync/WORK/Proj/MyTesting/GTest/googletest-download

# Utility rule file for googletest.

# Include the progress variables for this target.
include CMakeFiles/googletest.dir/progress.make

CMakeFiles/googletest: CMakeFiles/googletest-complete


CMakeFiles/googletest-complete: googletest-prefix/src/googletest-stamp/googletest-install
CMakeFiles/googletest-complete: googletest-prefix/src/googletest-stamp/googletest-mkdir
CMakeFiles/googletest-complete: googletest-prefix/src/googletest-stamp/googletest-download
CMakeFiles/googletest-complete: googletest-prefix/src/googletest-stamp/googletest-update
CMakeFiles/googletest-complete: googletest-prefix/src/googletest-stamp/googletest-patch
CMakeFiles/googletest-complete: googletest-prefix/src/googletest-stamp/googletest-configure
CMakeFiles/googletest-complete: googletest-prefix/src/googletest-stamp/googletest-build
CMakeFiles/googletest-complete: googletest-prefix/src/googletest-stamp/googletest-install
CMakeFiles/googletest-complete: googletest-prefix/src/googletest-stamp/googletest-test
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --blue --bold --progress-dir=/mnt/G/MEGASync/Sync/WORK/Proj/MyTesting/GTest/googletest-download/CMakeFiles --progress-num=$(CMAKE_PROGRESS_1) "Completed 'googletest'"
	/home/robgrzel/.local/share/JetBrains/Toolbox/apps/CLion/ch-0/172.3544.40/bin/cmake/bin/cmake -E make_directory /mnt/G/MEGASync/Sync/WORK/Proj/MyTesting/GTest/googletest-download/CMakeFiles
	/home/robgrzel/.local/share/JetBrains/Toolbox/apps/CLion/ch-0/172.3544.40/bin/cmake/bin/cmake -E touch /mnt/G/MEGASync/Sync/WORK/Proj/MyTesting/GTest/googletest-download/CMakeFiles/googletest-complete
	/home/robgrzel/.local/share/JetBrains/Toolbox/apps/CLion/ch-0/172.3544.40/bin/cmake/bin/cmake -E touch /mnt/G/MEGASync/Sync/WORK/Proj/MyTesting/GTest/googletest-download/googletest-prefix/src/googletest-stamp/googletest-done

googletest-prefix/src/googletest-stamp/googletest-install: googletest-prefix/src/googletest-stamp/googletest-build
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --blue --bold --progress-dir=/mnt/G/MEGASync/Sync/WORK/Proj/MyTesting/GTest/googletest-download/CMakeFiles --progress-num=$(CMAKE_PROGRESS_2) "No install step for 'googletest'"
	cd /mnt/G/MEGASync/Sync/WORK/Proj/MyTesting/GTest/googletest-build && /home/robgrzel/.local/share/JetBrains/Toolbox/apps/CLion/ch-0/172.3544.40/bin/cmake/bin/cmake -E echo_append
	cd /mnt/G/MEGASync/Sync/WORK/Proj/MyTesting/GTest/googletest-build && /home/robgrzel/.local/share/JetBrains/Toolbox/apps/CLion/ch-0/172.3544.40/bin/cmake/bin/cmake -E touch /mnt/G/MEGASync/Sync/WORK/Proj/MyTesting/GTest/googletest-download/googletest-prefix/src/googletest-stamp/googletest-install

googletest-prefix/src/googletest-stamp/googletest-mkdir:
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --blue --bold --progress-dir=/mnt/G/MEGASync/Sync/WORK/Proj/MyTesting/GTest/googletest-download/CMakeFiles --progress-num=$(CMAKE_PROGRESS_3) "Creating directories for 'googletest'"
	/home/robgrzel/.local/share/JetBrains/Toolbox/apps/CLion/ch-0/172.3544.40/bin/cmake/bin/cmake -E make_directory /mnt/G/MEGASync/Sync/WORK/Proj/MyTesting/GTest/googletest-src
	/home/robgrzel/.local/share/JetBrains/Toolbox/apps/CLion/ch-0/172.3544.40/bin/cmake/bin/cmake -E make_directory /mnt/G/MEGASync/Sync/WORK/Proj/MyTesting/GTest/googletest-build
	/home/robgrzel/.local/share/JetBrains/Toolbox/apps/CLion/ch-0/172.3544.40/bin/cmake/bin/cmake -E make_directory /mnt/G/MEGASync/Sync/WORK/Proj/MyTesting/GTest/googletest-download/googletest-prefix
	/home/robgrzel/.local/share/JetBrains/Toolbox/apps/CLion/ch-0/172.3544.40/bin/cmake/bin/cmake -E make_directory /mnt/G/MEGASync/Sync/WORK/Proj/MyTesting/GTest/googletest-download/googletest-prefix/tmp
	/home/robgrzel/.local/share/JetBrains/Toolbox/apps/CLion/ch-0/172.3544.40/bin/cmake/bin/cmake -E make_directory /mnt/G/MEGASync/Sync/WORK/Proj/MyTesting/GTest/googletest-download/googletest-prefix/src/googletest-stamp
	/home/robgrzel/.local/share/JetBrains/Toolbox/apps/CLion/ch-0/172.3544.40/bin/cmake/bin/cmake -E make_directory /mnt/G/MEGASync/Sync/WORK/Proj/MyTesting/GTest/googletest-download/googletest-prefix/src
	/home/robgrzel/.local/share/JetBrains/Toolbox/apps/CLion/ch-0/172.3544.40/bin/cmake/bin/cmake -E touch /mnt/G/MEGASync/Sync/WORK/Proj/MyTesting/GTest/googletest-download/googletest-prefix/src/googletest-stamp/googletest-mkdir

googletest-prefix/src/googletest-stamp/googletest-download: googletest-prefix/src/googletest-stamp/googletest-gitinfo.txt
googletest-prefix/src/googletest-stamp/googletest-download: googletest-prefix/src/googletest-stamp/googletest-mkdir
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --blue --bold --progress-dir=/mnt/G/MEGASync/Sync/WORK/Proj/MyTesting/GTest/googletest-download/CMakeFiles --progress-num=$(CMAKE_PROGRESS_4) "Performing download step (git clone) for 'googletest'"
	cd /mnt/G/MEGASync/Sync/WORK/Proj/MyTesting/GTest && /home/robgrzel/.local/share/JetBrains/Toolbox/apps/CLion/ch-0/172.3544.40/bin/cmake/bin/cmake -P /mnt/G/MEGASync/Sync/WORK/Proj/MyTesting/GTest/googletest-download/googletest-prefix/tmp/googletest-gitclone.cmake
	cd /mnt/G/MEGASync/Sync/WORK/Proj/MyTesting/GTest && /home/robgrzel/.local/share/JetBrains/Toolbox/apps/CLion/ch-0/172.3544.40/bin/cmake/bin/cmake -E touch /mnt/G/MEGASync/Sync/WORK/Proj/MyTesting/GTest/googletest-download/googletest-prefix/src/googletest-stamp/googletest-download

googletest-prefix/src/googletest-stamp/googletest-update: googletest-prefix/src/googletest-stamp/googletest-download
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --blue --bold --progress-dir=/mnt/G/MEGASync/Sync/WORK/Proj/MyTesting/GTest/googletest-download/CMakeFiles --progress-num=$(CMAKE_PROGRESS_5) "Performing update step for 'googletest'"
	cd /mnt/G/MEGASync/Sync/WORK/Proj/MyTesting/GTest/googletest-src && /home/robgrzel/.local/share/JetBrains/Toolbox/apps/CLion/ch-0/172.3544.40/bin/cmake/bin/cmake -P /mnt/G/MEGASync/Sync/WORK/Proj/MyTesting/GTest/googletest-download/googletest-prefix/tmp/googletest-gitupdate.cmake

googletest-prefix/src/googletest-stamp/googletest-patch: googletest-prefix/src/googletest-stamp/googletest-download
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --blue --bold --progress-dir=/mnt/G/MEGASync/Sync/WORK/Proj/MyTesting/GTest/googletest-download/CMakeFiles --progress-num=$(CMAKE_PROGRESS_6) "No patch step for 'googletest'"
	/home/robgrzel/.local/share/JetBrains/Toolbox/apps/CLion/ch-0/172.3544.40/bin/cmake/bin/cmake -E echo_append
	/home/robgrzel/.local/share/JetBrains/Toolbox/apps/CLion/ch-0/172.3544.40/bin/cmake/bin/cmake -E touch /mnt/G/MEGASync/Sync/WORK/Proj/MyTesting/GTest/googletest-download/googletest-prefix/src/googletest-stamp/googletest-patch

googletest-prefix/src/googletest-stamp/googletest-configure: googletest-prefix/tmp/googletest-cfgcmd.txt
googletest-prefix/src/googletest-stamp/googletest-configure: googletest-prefix/src/googletest-stamp/googletest-update
googletest-prefix/src/googletest-stamp/googletest-configure: googletest-prefix/src/googletest-stamp/googletest-patch
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --blue --bold --progress-dir=/mnt/G/MEGASync/Sync/WORK/Proj/MyTesting/GTest/googletest-download/CMakeFiles --progress-num=$(CMAKE_PROGRESS_7) "No configure step for 'googletest'"
	cd /mnt/G/MEGASync/Sync/WORK/Proj/MyTesting/GTest/googletest-build && /home/robgrzel/.local/share/JetBrains/Toolbox/apps/CLion/ch-0/172.3544.40/bin/cmake/bin/cmake -E echo_append
	cd /mnt/G/MEGASync/Sync/WORK/Proj/MyTesting/GTest/googletest-build && /home/robgrzel/.local/share/JetBrains/Toolbox/apps/CLion/ch-0/172.3544.40/bin/cmake/bin/cmake -E touch /mnt/G/MEGASync/Sync/WORK/Proj/MyTesting/GTest/googletest-download/googletest-prefix/src/googletest-stamp/googletest-configure

googletest-prefix/src/googletest-stamp/googletest-build: googletest-prefix/src/googletest-stamp/googletest-configure
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --blue --bold --progress-dir=/mnt/G/MEGASync/Sync/WORK/Proj/MyTesting/GTest/googletest-download/CMakeFiles --progress-num=$(CMAKE_PROGRESS_8) "No build step for 'googletest'"
	cd /mnt/G/MEGASync/Sync/WORK/Proj/MyTesting/GTest/googletest-build && /home/robgrzel/.local/share/JetBrains/Toolbox/apps/CLion/ch-0/172.3544.40/bin/cmake/bin/cmake -E echo_append
	cd /mnt/G/MEGASync/Sync/WORK/Proj/MyTesting/GTest/googletest-build && /home/robgrzel/.local/share/JetBrains/Toolbox/apps/CLion/ch-0/172.3544.40/bin/cmake/bin/cmake -E touch /mnt/G/MEGASync/Sync/WORK/Proj/MyTesting/GTest/googletest-download/googletest-prefix/src/googletest-stamp/googletest-build

googletest-prefix/src/googletest-stamp/googletest-test: googletest-prefix/src/googletest-stamp/googletest-install
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --blue --bold --progress-dir=/mnt/G/MEGASync/Sync/WORK/Proj/MyTesting/GTest/googletest-download/CMakeFiles --progress-num=$(CMAKE_PROGRESS_9) "No test step for 'googletest'"
	cd /mnt/G/MEGASync/Sync/WORK/Proj/MyTesting/GTest/googletest-build && /home/robgrzel/.local/share/JetBrains/Toolbox/apps/CLion/ch-0/172.3544.40/bin/cmake/bin/cmake -E echo_append
	cd /mnt/G/MEGASync/Sync/WORK/Proj/MyTesting/GTest/googletest-build && /home/robgrzel/.local/share/JetBrains/Toolbox/apps/CLion/ch-0/172.3544.40/bin/cmake/bin/cmake -E touch /mnt/G/MEGASync/Sync/WORK/Proj/MyTesting/GTest/googletest-download/googletest-prefix/src/googletest-stamp/googletest-test

googletest: CMakeFiles/googletest
googletest: CMakeFiles/googletest-complete
googletest: googletest-prefix/src/googletest-stamp/googletest-install
googletest: googletest-prefix/src/googletest-stamp/googletest-mkdir
googletest: googletest-prefix/src/googletest-stamp/googletest-download
googletest: googletest-prefix/src/googletest-stamp/googletest-update
googletest: googletest-prefix/src/googletest-stamp/googletest-patch
googletest: googletest-prefix/src/googletest-stamp/googletest-configure
googletest: googletest-prefix/src/googletest-stamp/googletest-build
googletest: googletest-prefix/src/googletest-stamp/googletest-test
googletest: CMakeFiles/googletest.dir/build.make

.PHONY : googletest

# Rule to build all files generated by this target.
CMakeFiles/googletest.dir/build: googletest

.PHONY : CMakeFiles/googletest.dir/build

CMakeFiles/googletest.dir/clean:
	$(CMAKE_COMMAND) -P CMakeFiles/googletest.dir/cmake_clean.cmake
.PHONY : CMakeFiles/googletest.dir/clean

CMakeFiles/googletest.dir/depend:
	cd /mnt/G/MEGASync/Sync/WORK/Proj/MyTesting/GTest/googletest-download && $(CMAKE_COMMAND) -E cmake_depends "Unix Makefiles" /mnt/G/MEGASync/Sync/WORK/Proj/MyTesting/GTest/googletest-download /mnt/G/MEGASync/Sync/WORK/Proj/MyTesting/GTest/googletest-download /mnt/G/MEGASync/Sync/WORK/Proj/MyTesting/GTest/googletest-download /mnt/G/MEGASync/Sync/WORK/Proj/MyTesting/GTest/googletest-download /mnt/G/MEGASync/Sync/WORK/Proj/MyTesting/GTest/googletest-download/CMakeFiles/googletest.dir/DependInfo.cmake --color=$(COLOR)
.PHONY : CMakeFiles/googletest.dir/depend

