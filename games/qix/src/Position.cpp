/*
** EPITECH PROJECT, 2018
** arcade
** File description:
** Position.cpp
*/

#include "Position.hpp"


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
	return {pos.x - x, pos.y - y};
}