cmake_minimum_required(VERSION 3.7)
set(PROJECT_NAME_STR asteroids)
project(${PROJECT_NAME_STR})
set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -std=c++1z")

set(CMAKE_MODULE_PATH "${CMAKE_CURRENT_LIST_DIR}/cmake_modules")
find_package(SFML REQUIRED system window graphics)
find_package(OpenGL REQUIRED)

include_directories(${PROJECT_SOURCE_DIR}/src)
include_directories(${OPENGL_INCLUDE_DIRS})

set(SOURCE_FILES src/main.cpp src/GameInterface.cpp src/GameInterface.h src/renderer/WindowRenderer.cpp src/renderer/WindowRenderer.h src/entities/Ship.cpp src/entities/Ship.h src/entities/AbstractWorldObject.h src/player/Player.h src/scenes/SceneInterface.h src/scenes/MainMenuScene.cpp src/scenes/MainMenuScene.h src/scenes/GameScene.cpp src/scenes/GameScene.h src/player/PlayerSession.cpp src/player/PlayerSession.h src/input/ControllerInterface.h src/entities/Bullet.cpp src/entities/Bullet.h src/world/World.cpp src/world/World.h src/Asteroids.cpp src/Asteroids.h src/collision/CollisionModelInterface.h src/input/InputAction.h src/input/KeyboardController.cpp src/input/KeyboardController.h src/input/ControllerListenerInterface.h src/scenes/GameOverScene.cpp src/scenes/GameOverScene.h src/entities/WorldObjectInterface.h src/utility/vector.cpp src/utility/vector.h src/collision/SATCollisionModel.cpp src/collision/SATCollisionModel.h src/world/WorldInterface.h src/renderer/WindowRendererInterface.h src/utility/drawing.cpp src/utility/drawing.h src/collision/collision_result_t.h src/renderer/WorldRenderer.cpp src/renderer/WorldRenderer.h src/input/JoystickController.cpp src/input/JoystickController.h src/input/ControllerManager.h src/input/presets.cpp src/input/presets.h src/entities/Asteroid.cpp src/entities/Asteroid.h src/utility/shape.cpp src/utility/shape.h src/entities/TemporaryParticle.cpp src/entities/TemporaryParticle.h src/scenes/StressTestScene.cpp src/scenes/StressTestScene.h src/input/ControllerManager.cpp src/particles/ParticleSystem.cpp src/particles/ParticleSystem.h src/waves/WaveGenerator.cpp src/waves/WaveGenerator.h src/particles/Randomizer.h)
add_executable(${PROJECT_NAME_STR} ${SOURCE_FILES})

include_directories(${SFML_INCLUDE_DIR})
target_link_libraries(${PROJECT_NAME_STR} ${SFML_LIBRARIES} ${OPENGL_LIBRARIES})