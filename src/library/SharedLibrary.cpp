/*
** EPITECH PROJECT, 2018
** OOP_arcade_2018
** File description:
** SharedLibrary.cpp
*/

#include <dlfcn.h>
#include "SharedLibrary.hpp"
#include "SharedLibraryException.hpp"

void SharedLibrary::load(const std::string &libname)
{
	_lib = dlopen(std::string("lib" + libname + ".so").c_str(), RTLD_LAZY);
	if (!_lib)
		throw SharedLibraryException(dlerror());
}

void SharedLibrary::unload()
{
	dlclose(_lib);
}
