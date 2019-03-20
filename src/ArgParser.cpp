/*
** EPITECH PROJECT, 2018
** arcade
** File description:
** ArgParser.cpp
*/

#include <iostream>
#include "ArgParser.hpp"

arc::ArgParser::ArgParser(int &argc, char **argv) :
	_libraryLoader(std::make_unique<LibraryLoader>())
{
	if (argc != 2) {
		std::cerr << "Usage : " << std::endl
		          << "\t" << std::string(argv[0]) + " ./lib[graphical_libname].so" << std::endl
		          << std::endl;
		exit(84);
	}
	loadLibrary(argv[1]);
}

void arc::ArgParser::loadLibrary(const std::string &libname)
{
	try {
		_graphic = _libraryLoader->loadInstance<IGraphic>(libname);
	} catch (arc::LibraryLoaderException &exception) {
		std::cerr << exception.what() << std::endl;
		exit(84);
	}
}

arc::Core arc::ArgParser::createCore()
{
	return Core(_graphic, std::move(_libraryLoader));
}
