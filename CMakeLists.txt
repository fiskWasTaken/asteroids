cmake_minimum_required(VERSION 3.7)
set(PROJECT_NAME_STR asteroids)
project(${PROJECT_NAME_STR})
set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -std=c++17")

find_package(OpenGL REQUIRED)
find_package(Threads REQUIRED)
find_package(GTest REQUIRED)
include_directories(${GTEST_INCLUDE_DIRS} ${OPENGL_INCLUDE_DIRS})

if(NOT MSVC)
    set(PThreadLib -pthread)
endif()

set(SOURCE_FILES src/main.cpp src/Game.cpp src/Game.h src/Renderer.cpp src/Renderer.h src/entities/Ship.cpp src/entities/Ship.h src/entities/Asteroid.cpp src/entities/Asteroid.h src/entities/WorldObject.cpp src/entities/WorldObject.h src/Player.cpp src/Player.h src/scenes/IScene.cpp src/scenes/IScene.h src/scenes/MainMenu.cpp src/scenes/MainMenu.h src/scenes/GameScene.cpp src/scenes/GameScene.h src/PlayerSession.cpp src/PlayerSession.h src/Controller.cpp src/Controller.h src/entities/ShipWeapon.cpp src/entities/ShipWeapon.h src/entities/Bullet.cpp src/entities/Bullet.h src/World.cpp src/World.h src/Asteroids.cpp src/Asteroids.h src/entities/WorldObjectClass.h src/Collision.cpp src/Collision.h)
add_executable(${PROJECT_NAME_STR} ${SOURCE_FILES})

set(CMAKE_MODULE_PATH "${CMAKE_CURRENT_LIST_DIR}/cmake_modules")
find_package(SFML REQUIRED system window graphics network audio)

if (SFML_FOUND)
    include_directories(${SFML_INCLUDE_DIR})
    target_link_libraries(${PROJECT_NAME_STR} ${PThreadLib} ${SFML_LIBRARIES} ${OPENGL_LIBRARIES})
endif()

if (GTEST_FOUND)
    # Testing
    enable_testing()
    add_executable(${PROJECT_NAME_STR}_test test/asteroids_tests.cpp)
    include_directories(${PROJECT_SOURCE_DIR}/src)
    target_link_libraries(${PROJECT_NAME_STR}_test ${PThreadLib} ${GTEST_BOTH_LIBRARIES})
endif()