/*
** EPITECH PROJECT, 2018
** arcade
** File description:
** LibraryLoader.hpp
*/

#ifndef ARCADE_LIBRARYLOADER_HPP
#define ARCADE_LIBRARYLOADER_HPP

#include <string>
#include "LibraryLoaderException.hpp"

namespace arc {
	class LibraryLoader {
	public:
		LibraryLoader();
		~LibraryLoader();

		template <typename T>
		T *loadInstance(const std::string &libname, const std::string &entryPoint);
		template <typename T>
		T *reloadInstance(const std::string &entryPoint);
	private:
		bool checkFileExists(const std::string &name) const;
		void load(const std::string &libname);
		void *findSym(const std::string &symname);

		void *_lib;
	};

	template<typename T>
	T *arc::LibraryLoader::loadInstance(const std::string &libname, const std::string &entryPoint)
	{
		T *(*instantiate)();

		load(libname);
		instantiate = (T *(*)())findSym(entryPoint);
		if (instantiate == nullptr)
			throw LibraryLoaderException("wrong entry point");
		return instantiate();
	}

	template<typename T>
	T *arc::LibraryLoader::reloadInstance(const std::string &entryPoint)
	{
		T *(*instantiate)();

		instantiate = (T *(*)())findSym(entryPoint);
		if (instantiate == nullptr)
			throw LibraryLoaderException("wrong entry point");
		return instantiate();
	}
}

#endif
