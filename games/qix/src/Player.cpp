/*
** EPITECH PROJECT, 2018
** arcade
** File description:
** Player.cpp
*/

#include "Player.hpp"

arc::Player::Player() : _sprite("", {0.1, 0.1}, {0, 0}, 0xffffffff),
			_x(0),
                        _y(0)
{
}

void arc::Player::moveDown()
{
	++_y;
}

void arc::Player::moveUp()
{
	--_y;
}

void arc::Player::moveRight()
{
	++_x;
}

void arc::Player::moveLeft()
{
	--_x;
}

const arc::Sprite &arc::Player::getSprite() const
{
        return _sprite;
}
