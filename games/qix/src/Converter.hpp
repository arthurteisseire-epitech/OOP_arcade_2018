/*
** EPITECH PROJECT, 2018
** arcade
** File description:
** Converter.hpp
*/

#ifndef ARCADE_CONVERTER_HPP
#define ARCADE_CONVERTER_HPP

#include <utility>
#include "Player.hpp"

namespace arc {
	class Converter {
	public:
		static std::pair<float, float> PosToPourcent(arc::Player::Position pos, int width, int height);
	};
}

#endif
