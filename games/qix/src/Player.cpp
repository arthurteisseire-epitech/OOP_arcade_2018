/*
** EPITECH PROJECT, 2018
** arcade
** File description:
** Player.cpp
*/

#include "Player.hpp"

arc::Player::Player() : _sprite("", {0.1, 0.1}, {0, 0}, 0xffffffff),
                        _pos({0, 0})
{
}

void arc::Player::move(DIRECTION dir)
{
	_pos += dir;
}

const arc::Sprite &arc::Player::getSprite() const
{
	return _sprite;
}

arc::Player::Position &arc::operator+=(Player::Position &pos, Player::DIRECTION dir)
{
	if (dir == Player::UP)
		--pos.y;
	else if (dir == Player::DOWN)
		++pos.y;
	else if (dir == Player::LEFT)
		--pos.x;
	else if (dir == Player::RIGHT)
		++pos.x;
	return pos;
}

bool arc::operator==(const Player::Position &pos1, const Player::Position &pos2)
{
	return pos1.x == pos2.x && pos1.y == pos2.y;
}
