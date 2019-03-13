/*
** EPITECH PROJECT, 2018
** OOP_arcade_2018
** File description:
** LibraryLoaderTest.cpp
*/

#include "gtest/gtest.h"
#include "IGraphic.hpp"
#include "LibraryLoader.hpp"
#include "LibraryLoaderException.hpp"

TEST(SharedLibrary, LoadError)
{
        int ac = 1;
        char *av[1];
        LibraryLoader lib(ac, av);

        av[0] = const_cast<char *>(std::string("test").c_str());
        ASSERT_THROW(lib.load("Not existent lib"), LibraryLoaderException);
}

TEST(SharedLibrary, LoadGraphicInstanceError)
{
        int ac = 1;
        char *av[1];
        LibraryLoader lib(ac, av);

        av[0] = const_cast<char *>(std::string("test").c_str());
        ASSERT_THROW(lib.loadInstance<IGraphic>("non existent lib"), LibraryLoaderException);
}

TEST(SharedLibrary, FindSymWithoutLibError)
{
        int ac = 1;
        char *av[1];
        LibraryLoader lib(ac, av);

        av[0] = const_cast<char *>(std::string("test").c_str());
        ASSERT_THROW(lib.findSym("lib not yet loaded"), LibraryLoaderException);
}
