/*
** EPITECH PROJECT, 2018
** arcade
** File description:
** PlayerData.hpp
*/

#ifndef ARCADE_PLAYERDATA_HPP
#define ARCADE_PLAYERDATA_HPP

#include <string>
#include "IGame.hpp"

namespace arc {
	struct PlayerData {
		std::string name;
		IGame *game;
	};
}

#endif
