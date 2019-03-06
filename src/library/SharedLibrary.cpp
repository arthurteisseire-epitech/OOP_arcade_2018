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
	_lib = dlopen(std::string("lib" + libname + ".so").c_str(), RTLD_LAZY);
	if (!_lib)
		throw SharedLibraryException(dlerror());
}
