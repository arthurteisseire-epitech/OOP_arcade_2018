/*
** EPITECH PROJECT, 2018
** arcade
** File description:
** ISprite.cpp
*/

#include "Sprite.hpp"

Sprite::Sprite(const std::string &filename) :
	_filename(filename),
	_pos(0, 0),
	_size(0, 0)
{
}

const std::string &Sprite::getPath() const
{
	return _filename;
}

void Sprite::setPosition(const std::pair<float, float> &pos)
{
	_pos = pos;
}

const std::pair<float, float> &Sprite::getPosition() const
{
	return _pos;
}

void Sprite::setSize(const std::pair<float, float> &size)
{
	_size = size;
}

const std::pair<float, float> &Sprite::getSize() const
{
	return _size;
}

ComponentType Sprite::getType() const
{
	return SPRITE;
}

void Sprite::moveUp(float y)
{
	_pos.second -= y;
}

void Sprite::moveDown(float y)
{
	_pos.second += y;
}
