/*
** EPITECH PROJECT, 2018
** arcade
** File description:
** ISprite.cpp
*/

#include "Sprite.hpp"

Sprite::Sprite(const std::string &filename) :
	_filename(filename)
{
}

const std::string &Sprite::getPath() const
{
	return _filename;
}
