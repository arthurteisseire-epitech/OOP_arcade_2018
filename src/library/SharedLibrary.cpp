/*
** EPITECH PROJECT, 2018
** OOP_arcade_2018
** File description:
** SharedLibrary.cpp
*/

#include <dlfcn.h>
#include "SharedLibrary.hpp"
#include "SharedLibraryException.hpp"

SharedLibrary::SharedLibrary() :
	_lib(nullptr)
{
}

SharedLibrary::~SharedLibrary()
{
	if (_lib)
		dlclose(_lib);
}

void SharedLibrary::load(const std::string &libname)
{
	if (_lib)
		dlclose(_lib);
	_lib = dlopen(libname.c_str(), RTLD_LAZY);
	if (!_lib)
		throw SharedLibraryException(dlerror());
}

void *SharedLibrary::sym(const std::string &symname)
{
        return dlsym(_lib, symname.c_str());
}
