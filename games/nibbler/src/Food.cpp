/*
** EPITECH PROJECT, 2018
** arcade
** File description:
** Food.cpp
*/

#include "Food.hpp"
#include "Snake.hpp"
#include "MathUtils.hpp"

const unsigned int value = 500;

arc::Food::Food(const pos_t &position, const pos_t &size) :
	_pos(position),
	_sprite(std::make_unique<Sprite>(std::string(PATH_TO_ASSETS) + "apple.png"))
{
	_sprite->setPosition(_pos / size);
	_sprite->setSize(pos_t{1.0, 1.0} / size);
}

std::reference_wrapper<arc::ISprite> arc::Food::getSprite() const
{
	return std::reference_wrapper<ISprite>(*_sprite);
}

void arc::Food::move(const pos_t &pos, const pos_t &size)
{
	_sprite->setPosition(pos / size);
	_sprite->setSize(pos_t{1.0, 1.0} / size);
	_pos = pos;
}