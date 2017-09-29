# CMAKE generated file: DO NOT EDIT!
# Generated by "Unix Makefiles" Generator, CMake Version 3.8

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
CMAKE_COMMAND = /Applications/JetBrains/CLion.app/Contents/bin/cmake/bin/cmake

# The command to remove a file.
RM = /Applications/JetBrains/CLion.app/Contents/bin/cmake/bin/cmake -E remove -f

# Escaping for special characters.
EQUALS = =

# The top-level source directory on which CMake was run.
CMAKE_SOURCE_DIR = /Users/fiskie/asteroids

# The top-level build directory on which CMake was run.
CMAKE_BINARY_DIR = /Users/fiskie/asteroids

#=============================================================================
# Targets provided globally by CMake.

# Special rule for the target rebuild_cache
rebuild_cache:
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --cyan "Running CMake to regenerate build system..."
	/Applications/JetBrains/CLion.app/Contents/bin/cmake/bin/cmake -H$(CMAKE_SOURCE_DIR) -B$(CMAKE_BINARY_DIR)
.PHONY : rebuild_cache

# Special rule for the target rebuild_cache
rebuild_cache/fast: rebuild_cache

.PHONY : rebuild_cache/fast

# Special rule for the target edit_cache
edit_cache:
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --cyan "No interactive CMake dialog available..."
	/Applications/JetBrains/CLion.app/Contents/bin/cmake/bin/cmake -E echo No\ interactive\ CMake\ dialog\ available.
.PHONY : edit_cache

# Special rule for the target edit_cache
edit_cache/fast: edit_cache

.PHONY : edit_cache/fast

# The main all target
all: cmake_check_build_system
	$(CMAKE_COMMAND) -E cmake_progress_start /Users/fiskie/asteroids/CMakeFiles /Users/fiskie/asteroids/CMakeFiles/progress.marks
	$(MAKE) -f CMakeFiles/Makefile2 all
	$(CMAKE_COMMAND) -E cmake_progress_start /Users/fiskie/asteroids/CMakeFiles 0
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
# Target rules for targets named asteroids

# Build rule for target.
asteroids: cmake_check_build_system
	$(MAKE) -f CMakeFiles/Makefile2 asteroids
.PHONY : asteroids

# fast build rule for target.
asteroids/fast:
	$(MAKE) -f CMakeFiles/asteroids.dir/build.make CMakeFiles/asteroids.dir/build
.PHONY : asteroids/fast

src/Asteroids.o: src/Asteroids.cpp.o

.PHONY : src/Asteroids.o

# target to build an object file
src/Asteroids.cpp.o:
	$(MAKE) -f CMakeFiles/asteroids.dir/build.make CMakeFiles/asteroids.dir/src/Asteroids.cpp.o
.PHONY : src/Asteroids.cpp.o

src/Asteroids.i: src/Asteroids.cpp.i

.PHONY : src/Asteroids.i

# target to preprocess a source file
src/Asteroids.cpp.i:
	$(MAKE) -f CMakeFiles/asteroids.dir/build.make CMakeFiles/asteroids.dir/src/Asteroids.cpp.i
.PHONY : src/Asteroids.cpp.i

src/Asteroids.s: src/Asteroids.cpp.s

.PHONY : src/Asteroids.s

# target to generate assembly for a file
src/Asteroids.cpp.s:
	$(MAKE) -f CMakeFiles/asteroids.dir/build.make CMakeFiles/asteroids.dir/src/Asteroids.cpp.s
.PHONY : src/Asteroids.cpp.s

src/Collision.o: src/Collision.cpp.o

.PHONY : src/Collision.o

# target to build an object file
src/Collision.cpp.o:
	$(MAKE) -f CMakeFiles/asteroids.dir/build.make CMakeFiles/asteroids.dir/src/Collision.cpp.o
.PHONY : src/Collision.cpp.o

src/Collision.i: src/Collision.cpp.i

.PHONY : src/Collision.i

# target to preprocess a source file
src/Collision.cpp.i:
	$(MAKE) -f CMakeFiles/asteroids.dir/build.make CMakeFiles/asteroids.dir/src/Collision.cpp.i
.PHONY : src/Collision.cpp.i

src/Collision.s: src/Collision.cpp.s

.PHONY : src/Collision.s

# target to generate assembly for a file
src/Collision.cpp.s:
	$(MAKE) -f CMakeFiles/asteroids.dir/build.make CMakeFiles/asteroids.dir/src/Collision.cpp.s
.PHONY : src/Collision.cpp.s

src/Controller.o: src/Controller.cpp.o

.PHONY : src/Controller.o

# target to build an object file
src/Controller.cpp.o:
	$(MAKE) -f CMakeFiles/asteroids.dir/build.make CMakeFiles/asteroids.dir/src/Controller.cpp.o
.PHONY : src/Controller.cpp.o

src/Controller.i: src/Controller.cpp.i

.PHONY : src/Controller.i

# target to preprocess a source file
src/Controller.cpp.i:
	$(MAKE) -f CMakeFiles/asteroids.dir/build.make CMakeFiles/asteroids.dir/src/Controller.cpp.i
.PHONY : src/Controller.cpp.i

src/Controller.s: src/Controller.cpp.s

.PHONY : src/Controller.s

# target to generate assembly for a file
src/Controller.cpp.s:
	$(MAKE) -f CMakeFiles/asteroids.dir/build.make CMakeFiles/asteroids.dir/src/Controller.cpp.s
.PHONY : src/Controller.cpp.s

src/Game.o: src/Game.cpp.o

.PHONY : src/Game.o

# target to build an object file
src/Game.cpp.o:
	$(MAKE) -f CMakeFiles/asteroids.dir/build.make CMakeFiles/asteroids.dir/src/Game.cpp.o
.PHONY : src/Game.cpp.o

src/Game.i: src/Game.cpp.i

.PHONY : src/Game.i

# target to preprocess a source file
src/Game.cpp.i:
	$(MAKE) -f CMakeFiles/asteroids.dir/build.make CMakeFiles/asteroids.dir/src/Game.cpp.i
.PHONY : src/Game.cpp.i

src/Game.s: src/Game.cpp.s

.PHONY : src/Game.s

# target to generate assembly for a file
src/Game.cpp.s:
	$(MAKE) -f CMakeFiles/asteroids.dir/build.make CMakeFiles/asteroids.dir/src/Game.cpp.s
.PHONY : src/Game.cpp.s

src/Player.o: src/Player.cpp.o

.PHONY : src/Player.o

# target to build an object file
src/Player.cpp.o:
	$(MAKE) -f CMakeFiles/asteroids.dir/build.make CMakeFiles/asteroids.dir/src/Player.cpp.o
.PHONY : src/Player.cpp.o

src/Player.i: src/Player.cpp.i

.PHONY : src/Player.i

# target to preprocess a source file
src/Player.cpp.i:
	$(MAKE) -f CMakeFiles/asteroids.dir/build.make CMakeFiles/asteroids.dir/src/Player.cpp.i
.PHONY : src/Player.cpp.i

src/Player.s: src/Player.cpp.s

.PHONY : src/Player.s

# target to generate assembly for a file
src/Player.cpp.s:
	$(MAKE) -f CMakeFiles/asteroids.dir/build.make CMakeFiles/asteroids.dir/src/Player.cpp.s
.PHONY : src/Player.cpp.s

src/PlayerSession.o: src/PlayerSession.cpp.o

.PHONY : src/PlayerSession.o

# target to build an object file
src/PlayerSession.cpp.o:
	$(MAKE) -f CMakeFiles/asteroids.dir/build.make CMakeFiles/asteroids.dir/src/PlayerSession.cpp.o
.PHONY : src/PlayerSession.cpp.o

src/PlayerSession.i: src/PlayerSession.cpp.i

.PHONY : src/PlayerSession.i

# target to preprocess a source file
src/PlayerSession.cpp.i:
	$(MAKE) -f CMakeFiles/asteroids.dir/build.make CMakeFiles/asteroids.dir/src/PlayerSession.cpp.i
.PHONY : src/PlayerSession.cpp.i

src/PlayerSession.s: src/PlayerSession.cpp.s

.PHONY : src/PlayerSession.s

# target to generate assembly for a file
src/PlayerSession.cpp.s:
	$(MAKE) -f CMakeFiles/asteroids.dir/build.make CMakeFiles/asteroids.dir/src/PlayerSession.cpp.s
.PHONY : src/PlayerSession.cpp.s

src/Renderer.o: src/Renderer.cpp.o

.PHONY : src/Renderer.o

# target to build an object file
src/Renderer.cpp.o:
	$(MAKE) -f CMakeFiles/asteroids.dir/build.make CMakeFiles/asteroids.dir/src/Renderer.cpp.o
.PHONY : src/Renderer.cpp.o

src/Renderer.i: src/Renderer.cpp.i

.PHONY : src/Renderer.i

# target to preprocess a source file
src/Renderer.cpp.i:
	$(MAKE) -f CMakeFiles/asteroids.dir/build.make CMakeFiles/asteroids.dir/src/Renderer.cpp.i
.PHONY : src/Renderer.cpp.i

src/Renderer.s: src/Renderer.cpp.s

.PHONY : src/Renderer.s

# target to generate assembly for a file
src/Renderer.cpp.s:
	$(MAKE) -f CMakeFiles/asteroids.dir/build.make CMakeFiles/asteroids.dir/src/Renderer.cpp.s
.PHONY : src/Renderer.cpp.s

src/World.o: src/World.cpp.o

.PHONY : src/World.o

# target to build an object file
src/World.cpp.o:
	$(MAKE) -f CMakeFiles/asteroids.dir/build.make CMakeFiles/asteroids.dir/src/World.cpp.o
.PHONY : src/World.cpp.o

src/World.i: src/World.cpp.i

.PHONY : src/World.i

# target to preprocess a source file
src/World.cpp.i:
	$(MAKE) -f CMakeFiles/asteroids.dir/build.make CMakeFiles/asteroids.dir/src/World.cpp.i
.PHONY : src/World.cpp.i

src/World.s: src/World.cpp.s

.PHONY : src/World.s

# target to generate assembly for a file
src/World.cpp.s:
	$(MAKE) -f CMakeFiles/asteroids.dir/build.make CMakeFiles/asteroids.dir/src/World.cpp.s
.PHONY : src/World.cpp.s

src/entities/Asteroid.o: src/entities/Asteroid.cpp.o

.PHONY : src/entities/Asteroid.o

# target to build an object file
src/entities/Asteroid.cpp.o:
	$(MAKE) -f CMakeFiles/asteroids.dir/build.make CMakeFiles/asteroids.dir/src/entities/Asteroid.cpp.o
.PHONY : src/entities/Asteroid.cpp.o

src/entities/Asteroid.i: src/entities/Asteroid.cpp.i

.PHONY : src/entities/Asteroid.i

# target to preprocess a source file
src/entities/Asteroid.cpp.i:
	$(MAKE) -f CMakeFiles/asteroids.dir/build.make CMakeFiles/asteroids.dir/src/entities/Asteroid.cpp.i
.PHONY : src/entities/Asteroid.cpp.i

src/entities/Asteroid.s: src/entities/Asteroid.cpp.s

.PHONY : src/entities/Asteroid.s

# target to generate assembly for a file
src/entities/Asteroid.cpp.s:
	$(MAKE) -f CMakeFiles/asteroids.dir/build.make CMakeFiles/asteroids.dir/src/entities/Asteroid.cpp.s
.PHONY : src/entities/Asteroid.cpp.s

src/entities/Bullet.o: src/entities/Bullet.cpp.o

.PHONY : src/entities/Bullet.o

# target to build an object file
src/entities/Bullet.cpp.o:
	$(MAKE) -f CMakeFiles/asteroids.dir/build.make CMakeFiles/asteroids.dir/src/entities/Bullet.cpp.o
.PHONY : src/entities/Bullet.cpp.o

src/entities/Bullet.i: src/entities/Bullet.cpp.i

.PHONY : src/entities/Bullet.i

# target to preprocess a source file
src/entities/Bullet.cpp.i:
	$(MAKE) -f CMakeFiles/asteroids.dir/build.make CMakeFiles/asteroids.dir/src/entities/Bullet.cpp.i
.PHONY : src/entities/Bullet.cpp.i

src/entities/Bullet.s: src/entities/Bullet.cpp.s

.PHONY : src/entities/Bullet.s

# target to generate assembly for a file
src/entities/Bullet.cpp.s:
	$(MAKE) -f CMakeFiles/asteroids.dir/build.make CMakeFiles/asteroids.dir/src/entities/Bullet.cpp.s
.PHONY : src/entities/Bullet.cpp.s

src/entities/Ship.o: src/entities/Ship.cpp.o

.PHONY : src/entities/Ship.o

# target to build an object file
src/entities/Ship.cpp.o:
	$(MAKE) -f CMakeFiles/asteroids.dir/build.make CMakeFiles/asteroids.dir/src/entities/Ship.cpp.o
.PHONY : src/entities/Ship.cpp.o

src/entities/Ship.i: src/entities/Ship.cpp.i

.PHONY : src/entities/Ship.i

# target to preprocess a source file
src/entities/Ship.cpp.i:
	$(MAKE) -f CMakeFiles/asteroids.dir/build.make CMakeFiles/asteroids.dir/src/entities/Ship.cpp.i
.PHONY : src/entities/Ship.cpp.i

src/entities/Ship.s: src/entities/Ship.cpp.s

.PHONY : src/entities/Ship.s

# target to generate assembly for a file
src/entities/Ship.cpp.s:
	$(MAKE) -f CMakeFiles/asteroids.dir/build.make CMakeFiles/asteroids.dir/src/entities/Ship.cpp.s
.PHONY : src/entities/Ship.cpp.s

src/entities/ShipWeapon.o: src/entities/ShipWeapon.cpp.o

.PHONY : src/entities/ShipWeapon.o

# target to build an object file
src/entities/ShipWeapon.cpp.o:
	$(MAKE) -f CMakeFiles/asteroids.dir/build.make CMakeFiles/asteroids.dir/src/entities/ShipWeapon.cpp.o
.PHONY : src/entities/ShipWeapon.cpp.o

src/entities/ShipWeapon.i: src/entities/ShipWeapon.cpp.i

.PHONY : src/entities/ShipWeapon.i

# target to preprocess a source file
src/entities/ShipWeapon.cpp.i:
	$(MAKE) -f CMakeFiles/asteroids.dir/build.make CMakeFiles/asteroids.dir/src/entities/ShipWeapon.cpp.i
.PHONY : src/entities/ShipWeapon.cpp.i

src/entities/ShipWeapon.s: src/entities/ShipWeapon.cpp.s

.PHONY : src/entities/ShipWeapon.s

# target to generate assembly for a file
src/entities/ShipWeapon.cpp.s:
	$(MAKE) -f CMakeFiles/asteroids.dir/build.make CMakeFiles/asteroids.dir/src/entities/ShipWeapon.cpp.s
.PHONY : src/entities/ShipWeapon.cpp.s

src/entities/WorldObject.o: src/entities/WorldObject.cpp.o

.PHONY : src/entities/WorldObject.o

# target to build an object file
src/entities/WorldObject.cpp.o:
	$(MAKE) -f CMakeFiles/asteroids.dir/build.make CMakeFiles/asteroids.dir/src/entities/WorldObject.cpp.o
.PHONY : src/entities/WorldObject.cpp.o

src/entities/WorldObject.i: src/entities/WorldObject.cpp.i

.PHONY : src/entities/WorldObject.i

# target to preprocess a source file
src/entities/WorldObject.cpp.i:
	$(MAKE) -f CMakeFiles/asteroids.dir/build.make CMakeFiles/asteroids.dir/src/entities/WorldObject.cpp.i
.PHONY : src/entities/WorldObject.cpp.i

src/entities/WorldObject.s: src/entities/WorldObject.cpp.s

.PHONY : src/entities/WorldObject.s

# target to generate assembly for a file
src/entities/WorldObject.cpp.s:
	$(MAKE) -f CMakeFiles/asteroids.dir/build.make CMakeFiles/asteroids.dir/src/entities/WorldObject.cpp.s
.PHONY : src/entities/WorldObject.cpp.s

src/main.o: src/main.cpp.o

.PHONY : src/main.o

# target to build an object file
src/main.cpp.o:
	$(MAKE) -f CMakeFiles/asteroids.dir/build.make CMakeFiles/asteroids.dir/src/main.cpp.o
.PHONY : src/main.cpp.o

src/main.i: src/main.cpp.i

.PHONY : src/main.i

# target to preprocess a source file
src/main.cpp.i:
	$(MAKE) -f CMakeFiles/asteroids.dir/build.make CMakeFiles/asteroids.dir/src/main.cpp.i
.PHONY : src/main.cpp.i

src/main.s: src/main.cpp.s

.PHONY : src/main.s

# target to generate assembly for a file
src/main.cpp.s:
	$(MAKE) -f CMakeFiles/asteroids.dir/build.make CMakeFiles/asteroids.dir/src/main.cpp.s
.PHONY : src/main.cpp.s

src/scenes/GameScene.o: src/scenes/GameScene.cpp.o

.PHONY : src/scenes/GameScene.o

# target to build an object file
src/scenes/GameScene.cpp.o:
	$(MAKE) -f CMakeFiles/asteroids.dir/build.make CMakeFiles/asteroids.dir/src/scenes/GameScene.cpp.o
.PHONY : src/scenes/GameScene.cpp.o

src/scenes/GameScene.i: src/scenes/GameScene.cpp.i

.PHONY : src/scenes/GameScene.i

# target to preprocess a source file
src/scenes/GameScene.cpp.i:
	$(MAKE) -f CMakeFiles/asteroids.dir/build.make CMakeFiles/asteroids.dir/src/scenes/GameScene.cpp.i
.PHONY : src/scenes/GameScene.cpp.i

src/scenes/GameScene.s: src/scenes/GameScene.cpp.s

.PHONY : src/scenes/GameScene.s

# target to generate assembly for a file
src/scenes/GameScene.cpp.s:
	$(MAKE) -f CMakeFiles/asteroids.dir/build.make CMakeFiles/asteroids.dir/src/scenes/GameScene.cpp.s
.PHONY : src/scenes/GameScene.cpp.s

src/scenes/IScene.o: src/scenes/IScene.cpp.o

.PHONY : src/scenes/IScene.o

# target to build an object file
src/scenes/IScene.cpp.o:
	$(MAKE) -f CMakeFiles/asteroids.dir/build.make CMakeFiles/asteroids.dir/src/scenes/IScene.cpp.o
.PHONY : src/scenes/IScene.cpp.o

src/scenes/IScene.i: src/scenes/IScene.cpp.i

.PHONY : src/scenes/IScene.i

# target to preprocess a source file
src/scenes/IScene.cpp.i:
	$(MAKE) -f CMakeFiles/asteroids.dir/build.make CMakeFiles/asteroids.dir/src/scenes/IScene.cpp.i
.PHONY : src/scenes/IScene.cpp.i

src/scenes/IScene.s: src/scenes/IScene.cpp.s

.PHONY : src/scenes/IScene.s

# target to generate assembly for a file
src/scenes/IScene.cpp.s:
	$(MAKE) -f CMakeFiles/asteroids.dir/build.make CMakeFiles/asteroids.dir/src/scenes/IScene.cpp.s
.PHONY : src/scenes/IScene.cpp.s

src/scenes/MainMenu.o: src/scenes/MainMenu.cpp.o

.PHONY : src/scenes/MainMenu.o

# target to build an object file
src/scenes/MainMenu.cpp.o:
	$(MAKE) -f CMakeFiles/asteroids.dir/build.make CMakeFiles/asteroids.dir/src/scenes/MainMenu.cpp.o
.PHONY : src/scenes/MainMenu.cpp.o

src/scenes/MainMenu.i: src/scenes/MainMenu.cpp.i

.PHONY : src/scenes/MainMenu.i

# target to preprocess a source file
src/scenes/MainMenu.cpp.i:
	$(MAKE) -f CMakeFiles/asteroids.dir/build.make CMakeFiles/asteroids.dir/src/scenes/MainMenu.cpp.i
.PHONY : src/scenes/MainMenu.cpp.i

src/scenes/MainMenu.s: src/scenes/MainMenu.cpp.s

.PHONY : src/scenes/MainMenu.s

# target to generate assembly for a file
src/scenes/MainMenu.cpp.s:
	$(MAKE) -f CMakeFiles/asteroids.dir/build.make CMakeFiles/asteroids.dir/src/scenes/MainMenu.cpp.s
.PHONY : src/scenes/MainMenu.cpp.s

# Help Target
help:
	@echo "The following are some of the valid targets for this Makefile:"
	@echo "... all (the default if no target is provided)"
	@echo "... clean"
	@echo "... depend"
	@echo "... rebuild_cache"
	@echo "... edit_cache"
	@echo "... asteroids"
	@echo "... src/Asteroids.o"
	@echo "... src/Asteroids.i"
	@echo "... src/Asteroids.s"
	@echo "... src/Collision.o"
	@echo "... src/Collision.i"
	@echo "... src/Collision.s"
	@echo "... src/Controller.o"
	@echo "... src/Controller.i"
	@echo "... src/Controller.s"
	@echo "... src/Game.o"
	@echo "... src/Game.i"
	@echo "... src/Game.s"
	@echo "... src/Player.o"
	@echo "... src/Player.i"
	@echo "... src/Player.s"
	@echo "... src/PlayerSession.o"
	@echo "... src/PlayerSession.i"
	@echo "... src/PlayerSession.s"
	@echo "... src/Renderer.o"
	@echo "... src/Renderer.i"
	@echo "... src/Renderer.s"
	@echo "... src/World.o"
	@echo "... src/World.i"
	@echo "... src/World.s"
	@echo "... src/entities/Asteroid.o"
	@echo "... src/entities/Asteroid.i"
	@echo "... src/entities/Asteroid.s"
	@echo "... src/entities/Bullet.o"
	@echo "... src/entities/Bullet.i"
	@echo "... src/entities/Bullet.s"
	@echo "... src/entities/Ship.o"
	@echo "... src/entities/Ship.i"
	@echo "... src/entities/Ship.s"
	@echo "... src/entities/ShipWeapon.o"
	@echo "... src/entities/ShipWeapon.i"
	@echo "... src/entities/ShipWeapon.s"
	@echo "... src/entities/WorldObject.o"
	@echo "... src/entities/WorldObject.i"
	@echo "... src/entities/WorldObject.s"
	@echo "... src/main.o"
	@echo "... src/main.i"
	@echo "... src/main.s"
	@echo "... src/scenes/GameScene.o"
	@echo "... src/scenes/GameScene.i"
	@echo "... src/scenes/GameScene.s"
	@echo "... src/scenes/IScene.o"
	@echo "... src/scenes/IScene.i"
	@echo "... src/scenes/IScene.s"
	@echo "... src/scenes/MainMenu.o"
	@echo "... src/scenes/MainMenu.i"
	@echo "... src/scenes/MainMenu.s"
.PHONY : help



#=============================================================================
# Special targets to cleanup operation of make.

# Special rule to run CMake to check the build system integrity.
# No rule that depends on this can have commands that come from listfiles
# because they might be regenerated.
cmake_check_build_system:
	$(CMAKE_COMMAND) -H$(CMAKE_SOURCE_DIR) -B$(CMAKE_BINARY_DIR) --check-build-system CMakeFiles/Makefile.cmake 0
.PHONY : cmake_check_build_system

