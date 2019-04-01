/*
** EPITECH PROJECT, 2018
** arcade
** File description:
** Position.cpp
*/

#include <cmath>
#include "Position.hpp"

arc::Position::Position(unsigned int x_, unsigned int y_) :
	x(x_),
	y(y_)
{
}

double arc::Position::distance(const Position &pos) const
{
	return sqrt((pos.x * pos.x + x * x - 2 * pos.x * x) + ((pos.y * pos.y + y * y - 2 * pos.y * y)));
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

double arc::Position::size() const
{
	return sqrt(x * x + y * y);
}