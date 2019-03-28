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
		std::string playerName;
		IGame *currentGame;
		std::vector<std::string> games;
		std::string gameName;
		std::vector<std::string> libs;
		std::string libname;
		std::pair<float, float> winSize;
	};
}

#endif
