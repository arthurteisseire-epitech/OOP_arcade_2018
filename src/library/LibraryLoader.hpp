/*
** EPITECH PROJECT, 2018
** OOP_arcade_2018
** File description:
** LibraryLoader.hpp
*/

#ifndef OOP_ARCADE_2018_SHAREDLIBRARY_HPP
#define OOP_ARCADE_2018_SHAREDLIBRARY_HPP

#include <string>
#include "LibraryLoaderException.hpp"

class LibraryLoader {
public:
	LibraryLoader();
	~LibraryLoader();
	void load(const std::string &libname);
	void *findSym(const std::string &symname);
private:
	void *_lib;
};

#endif
