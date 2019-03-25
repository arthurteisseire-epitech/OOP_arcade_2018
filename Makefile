# CMAKE generated file: DO NOT EDIT!
# Generated by "Unix Makefiles" Generator, CMake Version 3.13

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
CMAKE_COMMAND = /home/arthur/app/clion/bin/cmake/linux/bin/cmake

# The command to remove a file.
RM = /home/arthur/app/clion/bin/cmake/linux/bin/cmake -E remove -f

# Escaping for special characters.
EQUALS = =

# The top-level source directory on which CMake was run.
CMAKE_SOURCE_DIR = /home/arthur/epitech/2018/OOP/OOP_arcade_2018

# The top-level build directory on which CMake was run.
CMAKE_BINARY_DIR = /home/arthur/epitech/2018/OOP/OOP_arcade_2018

#=============================================================================
# Targets provided globally by CMake.

# Special rule for the target rebuild_cache
rebuild_cache:
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --cyan "Running CMake to regenerate build system..."
	/home/arthur/app/clion/bin/cmake/linux/bin/cmake -S$(CMAKE_SOURCE_DIR) -B$(CMAKE_BINARY_DIR)
.PHONY : rebuild_cache

# Special rule for the target rebuild_cache
rebuild_cache/fast: rebuild_cache

.PHONY : rebuild_cache/fast

# Special rule for the target test
test:
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --cyan "Running tests..."
	/home/arthur/app/clion/bin/cmake/linux/bin/ctest --force-new-ctest-process $(ARGS)
.PHONY : test

# Special rule for the target test
test/fast: test

.PHONY : test/fast

# Special rule for the target edit_cache
edit_cache:
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --cyan "Running CMake cache editor..."
	/usr/bin/ccmake -S$(CMAKE_SOURCE_DIR) -B$(CMAKE_BINARY_DIR)
.PHONY : edit_cache

# Special rule for the target edit_cache
edit_cache/fast: edit_cache

.PHONY : edit_cache/fast

# The main all target
all: cmake_check_build_system
	$(CMAKE_COMMAND) -E cmake_progress_start /home/arthur/epitech/2018/OOP/OOP_arcade_2018/CMakeFiles /home/arthur/epitech/2018/OOP/OOP_arcade_2018/CMakeFiles/progress.marks
	$(MAKE) -f CMakeFiles/Makefile2 all
	$(CMAKE_COMMAND) -E cmake_progress_start /home/arthur/epitech/2018/OOP/OOP_arcade_2018/CMakeFiles 0
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
	$(CMAKE_COMMAND) -S$(CMAKE_SOURCE_DIR) -B$(CMAKE_BINARY_DIR) --check-build-system CMakeFiles/Makefile.cmake 1
.PHONY : depend

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
# Target rules for targets named games

# Build rule for target.
games: cmake_check_build_system
	$(MAKE) -f CMakeFiles/Makefile2 games
.PHONY : games

# fast build rule for target.
games/fast:
	$(MAKE) -f CMakeFiles/games.dir/build.make CMakeFiles/games.dir/build
.PHONY : games/fast

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
# Target rules for targets named tests_run

# Build rule for target.
tests_run: cmake_check_build_system
	$(MAKE) -f CMakeFiles/Makefile2 tests_run
.PHONY : tests_run

# fast build rule for target.
tests_run/fast:
	$(MAKE) -f CMakeFiles/tests_run.dir/build.make CMakeFiles/tests_run.dir/build
.PHONY : tests_run/fast

# target to build an object file
component/Audio.o:
	$(MAKE) -f CMakeFiles/units.dir/build.make CMakeFiles/units.dir/component/Audio.o
	$(MAKE) -f CMakeFiles/arcade.dir/build.make CMakeFiles/arcade.dir/component/Audio.o
.PHONY : component/Audio.o

# target to preprocess a source file
component/Audio.i:
	$(MAKE) -f CMakeFiles/units.dir/build.make CMakeFiles/units.dir/component/Audio.i
	$(MAKE) -f CMakeFiles/arcade.dir/build.make CMakeFiles/arcade.dir/component/Audio.i
.PHONY : component/Audio.i

# target to generate assembly for a file
component/Audio.s:
	$(MAKE) -f CMakeFiles/units.dir/build.make CMakeFiles/units.dir/component/Audio.s
	$(MAKE) -f CMakeFiles/arcade.dir/build.make CMakeFiles/arcade.dir/component/Audio.s
.PHONY : component/Audio.s

# target to build an object file
component/Sprite.o:
	$(MAKE) -f CMakeFiles/units.dir/build.make CMakeFiles/units.dir/component/Sprite.o
	$(MAKE) -f CMakeFiles/arcade.dir/build.make CMakeFiles/arcade.dir/component/Sprite.o
.PHONY : component/Sprite.o

# target to preprocess a source file
component/Sprite.i:
	$(MAKE) -f CMakeFiles/units.dir/build.make CMakeFiles/units.dir/component/Sprite.i
	$(MAKE) -f CMakeFiles/arcade.dir/build.make CMakeFiles/arcade.dir/component/Sprite.i
.PHONY : component/Sprite.i

# target to generate assembly for a file
component/Sprite.s:
	$(MAKE) -f CMakeFiles/units.dir/build.make CMakeFiles/units.dir/component/Sprite.s
	$(MAKE) -f CMakeFiles/arcade.dir/build.make CMakeFiles/arcade.dir/component/Sprite.s
.PHONY : component/Sprite.s

# target to build an object file
component/Text.o:
	$(MAKE) -f CMakeFiles/units.dir/build.make CMakeFiles/units.dir/component/Text.o
	$(MAKE) -f CMakeFiles/arcade.dir/build.make CMakeFiles/arcade.dir/component/Text.o
.PHONY : component/Text.o

# target to preprocess a source file
component/Text.i:
	$(MAKE) -f CMakeFiles/units.dir/build.make CMakeFiles/units.dir/component/Text.i
	$(MAKE) -f CMakeFiles/arcade.dir/build.make CMakeFiles/arcade.dir/component/Text.i
.PHONY : component/Text.i

# target to generate assembly for a file
component/Text.s:
	$(MAKE) -f CMakeFiles/units.dir/build.make CMakeFiles/units.dir/component/Text.s
	$(MAKE) -f CMakeFiles/arcade.dir/build.make CMakeFiles/arcade.dir/component/Text.s
.PHONY : component/Text.s

# target to build an object file
games/qix/src/Cell.o:
	$(MAKE) -f CMakeFiles/units.dir/build.make CMakeFiles/units.dir/games/qix/src/Cell.o
	$(MAKE) -f CMakeFiles/arcade.dir/build.make CMakeFiles/arcade.dir/games/qix/src/Cell.o
.PHONY : games/qix/src/Cell.o

# target to preprocess a source file
games/qix/src/Cell.i:
	$(MAKE) -f CMakeFiles/units.dir/build.make CMakeFiles/units.dir/games/qix/src/Cell.i
	$(MAKE) -f CMakeFiles/arcade.dir/build.make CMakeFiles/arcade.dir/games/qix/src/Cell.i
.PHONY : games/qix/src/Cell.i

# target to generate assembly for a file
games/qix/src/Cell.s:
	$(MAKE) -f CMakeFiles/units.dir/build.make CMakeFiles/units.dir/games/qix/src/Cell.s
	$(MAKE) -f CMakeFiles/arcade.dir/build.make CMakeFiles/arcade.dir/games/qix/src/Cell.s
.PHONY : games/qix/src/Cell.s

# target to build an object file
games/qix/src/CellTest.o:
	$(MAKE) -f CMakeFiles/units.dir/build.make CMakeFiles/units.dir/games/qix/src/CellTest.o
.PHONY : games/qix/src/CellTest.o

# target to preprocess a source file
games/qix/src/CellTest.i:
	$(MAKE) -f CMakeFiles/units.dir/build.make CMakeFiles/units.dir/games/qix/src/CellTest.i
.PHONY : games/qix/src/CellTest.i

# target to generate assembly for a file
games/qix/src/CellTest.s:
	$(MAKE) -f CMakeFiles/units.dir/build.make CMakeFiles/units.dir/games/qix/src/CellTest.s
.PHONY : games/qix/src/CellTest.s

# target to build an object file
games/qix/src/Converter.o:
	$(MAKE) -f CMakeFiles/units.dir/build.make CMakeFiles/units.dir/games/qix/src/Converter.o
	$(MAKE) -f CMakeFiles/arcade.dir/build.make CMakeFiles/arcade.dir/games/qix/src/Converter.o
.PHONY : games/qix/src/Converter.o

# target to preprocess a source file
games/qix/src/Converter.i:
	$(MAKE) -f CMakeFiles/units.dir/build.make CMakeFiles/units.dir/games/qix/src/Converter.i
	$(MAKE) -f CMakeFiles/arcade.dir/build.make CMakeFiles/arcade.dir/games/qix/src/Converter.i
.PHONY : games/qix/src/Converter.i

# target to generate assembly for a file
games/qix/src/Converter.s:
	$(MAKE) -f CMakeFiles/units.dir/build.make CMakeFiles/units.dir/games/qix/src/Converter.s
	$(MAKE) -f CMakeFiles/arcade.dir/build.make CMakeFiles/arcade.dir/games/qix/src/Converter.s
.PHONY : games/qix/src/Converter.s

# target to build an object file
games/qix/src/ConverterTest.o:
	$(MAKE) -f CMakeFiles/units.dir/build.make CMakeFiles/units.dir/games/qix/src/ConverterTest.o
.PHONY : games/qix/src/ConverterTest.o

# target to preprocess a source file
games/qix/src/ConverterTest.i:
	$(MAKE) -f CMakeFiles/units.dir/build.make CMakeFiles/units.dir/games/qix/src/ConverterTest.i
.PHONY : games/qix/src/ConverterTest.i

# target to generate assembly for a file
games/qix/src/ConverterTest.s:
	$(MAKE) -f CMakeFiles/units.dir/build.make CMakeFiles/units.dir/games/qix/src/ConverterTest.s
.PHONY : games/qix/src/ConverterTest.s

# target to build an object file
games/qix/src/Game.o:
	$(MAKE) -f CMakeFiles/units.dir/build.make CMakeFiles/units.dir/games/qix/src/Game.o
	$(MAKE) -f CMakeFiles/arcade.dir/build.make CMakeFiles/arcade.dir/games/qix/src/Game.o
.PHONY : games/qix/src/Game.o

# target to preprocess a source file
games/qix/src/Game.i:
	$(MAKE) -f CMakeFiles/units.dir/build.make CMakeFiles/units.dir/games/qix/src/Game.i
	$(MAKE) -f CMakeFiles/arcade.dir/build.make CMakeFiles/arcade.dir/games/qix/src/Game.i
.PHONY : games/qix/src/Game.i

# target to generate assembly for a file
games/qix/src/Game.s:
	$(MAKE) -f CMakeFiles/units.dir/build.make CMakeFiles/units.dir/games/qix/src/Game.s
	$(MAKE) -f CMakeFiles/arcade.dir/build.make CMakeFiles/arcade.dir/games/qix/src/Game.s
.PHONY : games/qix/src/Game.s

# target to build an object file
games/qix/src/Map.o:
	$(MAKE) -f CMakeFiles/units.dir/build.make CMakeFiles/units.dir/games/qix/src/Map.o
	$(MAKE) -f CMakeFiles/arcade.dir/build.make CMakeFiles/arcade.dir/games/qix/src/Map.o
.PHONY : games/qix/src/Map.o

# target to preprocess a source file
games/qix/src/Map.i:
	$(MAKE) -f CMakeFiles/units.dir/build.make CMakeFiles/units.dir/games/qix/src/Map.i
	$(MAKE) -f CMakeFiles/arcade.dir/build.make CMakeFiles/arcade.dir/games/qix/src/Map.i
.PHONY : games/qix/src/Map.i

# target to generate assembly for a file
games/qix/src/Map.s:
	$(MAKE) -f CMakeFiles/units.dir/build.make CMakeFiles/units.dir/games/qix/src/Map.s
	$(MAKE) -f CMakeFiles/arcade.dir/build.make CMakeFiles/arcade.dir/games/qix/src/Map.s
.PHONY : games/qix/src/Map.s

# target to build an object file
games/qix/src/MapTest.o:
	$(MAKE) -f CMakeFiles/units.dir/build.make CMakeFiles/units.dir/games/qix/src/MapTest.o
.PHONY : games/qix/src/MapTest.o

# target to preprocess a source file
games/qix/src/MapTest.i:
	$(MAKE) -f CMakeFiles/units.dir/build.make CMakeFiles/units.dir/games/qix/src/MapTest.i
.PHONY : games/qix/src/MapTest.i

# target to generate assembly for a file
games/qix/src/MapTest.s:
	$(MAKE) -f CMakeFiles/units.dir/build.make CMakeFiles/units.dir/games/qix/src/MapTest.s
.PHONY : games/qix/src/MapTest.s

# target to build an object file
games/qix/src/Player.o:
	$(MAKE) -f CMakeFiles/units.dir/build.make CMakeFiles/units.dir/games/qix/src/Player.o
	$(MAKE) -f CMakeFiles/arcade.dir/build.make CMakeFiles/arcade.dir/games/qix/src/Player.o
.PHONY : games/qix/src/Player.o

# target to preprocess a source file
games/qix/src/Player.i:
	$(MAKE) -f CMakeFiles/units.dir/build.make CMakeFiles/units.dir/games/qix/src/Player.i
	$(MAKE) -f CMakeFiles/arcade.dir/build.make CMakeFiles/arcade.dir/games/qix/src/Player.i
.PHONY : games/qix/src/Player.i

# target to generate assembly for a file
games/qix/src/Player.s:
	$(MAKE) -f CMakeFiles/units.dir/build.make CMakeFiles/units.dir/games/qix/src/Player.s
	$(MAKE) -f CMakeFiles/arcade.dir/build.make CMakeFiles/arcade.dir/games/qix/src/Player.s
.PHONY : games/qix/src/Player.s

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
src/Core.o:
	$(MAKE) -f CMakeFiles/units.dir/build.make CMakeFiles/units.dir/src/Core.o
	$(MAKE) -f CMakeFiles/arcade.dir/build.make CMakeFiles/arcade.dir/src/Core.o
.PHONY : src/Core.o

# target to preprocess a source file
src/Core.i:
	$(MAKE) -f CMakeFiles/units.dir/build.make CMakeFiles/units.dir/src/Core.i
	$(MAKE) -f CMakeFiles/arcade.dir/build.make CMakeFiles/arcade.dir/src/Core.i
.PHONY : src/Core.i

# target to generate assembly for a file
src/Core.s:
	$(MAKE) -f CMakeFiles/units.dir/build.make CMakeFiles/units.dir/src/Core.s
	$(MAKE) -f CMakeFiles/arcade.dir/build.make CMakeFiles/arcade.dir/src/Core.s
.PHONY : src/Core.s

# target to build an object file
src/Process.o:
	$(MAKE) -f CMakeFiles/units.dir/build.make CMakeFiles/units.dir/src/Process.o
	$(MAKE) -f CMakeFiles/arcade.dir/build.make CMakeFiles/arcade.dir/src/Process.o
.PHONY : src/Process.o

# target to preprocess a source file
src/Process.i:
	$(MAKE) -f CMakeFiles/units.dir/build.make CMakeFiles/units.dir/src/Process.i
	$(MAKE) -f CMakeFiles/arcade.dir/build.make CMakeFiles/arcade.dir/src/Process.i
.PHONY : src/Process.i

# target to generate assembly for a file
src/Process.s:
	$(MAKE) -f CMakeFiles/units.dir/build.make CMakeFiles/units.dir/src/Process.s
	$(MAKE) -f CMakeFiles/arcade.dir/build.make CMakeFiles/arcade.dir/src/Process.s
.PHONY : src/Process.s

# target to build an object file
src/library/LibraryLoader.o:
	$(MAKE) -f CMakeFiles/units.dir/build.make CMakeFiles/units.dir/src/library/LibraryLoader.o
	$(MAKE) -f CMakeFiles/arcade.dir/build.make CMakeFiles/arcade.dir/src/library/LibraryLoader.o
.PHONY : src/library/LibraryLoader.o

# target to preprocess a source file
src/library/LibraryLoader.i:
	$(MAKE) -f CMakeFiles/units.dir/build.make CMakeFiles/units.dir/src/library/LibraryLoader.i
	$(MAKE) -f CMakeFiles/arcade.dir/build.make CMakeFiles/arcade.dir/src/library/LibraryLoader.i
.PHONY : src/library/LibraryLoader.i

# target to generate assembly for a file
src/library/LibraryLoader.s:
	$(MAKE) -f CMakeFiles/units.dir/build.make CMakeFiles/units.dir/src/library/LibraryLoader.s
	$(MAKE) -f CMakeFiles/arcade.dir/build.make CMakeFiles/arcade.dir/src/library/LibraryLoader.s
.PHONY : src/library/LibraryLoader.s

# target to build an object file
src/library/LibraryLoaderException.o:
	$(MAKE) -f CMakeFiles/units.dir/build.make CMakeFiles/units.dir/src/library/LibraryLoaderException.o
	$(MAKE) -f CMakeFiles/arcade.dir/build.make CMakeFiles/arcade.dir/src/library/LibraryLoaderException.o
.PHONY : src/library/LibraryLoaderException.o

# target to preprocess a source file
src/library/LibraryLoaderException.i:
	$(MAKE) -f CMakeFiles/units.dir/build.make CMakeFiles/units.dir/src/library/LibraryLoaderException.i
	$(MAKE) -f CMakeFiles/arcade.dir/build.make CMakeFiles/arcade.dir/src/library/LibraryLoaderException.i
.PHONY : src/library/LibraryLoaderException.i

# target to generate assembly for a file
src/library/LibraryLoaderException.s:
	$(MAKE) -f CMakeFiles/units.dir/build.make CMakeFiles/units.dir/src/library/LibraryLoaderException.s
	$(MAKE) -f CMakeFiles/arcade.dir/build.make CMakeFiles/arcade.dir/src/library/LibraryLoaderException.s
.PHONY : src/library/LibraryLoaderException.s

# target to build an object file
src/scenes/Scene.o:
	$(MAKE) -f CMakeFiles/units.dir/build.make CMakeFiles/units.dir/src/scenes/Scene.o
	$(MAKE) -f CMakeFiles/arcade.dir/build.make CMakeFiles/arcade.dir/src/scenes/Scene.o
.PHONY : src/scenes/Scene.o

# target to preprocess a source file
src/scenes/Scene.i:
	$(MAKE) -f CMakeFiles/units.dir/build.make CMakeFiles/units.dir/src/scenes/Scene.i
	$(MAKE) -f CMakeFiles/arcade.dir/build.make CMakeFiles/arcade.dir/src/scenes/Scene.i
.PHONY : src/scenes/Scene.i

# target to generate assembly for a file
src/scenes/Scene.s:
	$(MAKE) -f CMakeFiles/units.dir/build.make CMakeFiles/units.dir/src/scenes/Scene.s
	$(MAKE) -f CMakeFiles/arcade.dir/build.make CMakeFiles/arcade.dir/src/scenes/Scene.s
.PHONY : src/scenes/Scene.s

# target to build an object file
src/scenes/SceneFactory.o:
	$(MAKE) -f CMakeFiles/units.dir/build.make CMakeFiles/units.dir/src/scenes/SceneFactory.o
	$(MAKE) -f CMakeFiles/arcade.dir/build.make CMakeFiles/arcade.dir/src/scenes/SceneFactory.o
.PHONY : src/scenes/SceneFactory.o

# target to preprocess a source file
src/scenes/SceneFactory.i:
	$(MAKE) -f CMakeFiles/units.dir/build.make CMakeFiles/units.dir/src/scenes/SceneFactory.i
	$(MAKE) -f CMakeFiles/arcade.dir/build.make CMakeFiles/arcade.dir/src/scenes/SceneFactory.i
.PHONY : src/scenes/SceneFactory.i

# target to generate assembly for a file
src/scenes/SceneFactory.s:
	$(MAKE) -f CMakeFiles/units.dir/build.make CMakeFiles/units.dir/src/scenes/SceneFactory.s
	$(MAKE) -f CMakeFiles/arcade.dir/build.make CMakeFiles/arcade.dir/src/scenes/SceneFactory.s
.PHONY : src/scenes/SceneFactory.s

# target to build an object file
src/scenes/SceneManager.o:
	$(MAKE) -f CMakeFiles/units.dir/build.make CMakeFiles/units.dir/src/scenes/SceneManager.o
	$(MAKE) -f CMakeFiles/arcade.dir/build.make CMakeFiles/arcade.dir/src/scenes/SceneManager.o
.PHONY : src/scenes/SceneManager.o

# target to preprocess a source file
src/scenes/SceneManager.i:
	$(MAKE) -f CMakeFiles/units.dir/build.make CMakeFiles/units.dir/src/scenes/SceneManager.i
	$(MAKE) -f CMakeFiles/arcade.dir/build.make CMakeFiles/arcade.dir/src/scenes/SceneManager.i
.PHONY : src/scenes/SceneManager.i

# target to generate assembly for a file
src/scenes/SceneManager.s:
	$(MAKE) -f CMakeFiles/units.dir/build.make CMakeFiles/units.dir/src/scenes/SceneManager.s
	$(MAKE) -f CMakeFiles/arcade.dir/build.make CMakeFiles/arcade.dir/src/scenes/SceneManager.s
.PHONY : src/scenes/SceneManager.s

# target to build an object file
src/scenes/SharedData.o:
	$(MAKE) -f CMakeFiles/units.dir/build.make CMakeFiles/units.dir/src/scenes/SharedData.o
	$(MAKE) -f CMakeFiles/arcade.dir/build.make CMakeFiles/arcade.dir/src/scenes/SharedData.o
.PHONY : src/scenes/SharedData.o

# target to preprocess a source file
src/scenes/SharedData.i:
	$(MAKE) -f CMakeFiles/units.dir/build.make CMakeFiles/units.dir/src/scenes/SharedData.i
	$(MAKE) -f CMakeFiles/arcade.dir/build.make CMakeFiles/arcade.dir/src/scenes/SharedData.i
.PHONY : src/scenes/SharedData.i

# target to generate assembly for a file
src/scenes/SharedData.s:
	$(MAKE) -f CMakeFiles/units.dir/build.make CMakeFiles/units.dir/src/scenes/SharedData.s
	$(MAKE) -f CMakeFiles/arcade.dir/build.make CMakeFiles/arcade.dir/src/scenes/SharedData.s
.PHONY : src/scenes/SharedData.s

# target to build an object file
src/scenes/exit/ExitScene.o:
	$(MAKE) -f CMakeFiles/units.dir/build.make CMakeFiles/units.dir/src/scenes/exit/ExitScene.o
	$(MAKE) -f CMakeFiles/arcade.dir/build.make CMakeFiles/arcade.dir/src/scenes/exit/ExitScene.o
.PHONY : src/scenes/exit/ExitScene.o

# target to preprocess a source file
src/scenes/exit/ExitScene.i:
	$(MAKE) -f CMakeFiles/units.dir/build.make CMakeFiles/units.dir/src/scenes/exit/ExitScene.i
	$(MAKE) -f CMakeFiles/arcade.dir/build.make CMakeFiles/arcade.dir/src/scenes/exit/ExitScene.i
.PHONY : src/scenes/exit/ExitScene.i

# target to generate assembly for a file
src/scenes/exit/ExitScene.s:
	$(MAKE) -f CMakeFiles/units.dir/build.make CMakeFiles/units.dir/src/scenes/exit/ExitScene.s
	$(MAKE) -f CMakeFiles/arcade.dir/build.make CMakeFiles/arcade.dir/src/scenes/exit/ExitScene.s
.PHONY : src/scenes/exit/ExitScene.s

# target to build an object file
src/scenes/game/GameScene.o:
	$(MAKE) -f CMakeFiles/units.dir/build.make CMakeFiles/units.dir/src/scenes/game/GameScene.o
	$(MAKE) -f CMakeFiles/arcade.dir/build.make CMakeFiles/arcade.dir/src/scenes/game/GameScene.o
.PHONY : src/scenes/game/GameScene.o

# target to preprocess a source file
src/scenes/game/GameScene.i:
	$(MAKE) -f CMakeFiles/units.dir/build.make CMakeFiles/units.dir/src/scenes/game/GameScene.i
	$(MAKE) -f CMakeFiles/arcade.dir/build.make CMakeFiles/arcade.dir/src/scenes/game/GameScene.i
.PHONY : src/scenes/game/GameScene.i

# target to generate assembly for a file
src/scenes/game/GameScene.s:
	$(MAKE) -f CMakeFiles/units.dir/build.make CMakeFiles/units.dir/src/scenes/game/GameScene.s
	$(MAKE) -f CMakeFiles/arcade.dir/build.make CMakeFiles/arcade.dir/src/scenes/game/GameScene.s
.PHONY : src/scenes/game/GameScene.s

# target to build an object file
src/scenes/menu/MainMenu.o:
	$(MAKE) -f CMakeFiles/units.dir/build.make CMakeFiles/units.dir/src/scenes/menu/MainMenu.o
	$(MAKE) -f CMakeFiles/arcade.dir/build.make CMakeFiles/arcade.dir/src/scenes/menu/MainMenu.o
.PHONY : src/scenes/menu/MainMenu.o

# target to preprocess a source file
src/scenes/menu/MainMenu.i:
	$(MAKE) -f CMakeFiles/units.dir/build.make CMakeFiles/units.dir/src/scenes/menu/MainMenu.i
	$(MAKE) -f CMakeFiles/arcade.dir/build.make CMakeFiles/arcade.dir/src/scenes/menu/MainMenu.i
.PHONY : src/scenes/menu/MainMenu.i

# target to generate assembly for a file
src/scenes/menu/MainMenu.s:
	$(MAKE) -f CMakeFiles/units.dir/build.make CMakeFiles/units.dir/src/scenes/menu/MainMenu.s
	$(MAKE) -f CMakeFiles/arcade.dir/build.make CMakeFiles/arcade.dir/src/scenes/menu/MainMenu.s
.PHONY : src/scenes/menu/MainMenu.s

# target to build an object file
src/scenes/player_name/Cursor.o:
	$(MAKE) -f CMakeFiles/units.dir/build.make CMakeFiles/units.dir/src/scenes/player_name/Cursor.o
	$(MAKE) -f CMakeFiles/arcade.dir/build.make CMakeFiles/arcade.dir/src/scenes/player_name/Cursor.o
.PHONY : src/scenes/player_name/Cursor.o

# target to preprocess a source file
src/scenes/player_name/Cursor.i:
	$(MAKE) -f CMakeFiles/units.dir/build.make CMakeFiles/units.dir/src/scenes/player_name/Cursor.i
	$(MAKE) -f CMakeFiles/arcade.dir/build.make CMakeFiles/arcade.dir/src/scenes/player_name/Cursor.i
.PHONY : src/scenes/player_name/Cursor.i

# target to generate assembly for a file
src/scenes/player_name/Cursor.s:
	$(MAKE) -f CMakeFiles/units.dir/build.make CMakeFiles/units.dir/src/scenes/player_name/Cursor.s
	$(MAKE) -f CMakeFiles/arcade.dir/build.make CMakeFiles/arcade.dir/src/scenes/player_name/Cursor.s
.PHONY : src/scenes/player_name/Cursor.s

# target to build an object file
src/scenes/player_name/PlayerName.o:
	$(MAKE) -f CMakeFiles/units.dir/build.make CMakeFiles/units.dir/src/scenes/player_name/PlayerName.o
	$(MAKE) -f CMakeFiles/arcade.dir/build.make CMakeFiles/arcade.dir/src/scenes/player_name/PlayerName.o
.PHONY : src/scenes/player_name/PlayerName.o

# target to preprocess a source file
src/scenes/player_name/PlayerName.i:
	$(MAKE) -f CMakeFiles/units.dir/build.make CMakeFiles/units.dir/src/scenes/player_name/PlayerName.i
	$(MAKE) -f CMakeFiles/arcade.dir/build.make CMakeFiles/arcade.dir/src/scenes/player_name/PlayerName.i
.PHONY : src/scenes/player_name/PlayerName.i

# target to generate assembly for a file
src/scenes/player_name/PlayerName.s:
	$(MAKE) -f CMakeFiles/units.dir/build.make CMakeFiles/units.dir/src/scenes/player_name/PlayerName.s
	$(MAKE) -f CMakeFiles/arcade.dir/build.make CMakeFiles/arcade.dir/src/scenes/player_name/PlayerName.s
.PHONY : src/scenes/player_name/PlayerName.s

# target to build an object file
src/scenes/player_name/Row.o:
	$(MAKE) -f CMakeFiles/units.dir/build.make CMakeFiles/units.dir/src/scenes/player_name/Row.o
	$(MAKE) -f CMakeFiles/arcade.dir/build.make CMakeFiles/arcade.dir/src/scenes/player_name/Row.o
.PHONY : src/scenes/player_name/Row.o

# target to preprocess a source file
src/scenes/player_name/Row.i:
	$(MAKE) -f CMakeFiles/units.dir/build.make CMakeFiles/units.dir/src/scenes/player_name/Row.i
	$(MAKE) -f CMakeFiles/arcade.dir/build.make CMakeFiles/arcade.dir/src/scenes/player_name/Row.i
.PHONY : src/scenes/player_name/Row.i

# target to generate assembly for a file
src/scenes/player_name/Row.s:
	$(MAKE) -f CMakeFiles/units.dir/build.make CMakeFiles/units.dir/src/scenes/player_name/Row.s
	$(MAKE) -f CMakeFiles/arcade.dir/build.make CMakeFiles/arcade.dir/src/scenes/player_name/Row.s
.PHONY : src/scenes/player_name/Row.s

# target to build an object file
src/scenes/utils/Button.o:
	$(MAKE) -f CMakeFiles/units.dir/build.make CMakeFiles/units.dir/src/scenes/utils/Button.o
	$(MAKE) -f CMakeFiles/arcade.dir/build.make CMakeFiles/arcade.dir/src/scenes/utils/Button.o
.PHONY : src/scenes/utils/Button.o

# target to preprocess a source file
src/scenes/utils/Button.i:
	$(MAKE) -f CMakeFiles/units.dir/build.make CMakeFiles/units.dir/src/scenes/utils/Button.i
	$(MAKE) -f CMakeFiles/arcade.dir/build.make CMakeFiles/arcade.dir/src/scenes/utils/Button.i
.PHONY : src/scenes/utils/Button.i

# target to generate assembly for a file
src/scenes/utils/Button.s:
	$(MAKE) -f CMakeFiles/units.dir/build.make CMakeFiles/units.dir/src/scenes/utils/Button.s
	$(MAKE) -f CMakeFiles/arcade.dir/build.make CMakeFiles/arcade.dir/src/scenes/utils/Button.s
.PHONY : src/scenes/utils/Button.s

# Help Target
help:
	@echo "The following are some of the valid targets for this Makefile:"
	@echo "... all (the default if no target is provided)"
	@echo "... clean"
	@echo "... depend"
	@echo "... rebuild_cache"
	@echo "... test"
	@echo "... units"
	@echo "... arcade"
	@echo "... graphicals"
	@echo "... re"
	@echo "... games"
	@echo "... edit_cache"
	@echo "... fclean"
	@echo "... tests_run"
	@echo "... component/Audio.o"
	@echo "... component/Audio.i"
	@echo "... component/Audio.s"
	@echo "... component/Sprite.o"
	@echo "... component/Sprite.i"
	@echo "... component/Sprite.s"
	@echo "... component/Text.o"
	@echo "... component/Text.i"
	@echo "... component/Text.s"
	@echo "... games/qix/src/Cell.o"
	@echo "... games/qix/src/Cell.i"
	@echo "... games/qix/src/Cell.s"
	@echo "... games/qix/src/CellTest.o"
	@echo "... games/qix/src/CellTest.i"
	@echo "... games/qix/src/CellTest.s"
	@echo "... games/qix/src/Converter.o"
	@echo "... games/qix/src/Converter.i"
	@echo "... games/qix/src/Converter.s"
	@echo "... games/qix/src/ConverterTest.o"
	@echo "... games/qix/src/ConverterTest.i"
	@echo "... games/qix/src/ConverterTest.s"
	@echo "... games/qix/src/Game.o"
	@echo "... games/qix/src/Game.i"
	@echo "... games/qix/src/Game.s"
	@echo "... games/qix/src/Map.o"
	@echo "... games/qix/src/Map.i"
	@echo "... games/qix/src/Map.s"
	@echo "... games/qix/src/MapTest.o"
	@echo "... games/qix/src/MapTest.i"
	@echo "... games/qix/src/MapTest.s"
	@echo "... games/qix/src/Player.o"
	@echo "... games/qix/src/Player.i"
	@echo "... games/qix/src/Player.s"
	@echo "... main.o"
	@echo "... main.i"
	@echo "... main.s"
	@echo "... src/Core.o"
	@echo "... src/Core.i"
	@echo "... src/Core.s"
	@echo "... src/Process.o"
	@echo "... src/Process.i"
	@echo "... src/Process.s"
	@echo "... src/library/LibraryLoader.o"
	@echo "... src/library/LibraryLoader.i"
	@echo "... src/library/LibraryLoader.s"
	@echo "... src/library/LibraryLoaderException.o"
	@echo "... src/library/LibraryLoaderException.i"
	@echo "... src/library/LibraryLoaderException.s"
	@echo "... src/scenes/Scene.o"
	@echo "... src/scenes/Scene.i"
	@echo "... src/scenes/Scene.s"
	@echo "... src/scenes/SceneFactory.o"
	@echo "... src/scenes/SceneFactory.i"
	@echo "... src/scenes/SceneFactory.s"
	@echo "... src/scenes/SceneManager.o"
	@echo "... src/scenes/SceneManager.i"
	@echo "... src/scenes/SceneManager.s"
	@echo "... src/scenes/SharedData.o"
	@echo "... src/scenes/SharedData.i"
	@echo "... src/scenes/SharedData.s"
	@echo "... src/scenes/exit/ExitScene.o"
	@echo "... src/scenes/exit/ExitScene.i"
	@echo "... src/scenes/exit/ExitScene.s"
	@echo "... src/scenes/game/GameScene.o"
	@echo "... src/scenes/game/GameScene.i"
	@echo "... src/scenes/game/GameScene.s"
	@echo "... src/scenes/menu/MainMenu.o"
	@echo "... src/scenes/menu/MainMenu.i"
	@echo "... src/scenes/menu/MainMenu.s"
	@echo "... src/scenes/player_name/Cursor.o"
	@echo "... src/scenes/player_name/Cursor.i"
	@echo "... src/scenes/player_name/Cursor.s"
	@echo "... src/scenes/player_name/PlayerName.o"
	@echo "... src/scenes/player_name/PlayerName.i"
	@echo "... src/scenes/player_name/PlayerName.s"
	@echo "... src/scenes/player_name/Row.o"
	@echo "... src/scenes/player_name/Row.i"
	@echo "... src/scenes/player_name/Row.s"
	@echo "... src/scenes/utils/Button.o"
	@echo "... src/scenes/utils/Button.i"
	@echo "... src/scenes/utils/Button.s"
.PHONY : help



#=============================================================================
# Special targets to cleanup operation of make.

# Special rule to run CMake to check the build system integrity.
# No rule that depends on this can have commands that come from listfiles
# because they might be regenerated.
cmake_check_build_system:
	$(CMAKE_COMMAND) -S$(CMAKE_SOURCE_DIR) -B$(CMAKE_BINARY_DIR) --check-build-system CMakeFiles/Makefile.cmake 0
.PHONY : cmake_check_build_system

