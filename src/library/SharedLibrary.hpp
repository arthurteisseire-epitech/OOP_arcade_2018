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
	SharedLibrary();
	~SharedLibrary();
	void load(const std::string &libname);
	void *sym(const std::string &symname);
private:
	void *_lib;
};

#endif
