# CMAKE generated file: DO NOT EDIT!
# Generated by "Unix Makefiles" Generator, CMake Version 3.11

# Default target executed when no arguments are given to make.
default_target: all

.PHONY : default_target

# Allow only one "make -f Makefile2" at a time, but pass parallelism.
.NOTPARALLEL:


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
CMAKE_SOURCE_DIR = /home/Arthamios/delivery/OOP/OOP_arcade_2018

# The top-level build directory on which CMake was run.
CMAKE_BINARY_DIR = /home/Arthamios/delivery/OOP/OOP_arcade_2018

#=============================================================================
# Targets provided globally by CMake.

# Special rule for the target rebuild_cache
rebuild_cache:
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --cyan "Running CMake to regenerate build system..."
	/usr/bin/cmake -H$(CMAKE_SOURCE_DIR) -B$(CMAKE_BINARY_DIR)
.PHONY : rebuild_cache

# Special rule for the target rebuild_cache
rebuild_cache/fast: rebuild_cache

.PHONY : rebuild_cache/fast

# Special rule for the target edit_cache
edit_cache:
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --cyan "Running CMake cache editor..."
	/usr/bin/ccmake -H$(CMAKE_SOURCE_DIR) -B$(CMAKE_BINARY_DIR)
.PHONY : edit_cache

# Special rule for the target edit_cache
edit_cache/fast: edit_cache

.PHONY : edit_cache/fast

# The main all target
all: cmake_check_build_system
	$(CMAKE_COMMAND) -E cmake_progress_start /home/Arthamios/delivery/OOP/OOP_arcade_2018/CMakeFiles /home/Arthamios/delivery/OOP/OOP_arcade_2018/CMakeFiles/progress.marks
	$(MAKE) -f CMakeFiles/Makefile2 all
	$(CMAKE_COMMAND) -E cmake_progress_start /home/Arthamios/delivery/OOP/OOP_arcade_2018/CMakeFiles 0
.PHONY : all

# The main clean target
clean:
	$(MAKE) -f CMakeFiles/Makefile2 clean
.PHONY : clean

# The main clean target
clean/fast: clean

.PHONY : clean/fast

# Prepare targets for installation.
preinstall: all
	$(MAKE) -f CMakeFiles/Makefile2 preinstall
.PHONY : preinstall

# Prepare targets for installation.
preinstall/fast:
	$(MAKE) -f CMakeFiles/Makefile2 preinstall
.PHONY : preinstall/fast

# clear depends
depend:
	$(CMAKE_COMMAND) -H$(CMAKE_SOURCE_DIR) -B$(CMAKE_BINARY_DIR) --check-build-system CMakeFiles/Makefile.cmake 1
.PHONY : depend

#=============================================================================
# Target rules for targets named fclean

# Build rule for target.
fclean: cmake_check_build_system
	$(MAKE) -f CMakeFiles/Makefile2 fclean
.PHONY : fclean

# fast build rule for target.
fclean/fast:
	$(MAKE) -f CMakeFiles/fclean.dir/build.make CMakeFiles/fclean.dir/build
.PHONY : fclean/fast

#=============================================================================
# Target rules for targets named arcade

# Build rule for target.
arcade: cmake_check_build_system
	$(MAKE) -f CMakeFiles/Makefile2 arcade
.PHONY : arcade

# fast build rule for target.
arcade/fast:
	$(MAKE) -f CMakeFiles/arcade.dir/build.make CMakeFiles/arcade.dir/build
.PHONY : arcade/fast

#=============================================================================
# Target rules for targets named units

# Build rule for target.
units: cmake_check_build_system
	$(MAKE) -f CMakeFiles/Makefile2 units
.PHONY : units

# fast build rule for target.
units/fast:
	$(MAKE) -f CMakeFiles/units.dir/build.make CMakeFiles/units.dir/build
.PHONY : units/fast

#=============================================================================
# Target rules for targets named re

# Build rule for target.
re: cmake_check_build_system
	$(MAKE) -f CMakeFiles/Makefile2 re
.PHONY : re

# fast build rule for target.
re/fast:
	$(MAKE) -f CMakeFiles/re.dir/build.make CMakeFiles/re.dir/build
.PHONY : re/fast

#=============================================================================
# Target rules for targets named graphicals

# Build rule for target.
graphicals: cmake_check_build_system
	$(MAKE) -f CMakeFiles/Makefile2 graphicals
.PHONY : graphicals

# fast build rule for target.
graphicals/fast:
	$(MAKE) -f CMakeFiles/graphicals.dir/build.make CMakeFiles/graphicals.dir/build
.PHONY : graphicals/fast

#=============================================================================
# Target rules for targets named tests_run

# Build rule for target.
tests_run: cmake_check_build_system
	$(MAKE) -f CMakeFiles/Makefile2 tests_run
.PHONY : tests_run

# fast build rule for target.
tests_run/fast:
	$(MAKE) -f CMakeFiles/tests_run.dir/build.make CMakeFiles/tests_run.dir/build
.PHONY : tests_run/fast

#=============================================================================
# Target rules for targets named games

# Build rule for target.
games: cmake_check_build_system
	$(MAKE) -f CMakeFiles/Makefile2 games
.PHONY : games

# fast build rule for target.
games/fast:
	$(MAKE) -f CMakeFiles/games.dir/build.make CMakeFiles/games.dir/build
.PHONY : games/fast

# target to build an object file
component/Sprite.o:
	$(MAKE) -f CMakeFiles/arcade.dir/build.make CMakeFiles/arcade.dir/component/Sprite.o
	$(MAKE) -f CMakeFiles/units.dir/build.make CMakeFiles/units.dir/component/Sprite.o
.PHONY : component/Sprite.o

# target to preprocess a source file
component/Sprite.i:
	$(MAKE) -f CMakeFiles/arcade.dir/build.make CMakeFiles/arcade.dir/component/Sprite.i
	$(MAKE) -f CMakeFiles/units.dir/build.make CMakeFiles/units.dir/component/Sprite.i
.PHONY : component/Sprite.i

# target to generate assembly for a file
component/Sprite.s:
	$(MAKE) -f CMakeFiles/arcade.dir/build.make CMakeFiles/arcade.dir/component/Sprite.s
	$(MAKE) -f CMakeFiles/units.dir/build.make CMakeFiles/units.dir/component/Sprite.s
.PHONY : component/Sprite.s

# target to build an object file
component/Text.o:
	$(MAKE) -f CMakeFiles/arcade.dir/build.make CMakeFiles/arcade.dir/component/Text.o
	$(MAKE) -f CMakeFiles/units.dir/build.make CMakeFiles/units.dir/component/Text.o
.PHONY : component/Text.o

# target to preprocess a source file
component/Text.i:
	$(MAKE) -f CMakeFiles/arcade.dir/build.make CMakeFiles/arcade.dir/component/Text.i
	$(MAKE) -f CMakeFiles/units.dir/build.make CMakeFiles/units.dir/component/Text.i
.PHONY : component/Text.i

# target to generate assembly for a file
component/Text.s:
	$(MAKE) -f CMakeFiles/arcade.dir/build.make CMakeFiles/arcade.dir/component/Text.s
	$(MAKE) -f CMakeFiles/units.dir/build.make CMakeFiles/units.dir/component/Text.s
.PHONY : component/Text.s

# target to build an object file
games/nibbler/src/Nibbler.o:
	$(MAKE) -f CMakeFiles/units.dir/build.make CMakeFiles/units.dir/games/nibbler/src/Nibbler.o
.PHONY : games/nibbler/src/Nibbler.o

# target to preprocess a source file
games/nibbler/src/Nibbler.i:
	$(MAKE) -f CMakeFiles/units.dir/build.make CMakeFiles/units.dir/games/nibbler/src/Nibbler.i
.PHONY : games/nibbler/src/Nibbler.i

# target to generate assembly for a file
games/nibbler/src/Nibbler.s:
	$(MAKE) -f CMakeFiles/units.dir/build.make CMakeFiles/units.dir/games/nibbler/src/Nibbler.s
.PHONY : games/nibbler/src/Nibbler.s

# target to build an object file
games/nibbler/src/NibblerTest.o:
	$(MAKE) -f CMakeFiles/units.dir/build.make CMakeFiles/units.dir/games/nibbler/src/NibblerTest.o
.PHONY : games/nibbler/src/NibblerTest.o

# target to preprocess a source file
games/nibbler/src/NibblerTest.i:
	$(MAKE) -f CMakeFiles/units.dir/build.make CMakeFiles/units.dir/games/nibbler/src/NibblerTest.i
.PHONY : games/nibbler/src/NibblerTest.i

# target to generate assembly for a file
games/nibbler/src/NibblerTest.s:
	$(MAKE) -f CMakeFiles/units.dir/build.make CMakeFiles/units.dir/games/nibbler/src/NibblerTest.s
.PHONY : games/nibbler/src/NibblerTest.s

# target to build an object file
main.o:
	$(MAKE) -f CMakeFiles/arcade.dir/build.make CMakeFiles/arcade.dir/main.o
.PHONY : main.o

# target to preprocess a source file
main.i:
	$(MAKE) -f CMakeFiles/arcade.dir/build.make CMakeFiles/arcade.dir/main.i
.PHONY : main.i

# target to generate assembly for a file
main.s:
	$(MAKE) -f CMakeFiles/arcade.dir/build.make CMakeFiles/arcade.dir/main.s
.PHONY : main.s

# target to build an object file
src/Process.o:
	$(MAKE) -f CMakeFiles/arcade.dir/build.make CMakeFiles/arcade.dir/src/Process.o
	$(MAKE) -f CMakeFiles/units.dir/build.make CMakeFiles/units.dir/src/Process.o
.PHONY : src/Process.o

# target to preprocess a source file
src/Process.i:
	$(MAKE) -f CMakeFiles/arcade.dir/build.make CMakeFiles/arcade.dir/src/Process.i
	$(MAKE) -f CMakeFiles/units.dir/build.make CMakeFiles/units.dir/src/Process.i
.PHONY : src/Process.i

# target to generate assembly for a file
src/Process.s:
	$(MAKE) -f CMakeFiles/arcade.dir/build.make CMakeFiles/arcade.dir/src/Process.s
	$(MAKE) -f CMakeFiles/units.dir/build.make CMakeFiles/units.dir/src/Process.s
.PHONY : src/Process.s

# target to build an object file
src/library/LibraryLoader.o:
	$(MAKE) -f CMakeFiles/arcade.dir/build.make CMakeFiles/arcade.dir/src/library/LibraryLoader.o
	$(MAKE) -f CMakeFiles/units.dir/build.make CMakeFiles/units.dir/src/library/LibraryLoader.o
.PHONY : src/library/LibraryLoader.o

# target to preprocess a source file
src/library/LibraryLoader.i:
	$(MAKE) -f CMakeFiles/arcade.dir/build.make CMakeFiles/arcade.dir/src/library/LibraryLoader.i
	$(MAKE) -f CMakeFiles/units.dir/build.make CMakeFiles/units.dir/src/library/LibraryLoader.i
.PHONY : src/library/LibraryLoader.i

# target to generate assembly for a file
src/library/LibraryLoader.s:
	$(MAKE) -f CMakeFiles/arcade.dir/build.make CMakeFiles/arcade.dir/src/library/LibraryLoader.s
	$(MAKE) -f CMakeFiles/units.dir/build.make CMakeFiles/units.dir/src/library/LibraryLoader.s
.PHONY : src/library/LibraryLoader.s

# target to build an object file
src/library/LibraryLoaderException.o:
	$(MAKE) -f CMakeFiles/arcade.dir/build.make CMakeFiles/arcade.dir/src/library/LibraryLoaderException.o
	$(MAKE) -f CMakeFiles/units.dir/build.make CMakeFiles/units.dir/src/library/LibraryLoaderException.o
.PHONY : src/library/LibraryLoaderException.o

# target to preprocess a source file
src/library/LibraryLoaderException.i:
	$(MAKE) -f CMakeFiles/arcade.dir/build.make CMakeFiles/arcade.dir/src/library/LibraryLoaderException.i
	$(MAKE) -f CMakeFiles/units.dir/build.make CMakeFiles/units.dir/src/library/LibraryLoaderException.i
.PHONY : src/library/LibraryLoaderException.i

# target to generate assembly for a file
src/library/LibraryLoaderException.s:
	$(MAKE) -f CMakeFiles/arcade.dir/build.make CMakeFiles/arcade.dir/src/library/LibraryLoaderException.s
	$(MAKE) -f CMakeFiles/units.dir/build.make CMakeFiles/units.dir/src/library/LibraryLoaderException.s
.PHONY : src/library/LibraryLoaderException.s

# target to build an object file
src/library/LibraryLoaderTest.o:
	$(MAKE) -f CMakeFiles/units.dir/build.make CMakeFiles/units.dir/src/library/LibraryLoaderTest.o
.PHONY : src/library/LibraryLoaderTest.o

# target to preprocess a source file
src/library/LibraryLoaderTest.i:
	$(MAKE) -f CMakeFiles/units.dir/build.make CMakeFiles/units.dir/src/library/LibraryLoaderTest.i
.PHONY : src/library/LibraryLoaderTest.i

# target to generate assembly for a file
src/library/LibraryLoaderTest.s:
	$(MAKE) -f CMakeFiles/units.dir/build.make CMakeFiles/units.dir/src/library/LibraryLoaderTest.s
.PHONY : src/library/LibraryLoaderTest.s

# target to build an object file
src/menu/MainMenu.o:
	$(MAKE) -f CMakeFiles/arcade.dir/build.make CMakeFiles/arcade.dir/src/menu/MainMenu.o
	$(MAKE) -f CMakeFiles/units.dir/build.make CMakeFiles/units.dir/src/menu/MainMenu.o
.PHONY : src/menu/MainMenu.o

# target to preprocess a source file
src/menu/MainMenu.i:
	$(MAKE) -f CMakeFiles/arcade.dir/build.make CMakeFiles/arcade.dir/src/menu/MainMenu.i
	$(MAKE) -f CMakeFiles/units.dir/build.make CMakeFiles/units.dir/src/menu/MainMenu.i
.PHONY : src/menu/MainMenu.i

# target to generate assembly for a file
src/menu/MainMenu.s:
	$(MAKE) -f CMakeFiles/arcade.dir/build.make CMakeFiles/arcade.dir/src/menu/MainMenu.s
	$(MAKE) -f CMakeFiles/units.dir/build.make CMakeFiles/units.dir/src/menu/MainMenu.s
.PHONY : src/menu/MainMenu.s

# Help Target
help:
	@echo "The following are some of the valid targets for this Makefile:"
	@echo "... all (the default if no target is provided)"
	@echo "... clean"
	@echo "... depend"
	@echo "... rebuild_cache"
	@echo "... edit_cache"
	@echo "... fclean"
	@echo "... arcade"
	@echo "... units"
	@echo "... re"
	@echo "... graphicals"
	@echo "... tests_run"
	@echo "... games"
	@echo "... component/Sprite.o"
	@echo "... component/Sprite.i"
	@echo "... component/Sprite.s"
	@echo "... component/Text.o"
	@echo "... component/Text.i"
	@echo "... component/Text.s"
	@echo "... games/nibbler/src/Nibbler.o"
	@echo "... games/nibbler/src/Nibbler.i"
	@echo "... games/nibbler/src/Nibbler.s"
	@echo "... games/nibbler/src/NibblerTest.o"
	@echo "... games/nibbler/src/NibblerTest.i"
	@echo "... games/nibbler/src/NibblerTest.s"
	@echo "... main.o"
	@echo "... main.i"
	@echo "... main.s"
	@echo "... src/Process.o"
	@echo "... src/Process.i"
	@echo "... src/Process.s"
	@echo "... src/library/LibraryLoader.o"
	@echo "... src/library/LibraryLoader.i"
	@echo "... src/library/LibraryLoader.s"
	@echo "... src/library/LibraryLoaderException.o"
	@echo "... src/library/LibraryLoaderException.i"
	@echo "... src/library/LibraryLoaderException.s"
	@echo "... src/library/LibraryLoaderTest.o"
	@echo "... src/library/LibraryLoaderTest.i"
	@echo "... src/library/LibraryLoaderTest.s"
	@echo "... src/menu/MainMenu.o"
	@echo "... src/menu/MainMenu.i"
	@echo "... src/menu/MainMenu.s"
.PHONY : help



#=============================================================================
# Special targets to cleanup operation of make.

# Special rule to run CMake to check the build system integrity.
# No rule that depends on this can have commands that come from listfiles
# because they might be regenerated.
cmake_check_build_system:
	$(CMAKE_COMMAND) -H$(CMAKE_SOURCE_DIR) -B$(CMAKE_BINARY_DIR) --check-build-system CMakeFiles/Makefile.cmake 0
.PHONY : cmake_check_build_system

