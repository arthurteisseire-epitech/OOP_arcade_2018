/*
** EPITECH PROJECT, 2018
** arcade
** File description:
** LibraryLoader.hpp
*/

#ifndef ARCADE_LIBRARYLOADER_HPP
#define ARCADE_LIBRARYLOADER_HPP

#include <string>
#include "IGame.hpp"
#include "IGraphic.hpp"
#include "LibraryLoaderException.hpp"

namespace arc {
	class LibraryLoader {
	public:
		LibraryLoader();
		~LibraryLoader();

		IGraphic *loadGraphicInstance(const std::string &libname);
		IGame *loadGameInstance(const std::string &libname);
	private:
		bool checkFileExists(const std::string &name) const;
		void load(const std::string &libname);
		void *findSym(const std::string &symname);

		void *_lib;
	};
}

#endif
