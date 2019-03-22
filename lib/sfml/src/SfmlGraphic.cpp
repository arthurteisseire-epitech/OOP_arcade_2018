/*
** EPITECH PROJECT, 2018
** arcade
** File description:
** SfmlGraphic.cpp
*/

#include "SfmlGraphic.hpp"

#include <iostream>

const std::map<sf::Keyboard::Key, arc::Key> arc::SfmlGraphic::_sfmlKeys = {
	{sf::Keyboard::Return, ENTER},
	{sf::Keyboard::Up,     UP},
	{sf::Keyboard::Down,   DOWN},
	{sf::Keyboard::Left,   LEFT},
	{sf::Keyboard::Right,  RIGHT},
	{sf::Keyboard::F1,     F1},
	{sf::Keyboard::F2,     F2},
	{sf::Keyboard::F3,     F3},
	{sf::Keyboard::F4,     F4},
	{sf::Keyboard::Delete, SUPPR},
	{sf::Keyboard::Escape, ESCAPE},
	{sf::Keyboard::R,      R},
};

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
	return _window.isOpen();
}

void arc::SfmlGraphic::draw()
{
	_window.clear(sf::Color::Black);
	for (const auto &rect : _rects)
		_window.draw(rect);
	_window.display();
	_rects.clear();
}

bool arc::SfmlGraphic::processSprite(const arc::ISprite &sprite)
{
	auto rect = sf::RectangleShape(sf::Vector2f(_window.getSize().x * sprite.getSize().first,
	                                            _window.getSize().y * sprite.getSize().second));
	auto it = _textures.find(sprite.getTextureName());

	rect.setSize(sf::Vector2f(_window.getSize().x * sprite.getSize().first,
	                          _window.getSize().y * sprite.getSize().second));
	std::cerr << "width : " << _window.getSize().x << std::endl;
	std::cerr << "height : " << _window.getSize().y << std::endl;
	std::cerr << "sprite width : " << sprite.getSize().first << std::endl;
	std::cerr << "sprite height : " << sprite.getSize().second << std::endl;
	if (it == _textures.end()) {
		auto t = sf::Texture();
		if (!t.loadFromFile(sprite.getTextureName())) {
			rect.setFillColor(sf::Color(sprite.getColor()));
		} else {
			_textures.emplace(sprite.getTextureName(), t);
			rect.setTexture(&_textures.find(sprite.getTextureName())->second);
		}
	} else {
		rect.setTexture(&it->second);
	}
	rect.setPosition(_window.getSize().x * sprite.getPosition().first,
	                 _window.getSize().y * sprite.getPosition().second);
	_rects.emplace_back(rect);
	return true;
}

bool arc::SfmlGraphic::processText(const arc::IText &text)
{
//	std::cerr << text.getFontPath() << std::endl;
//	sf::Font font;
//	sf::Text t;
//	auto it = _fonts.find(text.getFontPath());
//
//	if (it == _fonts.end()) {
//		if (!font.loadFromFile(text.getFontPath()))
//			return false;
//		_fonts.emplace(text.getFontPath(), font);
//		t.setFont(_fonts.find(text.getFontPath())->second);
//	} else {
//		t.setFont(it->second);
//	}
//	t.setPosition(text.getPosition().first, text.getPosition().second);
//	t.setString(text.getText());
//	t.setCharacterSize(20);
//	t.setColor(sf::Color(text.getColor()));
//	_window.draw(t);
//	return true;
}

bool arc::SfmlGraphic::processAudio(const arc::IAudio &audio)
{
	return false;
}

void arc::SfmlGraphic::processEvents()
{
	sf::Event event;

	updateKeysState();
	_window.pollEvent(event);
	processKeys(event, sf::Event::KeyPressed, PRESSED);
	processKeys(event, sf::Event::KeyReleased, RELEASED);
	if (event.type == sf::Event::Closed) {
		_window.close();
	}
}

void arc::SfmlGraphic::processKeys(const sf::Event &event, sf::Event::EventType type, arc::KeyState state)
{
	if (event.type == type) {
		auto it = _sfmlKeys.find(event.key.code);
		if (it != _sfmlKeys.end())
			_keys[it->second] = state;
	}
}

void arc::SfmlGraphic::updateKeysState()
{
	auto it = _keys.begin();

	while (it != _keys.end())
		if (it->second == RELEASED)
			_keys.erase(it++);
		else if (it->second == PRESSED) {
			it->second = HOLD;
			++it;
		} else
			++it;
}

const std::map<arc::Key, arc::KeyState> &arc::SfmlGraphic::getKeys() const
{
	return _keys;
}

