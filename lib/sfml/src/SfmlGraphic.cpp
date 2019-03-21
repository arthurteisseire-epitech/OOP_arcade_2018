/*
** EPITECH PROJECT, 2018
** arcade
** File description:
** SfmlGraphic.cpp
*/

#include "SfmlGraphic.hpp"

#include <iostream>
arc::IGraphic *graphicEntryPoint()
{
	return new arc::SfmlGraphic();
}

arc::SfmlGraphic::SfmlGraphic() :
	_window(std::make_unique<sf::RenderWindow>()),
	_sprite(std::make_unique<sf::Sprite>()),
	_texture(std::make_unique<sf::Texture>()),
	_keys(std::make_unique<std::map<Key, KeyState>>())
{
	_window->create(sf::VideoMode(1920, 1080), "arcade");
	if (!_texture->loadFromFile("assets/focus.png")) {
		std::cerr << "error loading texture" << std::endl;
	}
	_sprite->setTexture(*_texture);
}

bool arc::SfmlGraphic::isOpen() const
{
	return _window->isOpen();
}

void arc::SfmlGraphic::draw()
{
	_window->clear(sf::Color::Black);
	_window->draw(*_sprite);
	_window->display();
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
//	sf::Event event{};
//
//	_window.pollEvent(event);
//	if (event.type == sf::Event::EventType::Closed)
//		_window.close();
}

const std::map<arc::Key, arc::KeyState> &arc::SfmlGraphic::getKeys() const
{
	return *_keys;
}
