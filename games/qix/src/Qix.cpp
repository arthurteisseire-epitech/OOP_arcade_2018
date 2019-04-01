/*
** EPITECH PROJECT, 2018
** arcade
** File description:
** Qix.cpp
*/

#include "Qix.hpp"

arc::Qix::Qix(const arc::Position &pos) :
	_pos(pos),
	_size(5)
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
