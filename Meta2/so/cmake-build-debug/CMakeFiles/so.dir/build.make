# CMAKE generated file: DO NOT EDIT!
# Generated by "Unix Makefiles" Generator, CMake Version 3.20

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
CMAKE_COMMAND = /home/mike/install/CLion-2021.2.3/clion-2021.2.3/bin/cmake/linux/bin/cmake

# The command to remove a file.
RM = /home/mike/install/CLion-2021.2.3/clion-2021.2.3/bin/cmake/linux/bin/cmake -E rm -f

# Escaping for special characters.
EQUALS = =

# The top-level source directory on which CMake was run.
CMAKE_SOURCE_DIR = /home/mike/so

# The top-level build directory on which CMake was run.
CMAKE_BINARY_DIR = /home/mike/so/cmake-build-debug

# Include any dependencies generated for this target.
include CMakeFiles/so.dir/depend.make
# Include the progress variables for this target.
include CMakeFiles/so.dir/progress.make

# Include the compile flags for this target's objects.
include CMakeFiles/so.dir/flags.make

CMakeFiles/so.dir/balcao.c.o: CMakeFiles/so.dir/flags.make
CMakeFiles/so.dir/balcao.c.o: ../balcao.c
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/home/mike/so/cmake-build-debug/CMakeFiles --progress-num=$(CMAKE_PROGRESS_1) "Building C object CMakeFiles/so.dir/balcao.c.o"
	/usr/bin/cc $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -o CMakeFiles/so.dir/balcao.c.o -c /home/mike/so/balcao.c

CMakeFiles/so.dir/balcao.c.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing C source to CMakeFiles/so.dir/balcao.c.i"
	/usr/bin/cc $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -E /home/mike/so/balcao.c > CMakeFiles/so.dir/balcao.c.i

CMakeFiles/so.dir/balcao.c.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling C source to assembly CMakeFiles/so.dir/balcao.c.s"
	/usr/bin/cc $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -S /home/mike/so/balcao.c -o CMakeFiles/so.dir/balcao.c.s

CMakeFiles/so.dir/classifica.c.o: CMakeFiles/so.dir/flags.make
CMakeFiles/so.dir/classifica.c.o: ../classifica.c
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/home/mike/so/cmake-build-debug/CMakeFiles --progress-num=$(CMAKE_PROGRESS_2) "Building C object CMakeFiles/so.dir/classifica.c.o"
	/usr/bin/cc $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -o CMakeFiles/so.dir/classifica.c.o -c /home/mike/so/classifica.c

CMakeFiles/so.dir/classifica.c.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing C source to CMakeFiles/so.dir/classifica.c.i"
	/usr/bin/cc $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -E /home/mike/so/classifica.c > CMakeFiles/so.dir/classifica.c.i

CMakeFiles/so.dir/classifica.c.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling C source to assembly CMakeFiles/so.dir/classifica.c.s"
	/usr/bin/cc $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -S /home/mike/so/classifica.c -o CMakeFiles/so.dir/classifica.c.s

CMakeFiles/so.dir/utente.c.o: CMakeFiles/so.dir/flags.make
CMakeFiles/so.dir/utente.c.o: ../utente.c
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/home/mike/so/cmake-build-debug/CMakeFiles --progress-num=$(CMAKE_PROGRESS_3) "Building C object CMakeFiles/so.dir/utente.c.o"
	/usr/bin/cc $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -o CMakeFiles/so.dir/utente.c.o -c /home/mike/so/utente.c

CMakeFiles/so.dir/utente.c.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing C source to CMakeFiles/so.dir/utente.c.i"
	/usr/bin/cc $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -E /home/mike/so/utente.c > CMakeFiles/so.dir/utente.c.i

CMakeFiles/so.dir/utente.c.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling C source to assembly CMakeFiles/so.dir/utente.c.s"
	/usr/bin/cc $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -S /home/mike/so/utente.c -o CMakeFiles/so.dir/utente.c.s

CMakeFiles/so.dir/medico.c.o: CMakeFiles/so.dir/flags.make
CMakeFiles/so.dir/medico.c.o: ../medico.c
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/home/mike/so/cmake-build-debug/CMakeFiles --progress-num=$(CMAKE_PROGRESS_4) "Building C object CMakeFiles/so.dir/medico.c.o"
	/usr/bin/cc $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -o CMakeFiles/so.dir/medico.c.o -c /home/mike/so/medico.c

CMakeFiles/so.dir/medico.c.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing C source to CMakeFiles/so.dir/medico.c.i"
	/usr/bin/cc $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -E /home/mike/so/medico.c > CMakeFiles/so.dir/medico.c.i

CMakeFiles/so.dir/medico.c.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling C source to assembly CMakeFiles/so.dir/medico.c.s"
	/usr/bin/cc $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -S /home/mike/so/medico.c -o CMakeFiles/so.dir/medico.c.s

# Object files for target so
so_OBJECTS = \
"CMakeFiles/so.dir/balcao.c.o" \
"CMakeFiles/so.dir/classifica.c.o" \
"CMakeFiles/so.dir/utente.c.o" \
"CMakeFiles/so.dir/medico.c.o"

# External object files for target so
so_EXTERNAL_OBJECTS =

so: CMakeFiles/so.dir/balcao.c.o
so: CMakeFiles/so.dir/classifica.c.o
so: CMakeFiles/so.dir/utente.c.o
so: CMakeFiles/so.dir/medico.c.o
so: CMakeFiles/so.dir/build.make
so: CMakeFiles/so.dir/link.txt
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --bold --progress-dir=/home/mike/so/cmake-build-debug/CMakeFiles --progress-num=$(CMAKE_PROGRESS_5) "Linking C executable so"
	$(CMAKE_COMMAND) -E cmake_link_script CMakeFiles/so.dir/link.txt --verbose=$(VERBOSE)

# Rule to build all files generated by this target.
CMakeFiles/so.dir/build: so
.PHONY : CMakeFiles/so.dir/build

CMakeFiles/so.dir/clean:
	$(CMAKE_COMMAND) -P CMakeFiles/so.dir/cmake_clean.cmake
.PHONY : CMakeFiles/so.dir/clean

CMakeFiles/so.dir/depend:
	cd /home/mike/so/cmake-build-debug && $(CMAKE_COMMAND) -E cmake_depends "Unix Makefiles" /home/mike/so /home/mike/so /home/mike/so/cmake-build-debug /home/mike/so/cmake-build-debug /home/mike/so/cmake-build-debug/CMakeFiles/so.dir/DependInfo.cmake --color=$(COLOR)
.PHONY : CMakeFiles/so.dir/depend
