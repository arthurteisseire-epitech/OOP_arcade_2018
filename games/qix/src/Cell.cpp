/*
** EPITECH PROJECT, 2018
** arcade
** File description:
** Cell.cpp
*/

#include "Cell.hpp"

arc::Cell::Cell(arc::Cell::STATE state) : _state(state)
{
}

arc::Cell::STATE arc::Cell::state() const
{
	return _state;
}
