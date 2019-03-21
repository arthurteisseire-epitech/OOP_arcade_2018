/*
** EPITECH PROJECT, 2018
** arcade
** File description:
** SfmlGraphic.cpp
*/

#include "SfmlGraphic.hpp"

arc::IGraphic *graphicEntryPoint()
{
	return new arc::SfmlGraphic();
}

arc::SfmlGraphic::SfmlGraphic()
{
	_window.create(sf::VideoMode(1920, 1080), "arcade");
}

bool arc::SfmlGraphic::isOpen() const
{
	return true;
}

void arc::SfmlGraphic::draw()
{
}

bool arc::SfmlGraphic::processSprite(const arc::ISprite &sprite)
{
	return true;
}

bool arc::SfmlGraphic::processText(const arc::IText &text)
{
	return false;
}

bool arc::SfmlGraphic::processAudio(const arc::IAudio &audio)
{
	return false;
}

void arc::SfmlGraphic::processEvents()
{
}

const std::map<arc::Key, arc::KeyState> &arc::SfmlGraphic::getKeys() const
{
	return _keys;
}
