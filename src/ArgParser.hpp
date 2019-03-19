/*
** EPITECH PROJECT, 2018
** arcade
** File description:
** ArgParser.hpp
*/

#ifndef ARCADE_ARGPARSER_HPP
#define ARCADE_ARGPARSER_HPP

#include "LibraryLoader.hpp"
#include "Core.hpp"

namespace arc {
	class ArgParser {
	public:
		ArgParser(int &argc, char **argv);
		arc::Core createCore();
	private:
		void loadLibrary(const std::string &libname);

		IGraphic *_graphic;
		LibraryLoader _libraryLoader;
	};
}

#endif
