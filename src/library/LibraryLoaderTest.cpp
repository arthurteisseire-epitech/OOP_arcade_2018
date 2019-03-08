/*
** EPITECH PROJECT, 2018
** OOP_arcade_2018
** File description:
** LibraryLoaderTest.cpp
*/

#include "gtest/gtest.h"
#include "LibraryLoader.hpp"
#include "LibraryLoaderException.hpp"

TEST(SharedLibrary, LoadError)
{
        int ac = 1;
        char *av[1];
        LibraryLoader lib(ac, av);

        av[0] = const_cast<char *>(std::string("test").c_str());
        ASSERT_THROW(lib.load("qt"), LibraryLoaderException);
}
