/*
** EPITECH PROJECT, 2018
** arcade
** File description:
** LibraryLoader.cpp
*/

#include <dlfcn.h>
#include <sys/stat.h>
#include "LibraryLoader.hpp"
#include "LibraryLoaderException.hpp"

arc::LibraryLoader::LibraryLoader(int &argc, char **argv) :
	_lib(nullptr),
	_argc(argc),
	_argv(argv)
{
}

arc::LibraryLoader::~LibraryLoader()
{
	if (_lib)
		dlclose(_lib);
}

bool arc::LibraryLoader::check_file_exists(const std::string &name) const
{
	struct stat buffer{};

	return (stat(name.c_str(), &buffer) == 0);
}

void arc::LibraryLoader::load(const std::string &libname)
{
	if (_lib)
		dlclose(_lib);
	if (!check_file_exists(libname))
		throw LibraryLoaderException(libname + " does not exist");
	_lib = dlopen(libname.c_str(), RTLD_LAZY);
	if (!_lib)
		throw LibraryLoaderException(dlerror());
}

void *arc::LibraryLoader::findSym(const std::string &symname)
{
	if (_lib == nullptr)
		throw LibraryLoaderException("No library loaded yet, can't load any symbol");
	return dlsym(_lib, symname.c_str());
}