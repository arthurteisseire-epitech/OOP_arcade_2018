cmake_minimum_required(VERSION 3.12)
project(OOP_arcade_2018)

add_compile_options(-Wall -Wextra)
set(CMAKE_CXX_STANDARD 20)

find_package(Qt5Widgets)

set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} ${Qt5Widgets_EXECUTABLE_COMPILE_FLAGS}")

include_directories(src src/library lib/qt lib)

file(GLOB_RECURSE core src/*.cpp main.cpp)
file(GLOB_RECURSE lib lib/*.cpp)
add_executable(${CMAKE_PROJECT_NAME} ${core} ${lib})
target_link_libraries(${CMAKE_PROJECT_NAME} gtest dl Qt5::Widgets)
