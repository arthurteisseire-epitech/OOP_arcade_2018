/*
** EPITECH PROJECT, 2018
** OOP_arcade_2018
** File description:
** LibraryLoader.cpp
*/

#include <dlfcn.h>
#include "LibraryLoader.hpp"
#include "LibraryLoaderException.hpp"

LibraryLoader::LibraryLoader() :
	_lib(nullptr)
{
}

LibraryLoader::~LibraryLoader()
{
	if (_lib)
		dlclose(_lib);
}

void LibraryLoader::load(const std::string &libname)
{
	if (_lib)
		dlclose(_lib);
	_lib = dlopen(libname.c_str(), RTLD_LAZY);
	if (!_lib)
		throw LibraryLoaderException(dlerror());
}

void *LibraryLoader::findSym(const std::string &symname)
{
        return dlsym(_lib, symname.c_str());
}
