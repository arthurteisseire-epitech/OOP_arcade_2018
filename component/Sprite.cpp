/*
** EPITECH PROJECT, 2018
** arcade
** File description:
** ISprite.cpp
*/

#include "Sprite.hpp"

arc::Sprite::Sprite(const std::string &filename) :
	_filename(filename),
	_pos(0, 0),
	_size(0, 0)
{
}

const std::string &arc::Sprite::getTextureName() const
{
	return _filename;
}

void arc::Sprite::setPosition(const std::pair<float, float> &pos)
{
	_pos = pos;
}

const std::pair<float, float> &arc::Sprite::getPosition() const
{
	return _pos;
}

void arc::Sprite::setSize(const std::pair<float, float> &size)
{
	_size = size;
}

const std::pair<float, float> &arc::Sprite::getSize() const
{
	return _size;
}

arc::ComponentType arc::Sprite::getType() const
{
	return SPRITE;
}

void arc::Sprite::moveUp(float y)
{
	_pos.second -= y;
}

void arc::Sprite::moveDown(float y)
{
	_pos.second += y;
}

unsigned int arc::Sprite::getColor() const
{
	return 0;
}
