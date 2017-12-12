cmake_minimum_required(VERSION 3.7)
set(PROJECT_NAME_STR asteroids)
project(${PROJECT_NAME_STR})
set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -std=c++1z")

set(CMAKE_MODULE_PATH "${CMAKE_CURRENT_LIST_DIR}/cmake_modules")
find_package(SFML REQUIRED system window graphics network audio)
find_package(OpenGL REQUIRED)
find_package(GTest)

include_directories(${GTEST_INCLUDE_DIRS} ${OPENGL_INCLUDE_DIRS})

if(NOT MSVC)
    set(PThreadLib -pthread)
endif()

set(SOURCE_FILES src/main.cpp src/GameInterface.cpp src/GameInterface.h src/renderer/WindowRenderer.cpp src/renderer/WindowRenderer.h src/entities/Ship.cpp src/entities/Ship.h src/entities/asteroids/LargeAsteroid.cpp src/entities/asteroids/LargeAsteroid.h src/entities/AbstractWorldObject.h src/player/Player.h src/scenes/SceneInterface.h src/scenes/MainMenuScene.cpp src/scenes/MainMenuScene.h src/scenes/GameScene.cpp src/scenes/GameScene.h src/player/PlayerSession.cpp src/player/PlayerSession.h src/input/ControllerInterface.h src/entities/Bullet.cpp src/entities/Bullet.h src/world/World.cpp src/world/World.h src/Asteroids.cpp src/Asteroids.h src/entities/WorldObjectClass.h src/collision/CollisionModelInterface.h src/input/InputAction.h src/input/KeyboardController.cpp src/input/KeyboardController.h src/input/ControllerListenerInterface.h src/scenes/GameOverScene.cpp src/scenes/GameOverScene.h src/scenes/HighScoreTableScene.cpp src/scenes/HighScoreTableScene.h src/HighScores.h src/entities/WorldObjectInterface.h src/utility/vector.cpp src/utility/vector.h src/collision/SATCollisionModel.cpp src/collision/SATCollisionModel.h src/world/WorldInterface.h src/renderer/WindowRendererInterface.h src/utility/drawing.cpp src/utility/drawing.h src/entities/asteroids/AsteroidBase.cpp src/entities/asteroids/AsteroidBase.h src/entities/asteroids/MediumAsteroid.cpp src/entities/asteroids/MediumAsteroid.h src/entities/asteroids/SmallAsteroid.cpp src/entities/asteroids/SmallAsteroid.h src/collision/collision_result_t.h src/levels/level_t.h src/levels/Playlist.cpp src/levels/Playlist.h src/levels/LevelLoader.cpp src/levels/LevelLoader.h src/renderer/WorldRenderer.cpp src/renderer/WorldRenderer.h)
add_executable(${PROJECT_NAME_STR} ${SOURCE_FILES})

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