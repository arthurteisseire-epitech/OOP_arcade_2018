/*
** EPITECH PROJECT, 2018
** arcade
** File description:
** ISprite.cpp
*/

#include "Sprite.hpp"

Sprite::Sprite(const std::string &filename) :
	_filename(filename),
	_pos(0, 0)
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
