/*
** EPITECH PROJECT, 2018
** OOP_arcade_2018
** File description:
** SharedLibraryTest.cpp
*/

#include "gtest/gtest.h"
#include "SharedLibrary.hpp"

TEST(SharedLibrary, LoadError)
{
        SharedLibrary lib;

        ASSERT_ANY_THROW(lib.load("qt"));
}
