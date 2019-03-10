/*
** EPITECH PROJECT, 2018
** arcade
** File description:
** ASprite.cpp
*/

#include "ASprite.hpp"

ASprite::ASprite(const std::string &filename) :
	_filename(filename)
{
}

const std::string &ASprite::getPath() const
{
	return _filename;
}
