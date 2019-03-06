cmake_minimum_required(VERSION 3.12)
project(OOP_arcade_2018)

add_compile_options(-Wall -Wextra)
set(CMAKE_CXX_STANDARD 20)

find_package(Qt5Widgets)
find_package(Qt5Charts REQUIRED)

set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} ${Qt5Widgets_EXECUTABLE_COMPILE_FLAGS} ${Qt5Charts_EXECUTABLE_COMPILE_FLAGS}")

include_directories(src src/library)

file(GLOB_RECURSE sources src/*.cpp)
add_executable(${CMAKE_PROJECT_NAME} ${sources})
target_link_libraries(${CMAKE_PROJECT_NAME} gtest gtest_main dl Qt5::Widgets Qt5::Charts)
