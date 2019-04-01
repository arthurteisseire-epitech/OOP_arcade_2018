/*
** EPITECH PROJECT, 2018
** arcade
** File description:
** Qix.cpp
*/

#include "Qix.hpp"

arc::Qix::Qix(const arc::Position &pos, unsigned int size) :
	_pos(pos),
	_size(size)
{
}

const arc::Position &arc::Qix::position() const
{
	return _pos;
}

unsigned int arc::Qix::radius() const
{
	return _size / 2;
}

void arc::Qix::move(const arc::Position &direction)
{
	_pos += direction;
}
