cmake_minimum_required(VERSION 3.12)
project(OOP_arcade_2018)

add_compile_options(-Wall -Wextra)
set(CMAKE_CXX_STANDARD 20)

include_directories(src)

file(GLOB_RECURSE sources src/*.cpp)
add_executable(OOP_arcade_2018 ${sources})
target_link_libraries(OOP_arcade_2018 gtest gtest_main gcov)
