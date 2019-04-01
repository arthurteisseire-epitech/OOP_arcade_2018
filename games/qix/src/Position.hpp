/*
** EPITECH PROJECT, 2018
** arcade
** File description:
** Position.hpp
*/

#ifndef ARCADE_POSITION_HPP
#define ARCADE_POSITION_HPP

#include <iostream>

namespace arc {
	struct Position {
		Position(unsigned int x, unsigned int y);
		unsigned int x;
		unsigned int y;

		double size() const;

		double distance(const Position &pos) const;
		Position operator+(const Position &pos) const;
		Position &operator+=(const Position &pos);
		Position operator-(const Position &pos) const;
		Position &operator-=(const Position &pos);
		bool operator!=(const Position &pos) const;
	};

	std::ostream &operator<<(std::ostream &ostream, const arc::Position &pos);
}

#endif
