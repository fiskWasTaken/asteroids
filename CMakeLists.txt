cmake_minimum_required(VERSION 3.7)
set(PROJECT_NAME_STR asteroids)
project(${PROJECT_NAME_STR})
set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -std=c++1z")

set(CMAKE_MODULE_PATH "${CMAKE_CURRENT_LIST_DIR}/cmake_modules")
find_package(SFML REQUIRED system window graphics)
find_package(OpenGL REQUIRED)

include_directories(${PROJECT_SOURCE_DIR}/src)
include_directories(${OPENGL_INCLUDE_DIRS})

file(GLOB_RECURSE source_list "src/**.cpp" "src/**.h")
add_executable(${PROJECT_NAME_STR} ${source_list})

include_directories(${SFML_INCLUDE_DIR})
target_link_libraries(${PROJECT_NAME_STR} ${SFML_LIBRARIES} ${OPENGL_LIBRARIES})