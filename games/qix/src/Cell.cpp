/*
** EPITECH PROJECT, 2018
** arcade
** File description:
** Cell.cpp
*/

#include "Cell.hpp"

const std::map<arc::Cell::STATE, unsigned> arc::Cell::_stateColor = {
	{WALKABLE,     0xff0000ff},
	{BORDER,       0x00ff00ff},
	{TRAIL,        0x0000ffff},
	{NON_WALKABLE, 0x000000ff},
};

arc::Cell::Cell(arc::Cell::STATE state) : _state(state), _sprite("")
{
	_sprite.setColor(_stateColor.find(_state)->second);
}

void arc::Cell::alterState(arc::Cell::STATE state)
{
	_sprite.setColor(_stateColor.find(_state)->second);
	_state = state;
}

arc::Cell::STATE arc::Cell::state() const
{
	return _state;
}

arc::Sprite &arc::Cell::sprite()
{
        return _sprite;
}
