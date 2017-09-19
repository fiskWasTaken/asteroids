cmake_minimum_required(VERSION 3.7)
set(PROJECT_NAME_STR sfml_sandbox)
project(${PROJECT_NAME_STR})
set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -std=c++11")

find_package(Threads REQUIRED)
find_package(GTest REQUIRED)
include_directories(${GTEST_INCLUDE_DIRS})

if(NOT MSVC)
    set(PThreadLib -pthread)
endif()

set(SOURCE_FILES src/main.cpp src/GameBoard.cpp src/GameBoard.h src/GamePiece.cpp src/GamePiece.h)
add_executable(${PROJECT_NAME_STR} ${SOURCE_FILES})

set(CMAKE_MODULE_PATH "${CMAKE_CURRENT_LIST_DIR}/cmake_modules")
find_package(SFML REQUIRED system window graphics network audio)

if (SFML_FOUND)
    include_directories(${SFML_INCLUDE_DIR})
    target_link_libraries(${PROJECT_NAME_STR} ${SFML_LIBRARIES})
endif()

# Testing
enable_testing()
add_executable(${PROJECT_NAME_STR}_test test/sfml_sandbox_tests.cpp)
include_directories(${PROJECT_SOURCE_DIR}/src)
target_link_libraries(${PROJECT_NAME_STR}_test ${PThreadLib} ${GTEST_BOTH_LIBRARIES})