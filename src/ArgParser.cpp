/*
** EPITECH PROJECT, 2018
** arcade
** File description:
** ArgParser.cpp
*/

#include <iostream>
#include "ArgParser.hpp"

arc::ArgParser::ArgParser(int &argc, char **argv) :
	_graphicLibraryLoader(argc, argv),
	_gameLibraryLoader(argc, argv)
{
	if (argc != 2) {
		std::cerr << "Usage : " << std::endl
		          << "\t" << std::string(argv[0]) + " ./lib[graphical_libname].so" << std::endl
		          << std::endl;
		exit(84);
	}
	loadGraphicLibrary(argv[1]);
	loadGameLibrary("games/nibbler/lib_arcade_nibbler.so");
}

void arc::ArgParser::loadGraphicLibrary(const std::string &libname)
{
	try {
		_graphic = _graphicLibraryLoader.loadInstance<IGraphic>(libname);
	} catch (arc::LibraryLoaderException &exception) {
		std::cerr << exception.what() << std::endl;
		exit(84);
	}
}

void arc::ArgParser::loadGameLibrary(const std::string &libname)
{
	try {
		_game = _gameLibraryLoader.loadInstance<IGame>(libname);
	} catch (arc::LibraryLoaderException &exception) {
		std::cerr << exception.what() << std::endl;
		exit(84);
	}
}

arc::Core arc::ArgParser::createCore()
{
	return Core(_graphic, _game);
}
