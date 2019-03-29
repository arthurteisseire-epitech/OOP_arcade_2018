/*
** EPITECH PROJECT, 2018
** arcade
** File description:
** Button.cpp
*/

#include "Button.hpp"

arc::Button::Button(const std::string &filename, SCENE linkedScene, const std::string &text, unsigned color) :
	_sprite(std::make_unique<Sprite>(filename)),
	_text(std::make_unique<Text>(text)),
	_linkedScene(linkedScene),
	_color(color)
{
	_sprite->setColor(_color);
}

void arc::Button::setPosition(const std::pair<float, float> &pos)
{
	std::pair<float, float> textPos(pos.first + _sprite->getSize().first / 2.0,
	                                pos.second + _sprite->getSize().second / 2.0);

	_sprite->setPosition(pos);
	_text->setPosition(textPos);
}

void arc::Button::setSize(const std::pair<float, float> &pos)
{
	_sprite->setSize(pos);
	_text->setSize(40);
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

arc::SCENE arc::Button::getLinkedScene() const
{
        return _linkedScene;
}
