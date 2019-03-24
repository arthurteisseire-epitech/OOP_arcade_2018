/*
** EPITECH PROJECT, 2018
** arcade
** File description:
** Player.cpp
*/

#include "Player.hpp"
#include "Converter.hpp"

arc::Player::Player(Map &map) : _sprite(""),
                                _pos({0, 0}),
                                _map(map)
{
	_sprite.setSize({_map.width() / 1000.0f, _map.height() / 1000.0f});
	_sprite.setPosition({0, 0});
	_sprite.setColor(0xffffffff);
}

void arc::Player::move(DIRECTION dir)
{
	_pos += dir;
	_sprite.setPosition(Converter::PosToPourcent(_pos, _map.width(), _map.height()));
}

const arc::Sprite &arc::Player::getSprite() const
{
	return _sprite;
}

arc::Position &arc::operator+=(Position &pos, Player::DIRECTION dir)
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

arc::Position arc::operator+(const Position &pos, Player::DIRECTION dir)
{
	Position newPos = pos;

	newPos += dir;
	return newPos;
}

bool arc::operator==(const Position &pos1, const Position &pos2)
{
	return pos1.x == pos2.x && pos1.y == pos2.y;
}
