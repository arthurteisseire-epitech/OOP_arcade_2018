/*
** EPITECH PROJECT, 2018
** OOP_arcade_2018
** File description:
** SharedLibrary.hpp
*/

#ifndef OOP_ARCADE_2018_SHAREDLIBRARY_HPP
#define OOP_ARCADE_2018_SHAREDLIBRARY_HPP

#include <string>
#include "SharedLibraryException.hpp"

class SharedLibrary {
public:
	void load(const std::string &libname);
	void unload();
private:
	void *_lib;
};

#endif
