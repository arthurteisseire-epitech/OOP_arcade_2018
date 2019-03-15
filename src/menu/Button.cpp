/*
** EPITECH PROJECT, 2018
** arcade
** File description:
** Button.cpp
*/

#include "Button.hpp"

arc::Button::Button(const std::string &filename, const std::string &text) :
	_sprite(std::make_unique<Sprite>(filename)),
	_text(std::make_unique<Text>(text))
{
}

void arc::Button::setPosition(const std::pair<float, float> &pos)
{
	_sprite->setPosition(pos);
	_text->setPosition(pos);
}

void arc::Button::setSize(const std::pair<float, float> &pos)
{
	_sprite->setSize(pos);
	_text->setSize(10);
}

const std::pair<float, float> &arc::Button::getPosition() const
{
	return _sprite->getPosition();
}

const std::pair<float, float> &arc::Button::getSize() const
{
        return _sprite->getSize();
}

arc::Sprite &arc::Button::getSprite() const
{
        return *_sprite;
}

arc::Text &arc::Button::getText() const
{
	return *_text;
}
