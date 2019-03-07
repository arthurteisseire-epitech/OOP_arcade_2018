/*
** EPITECH PROJECT, 2018
** OOP_arcade_2018
** File description:
** SharedLibraryTest.cpp
*/

#include "gtest/gtest.h"
#include "LibraryLoader.hpp"
#include "SharedLibraryException.hpp"

TEST(SharedLibrary, LoadError)
{
        LibraryLoader lib;

        ASSERT_THROW(lib.load("qt"), SharedLibraryException);
}
