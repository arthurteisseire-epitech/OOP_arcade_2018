cmake_minimum_required(VERSION 3.11)
project(arcade)

add_compile_options(-Wall -Wextra --coverage)
set(CMAKE_EXE_LINKER_FLAGS ${CMAKE_EXE_LINKER_FLAGS} " --coverage")
set(CMAKE_CXX_STANDARD 14)
set(CMAKE_C_COMPILER "gcc")
set(CMAKE_CXX_COMPILER "g++")

set(CMAKE_CXX_OUTPUT_EXTENSION_REPLACE 1)

find_package(Qt5Widgets)
find_package(Qt5Multimedia)

set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} ${Qt5Widgets_EXECUTABLE_COMPILE_FLAGS}")

include_directories(
        core/src/scenes/player_name
        core/src/scenes/utils
        core/src/scenes/menu
        core/src/scenes/game
        core/src/scenes/score_board
        core/src/scenes/exit
        core/src/scenes
        core/src/library
        core/src
        lib/qt
        lib
        games/src
        games
        component
        .
)

file(GLOB_RECURSE main main.cpp)
file(GLOB_RECURSE core core/*.cpp)
file(GLOB_RECURSE component component/*.cpp)
list(FILTER core EXCLUDE REGEX ".*Test.cpp$")

file(GLOB_RECURSE lib lib/*.cpp)
file(GLOB_RECURSE games games/qix/*.cpp)
list(FILTER games EXCLUDE REGEX ".*Test.cpp$")

add_executable(${CMAKE_PROJECT_NAME} ${main} ${core} ${component} ${games})
target_link_libraries(${CMAKE_PROJECT_NAME} dl Qt5::Widgets Qt5::Multimedia)

add_custom_target(
        graphicals
        ALL COMMAND make
        WORKING_DIRECTORY ${CMAKE_CURRENT_SOURCE_DIR}/lib
)

add_custom_target(
        games
        ALL COMMAND make
        WORKING_DIRECTORY ${CMAKE_CURRENT_SOURCE_DIR}/games
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

add_custom_target(
        tests_run
        COMMAND make && make test && ./cov.sh
        WORKING_DIRECTORY ${CMAKE_CURRENT_SOURCE_DIR}
)

#enable_testing()
#
#file(GLOB_RECURSE tests core/*Test.cpp games/qix/*Test.cpp)
#
#add_executable(units ${core} ${tests} ${component} ${games})
#target_link_libraries(units dl Qt5::Widgets Qt5::Multimedia gtest gtest_main gcov)
#
#add_test(NAME units COMMAND units)
#