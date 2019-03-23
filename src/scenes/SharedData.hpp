/*
** EPITECH PROJECT, 2018
** arcade
** File description:
** SharedData.hpp
*/

#ifndef ARCADE_PLAYERDATA_HPP
#define ARCADE_PLAYERDATA_HPP

#include <string>
#include "IGame.hpp"

namespace arc {
	struct SharedData {
		std::string name;
		IGame *currentGame;
		std::vector<std::string> games;
		std::vector<std::string> libs;
		std::string libname;
	};
}

#endif
