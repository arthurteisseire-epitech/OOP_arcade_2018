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
		Position(int x, int y) : x(x), y(y) {}
		int x;
		int y;
	};
}

#endif
