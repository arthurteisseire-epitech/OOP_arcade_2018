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
CMAKE_COMMAND = /usr/bin/cmake

# The command to remove a file.
RM = /usr/bin/cmake -E remove -f

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
	/usr/bin/cmake -S$(CMAKE_SOURCE_DIR) -B$(CMAKE_BINARY_DIR)
.PHONY : rebuild_cache

# Special rule for the target rebuild_cache
rebuild_cache/fast: rebuild_cache

.PHONY : rebuild_cache/fast

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

lib/qt/Graphic.o: lib/qt/Graphic.cpp.o

.PHONY : lib/qt/Graphic.o

# target to build an object file
lib/qt/Graphic.cpp.o:
	$(MAKE) -f CMakeFiles/arcade.dir/build.make CMakeFiles/arcade.dir/lib/qt/Graphic.cpp.o
.PHONY : lib/qt/Graphic.cpp.o

lib/qt/Graphic.i: lib/qt/Graphic.cpp.i

.PHONY : lib/qt/Graphic.i

# target to preprocess a source file
lib/qt/Graphic.cpp.i:
	$(MAKE) -f CMakeFiles/arcade.dir/build.make CMakeFiles/arcade.dir/lib/qt/Graphic.cpp.i
.PHONY : lib/qt/Graphic.cpp.i

lib/qt/Graphic.s: lib/qt/Graphic.cpp.s

.PHONY : lib/qt/Graphic.s

# target to generate assembly for a file
lib/qt/Graphic.cpp.s:
	$(MAKE) -f CMakeFiles/arcade.dir/build.make CMakeFiles/arcade.dir/lib/qt/Graphic.cpp.s
.PHONY : lib/qt/Graphic.cpp.s

main.o: main.cpp.o

.PHONY : main.o

# target to build an object file
main.cpp.o:
	$(MAKE) -f CMakeFiles/arcade.dir/build.make CMakeFiles/arcade.dir/main.cpp.o
.PHONY : main.cpp.o

main.i: main.cpp.i

.PHONY : main.i

# target to preprocess a source file
main.cpp.i:
	$(MAKE) -f CMakeFiles/arcade.dir/build.make CMakeFiles/arcade.dir/main.cpp.i
.PHONY : main.cpp.i

main.s: main.cpp.s

.PHONY : main.s

# target to generate assembly for a file
main.cpp.s:
	$(MAKE) -f CMakeFiles/arcade.dir/build.make CMakeFiles/arcade.dir/main.cpp.s
.PHONY : main.cpp.s

src/library/LibraryLoader.o: src/library/LibraryLoader.cpp.o

.PHONY : src/library/LibraryLoader.o

# target to build an object file
src/library/LibraryLoader.cpp.o:
	$(MAKE) -f CMakeFiles/arcade.dir/build.make CMakeFiles/arcade.dir/src/library/LibraryLoader.cpp.o
.PHONY : src/library/LibraryLoader.cpp.o

src/library/LibraryLoader.i: src/library/LibraryLoader.cpp.i

.PHONY : src/library/LibraryLoader.i

# target to preprocess a source file
src/library/LibraryLoader.cpp.i:
	$(MAKE) -f CMakeFiles/arcade.dir/build.make CMakeFiles/arcade.dir/src/library/LibraryLoader.cpp.i
.PHONY : src/library/LibraryLoader.cpp.i

src/library/LibraryLoader.s: src/library/LibraryLoader.cpp.s

.PHONY : src/library/LibraryLoader.s

# target to generate assembly for a file
src/library/LibraryLoader.cpp.s:
	$(MAKE) -f CMakeFiles/arcade.dir/build.make CMakeFiles/arcade.dir/src/library/LibraryLoader.cpp.s
.PHONY : src/library/LibraryLoader.cpp.s

src/library/LibraryLoaderException.o: src/library/LibraryLoaderException.cpp.o

.PHONY : src/library/LibraryLoaderException.o

# target to build an object file
src/library/LibraryLoaderException.cpp.o:
	$(MAKE) -f CMakeFiles/arcade.dir/build.make CMakeFiles/arcade.dir/src/library/LibraryLoaderException.cpp.o
.PHONY : src/library/LibraryLoaderException.cpp.o

src/library/LibraryLoaderException.i: src/library/LibraryLoaderException.cpp.i

.PHONY : src/library/LibraryLoaderException.i

# target to preprocess a source file
src/library/LibraryLoaderException.cpp.i:
	$(MAKE) -f CMakeFiles/arcade.dir/build.make CMakeFiles/arcade.dir/src/library/LibraryLoaderException.cpp.i
.PHONY : src/library/LibraryLoaderException.cpp.i

src/library/LibraryLoaderException.s: src/library/LibraryLoaderException.cpp.s

.PHONY : src/library/LibraryLoaderException.s

# target to generate assembly for a file
src/library/LibraryLoaderException.cpp.s:
	$(MAKE) -f CMakeFiles/arcade.dir/build.make CMakeFiles/arcade.dir/src/library/LibraryLoaderException.cpp.s
.PHONY : src/library/LibraryLoaderException.cpp.s

src/library/LibraryLoaderTest.o: src/library/LibraryLoaderTest.cpp.o

.PHONY : src/library/LibraryLoaderTest.o

# target to build an object file
src/library/LibraryLoaderTest.cpp.o:
	$(MAKE) -f CMakeFiles/arcade.dir/build.make CMakeFiles/arcade.dir/src/library/LibraryLoaderTest.cpp.o
.PHONY : src/library/LibraryLoaderTest.cpp.o

src/library/LibraryLoaderTest.i: src/library/LibraryLoaderTest.cpp.i

.PHONY : src/library/LibraryLoaderTest.i

# target to preprocess a source file
src/library/LibraryLoaderTest.cpp.i:
	$(MAKE) -f CMakeFiles/arcade.dir/build.make CMakeFiles/arcade.dir/src/library/LibraryLoaderTest.cpp.i
.PHONY : src/library/LibraryLoaderTest.cpp.i

src/library/LibraryLoaderTest.s: src/library/LibraryLoaderTest.cpp.s

.PHONY : src/library/LibraryLoaderTest.s

# target to generate assembly for a file
src/library/LibraryLoaderTest.cpp.s:
	$(MAKE) -f CMakeFiles/arcade.dir/build.make CMakeFiles/arcade.dir/src/library/LibraryLoaderTest.cpp.s
.PHONY : src/library/LibraryLoaderTest.cpp.s

# Help Target
help:
	@echo "The following are some of the valid targets for this Makefile:"
	@echo "... all (the default if no target is provided)"
	@echo "... clean"
	@echo "... depend"
	@echo "... rebuild_cache"
	@echo "... edit_cache"
	@echo "... fclean"
	@echo "... re"
	@echo "... arcade"
	@echo "... graphicals"
	@echo "... lib/qt/Graphic.o"
	@echo "... lib/qt/Graphic.i"
	@echo "... lib/qt/Graphic.s"
	@echo "... main.o"
	@echo "... main.i"
	@echo "... main.s"
	@echo "... src/library/LibraryLoader.o"
	@echo "... src/library/LibraryLoader.i"
	@echo "... src/library/LibraryLoader.s"
	@echo "... src/library/LibraryLoaderException.o"
	@echo "... src/library/LibraryLoaderException.i"
	@echo "... src/library/LibraryLoaderException.s"
	@echo "... src/library/LibraryLoaderTest.o"
	@echo "... src/library/LibraryLoaderTest.i"
	@echo "... src/library/LibraryLoaderTest.s"
.PHONY : help



#=============================================================================
# Special targets to cleanup operation of make.

# Special rule to run CMake to check the build system integrity.
# No rule that depends on this can have commands that come from listfiles
# because they might be regenerated.
cmake_check_build_system:
	$(CMAKE_COMMAND) -S$(CMAKE_SOURCE_DIR) -B$(CMAKE_BINARY_DIR) --check-build-system CMakeFiles/Makefile.cmake 0
.PHONY : cmake_check_build_system

