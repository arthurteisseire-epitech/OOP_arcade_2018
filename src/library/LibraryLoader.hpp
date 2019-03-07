/*
** EPITECH PROJECT, 2018
** OOP_arcade_2018
** File description:
** LibraryLoader.hpp
*/

#ifndef OOP_ARCADE_2018_LIBRARYLOADER_HPP
#define OOP_ARCADE_2018_LIBRARYLOADER_HPP

#include <string>
#include <IGraphic.hpp>
#include "LibraryLoaderException.hpp"

class LibraryLoader {
public:
	LibraryLoader(int &argc, char **argv);
	~LibraryLoader();
	void load(const std::string &libname);
	void *findSym(const std::string &symname);
	IGraphic *loadGraphicInstance(std::string libname);
private:
	void *_lib;
	int _argc;
	char **_argv;
};

#endif
