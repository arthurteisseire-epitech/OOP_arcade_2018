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
	_sprite.setPosition({0, 0});
	_sprite.setSize(Converter::SizeToPourcent(_map.width(), _map.height()));
	_sprite.setColor(0xffffffff);
}

void arc::Player::move(DIRECTION dir)
{
	if (_map.inBorder(_pos + dir))
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
