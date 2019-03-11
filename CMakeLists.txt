cmake_minimum_required(VERSION 3.11)
project(arcade)

add_compile_options(-Wall -Wextra)
set(CMAKE_EXE_LINKER_FLAGS ${CMAKE_EXE_LINKER_FLAGS} " --coverage")
set(CMAKE_CXX_STANDARD 11)
set(CMAKE_C_COMPILER "gcc")
set(CMAKE_CXX_COMPILER "g++")

set(CMAKE_CXX_OUTPUT_EXTENSION_REPLACE 1)

find_package(Qt5Widgets)

set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} ${Qt5Widgets_EXECUTABLE_COMPILE_FLAGS}")

include_directories(src/library src/menu lib/qt component src lib .)


file(GLOB_RECURSE main main.cpp)
file(GLOB_RECURSE core src/*.cpp)
file(GLOB_RECURSE component component/*.cpp)
list(FILTER core EXCLUDE REGEX ".*Test.cpp$")

file(GLOB_RECURSE lib lib/*.cpp)
file(GLOB_RECURSE tests src/*Test.cpp)


add_executable(units ${core} ${tests} ${component})
target_link_libraries(units dl Qt5::Widgets gtest gtest_main gcov)

add_executable(${CMAKE_PROJECT_NAME} ${main} ${core} ${component})
target_link_libraries(${CMAKE_PROJECT_NAME} dl Qt5::Widgets)

add_custom_target(
        tests_run
        COMMAND make && ./units && ./cov.sh
        WORKING_DIRECTORY ${CMAKE_CURRENT_SOURCE_DIR}
)

add_custom_target(
        graphicals
        ALL COMMAND qmake && make
        WORKING_DIRECTORY ${CMAKE_CURRENT_SOURCE_DIR}/lib/qt
)

add_custom_target(
        re
        COMMAND make fclean && make
        WORKING_DIRECTORY ${CMAKE_CURRENT_SOURCE_DIR}
)

add_custom_target(
        fclean
        COMMAND make clean && make distclean -C lib/qt
        WORKING_DIRECTORY ${CMAKE_CURRENT_SOURCE_DIR}
)
