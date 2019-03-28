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
		static std::pair<float, float> PosToPercent(const Position &pos, const Position &dimension);
		static std::pair<float, float> SizeToPercent(const Position &dimension);
	};
}

#endif
