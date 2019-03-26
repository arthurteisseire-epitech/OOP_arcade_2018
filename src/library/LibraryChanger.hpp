/*
** EPITECH PROJECT, 2018
** arcade
** File description:
** LibraryChanger.hpp
*/

#ifndef ARCADE_LIBRARYCHANGER_HPP
#define ARCADE_LIBRARYCHANGER_HPP

#include "SharedData.hpp"
#include "LibraryLoader.hpp"

namespace arc {
	class LibraryChanger {
	public:
		static std::string prevLib(std::vector<std::string> &libs, const std::string &currLib, const std::string &dir);
		static std::string nextLib(std::vector<std::string> &libs, const std::string &currLib, const std::string &dir);
		static std::string libPath(const std::string &dir, const std::string &libname);
		static std::vector<std::string> scanLibraries(const std::string &libDir);
	};
}

#endif
