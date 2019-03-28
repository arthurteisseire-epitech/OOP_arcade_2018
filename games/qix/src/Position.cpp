/*
** EPITECH PROJECT, 2018
** arcade
** File description:
** Position.cpp
*/

#include "Position.hpp"

arc::Position::Position(unsigned int x_, unsigned int y_) :
	x(x_),
	y(y_)
{
}

std::ostream &arc::operator<<(std::ostream &ostream, const arc::Position &pos)
{
	return ostream << pos.x << ", " << pos.y;
}

arc::Position arc::Position::operator+(const Position &pos) const
{
	return {pos.x + x, pos.y + y};
}

arc::Position arc::Position::operator-(const Position &pos) const
{
	return {x - pos.x, y - pos.y};
}

bool arc::Position::operator!=(const Position &pos) const
{
	return pos.x != x || pos.y != y;
}
