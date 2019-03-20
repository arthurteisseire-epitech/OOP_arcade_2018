/*
** EPITECH PROJECT, 2018
** arcade
** File description:
** LibraryLoader.hpp
*/

#ifndef ARCADE_LIBRARYLOADER_HPP
#define ARCADE_LIBRARYLOADER_HPP

#include <string>
#include "IGraphic.hpp"
#include "LibraryLoaderException.hpp"

namespace arc {
	class LibraryLoader {
	public:
		LibraryLoader();
		~LibraryLoader();

		template<typename T>
		T *loadInstance(const std::string &libname)
		{
			T *(*instantiate)();

			load(libname);
			instantiate = (T *(*)())findSym("entryPoint");
			return instantiate();
		}

	private:
		bool checkFileExists(const std::string &name) const;
		void load(const std::string &libname);
		void *findSym(const std::string &symname);

		void *_lib;
	};
}

#endif
