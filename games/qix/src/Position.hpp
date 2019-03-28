/*
** EPITECH PROJECT, 2018
** arcade
** File description:
** Position.hpp
*/

#ifndef ARCADE_POSITION_HPP
#define ARCADE_POSITION_HPP

namespace arc {
	struct Position {
		Position(unsigned int x, unsigned int y) : x(x), y(y) {}
		unsigned int x;
		unsigned int y;
	};
}

#endif
