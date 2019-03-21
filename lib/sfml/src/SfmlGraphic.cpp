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
	_textures(std::make_unique<std::map<std::string, sf::Texture>>()),
	_rects(std::make_unique<std::vector<sf::RectangleShape>>()),
	_fonts(std::make_unique<std::map<std::string, sf::Font>>()),
	_keys(std::make_unique<std::map<Key, KeyState>>())
{
	_window->create(sf::VideoMode(1920, 1080), "arcade");
}

bool arc::SfmlGraphic::isOpen() const
{
	return _window->isOpen();
}

void arc::SfmlGraphic::draw()
{
	_window->clear(sf::Color::Black);
	for (const auto &rect : *_rects)
		_window->draw(rect);
	_window->display();
	_rects->clear();
}

bool arc::SfmlGraphic::processSprite(const arc::ISprite &sprite)
{
	auto rect = sf::RectangleShape(sf::Vector2f(_window->getSize().x * sprite.getSize().first,
	                                            _window->getSize().y * sprite.getSize().second));
	auto it = _textures->find(sprite.getTextureName());

	if (it == _textures->end()) {
		auto t = sf::Texture();
		if (!t.loadFromFile(sprite.getTextureName())) {
			rect.setFillColor(sf::Color(sprite.getColor()));
		} else {
			_textures->emplace(sprite.getTextureName(), t);
			rect.setTexture(&_textures->find(sprite.getTextureName())->second);
		}
	} else {
		rect.setTexture(&it->second);
	}
	rect.setPosition(_window->getSize().x * sprite.getPosition().first,
	                 _window->getSize().y * sprite.getPosition().second);
	_rects->emplace_back(rect);
	return true;
}

bool arc::SfmlGraphic::processText(const arc::IText &text)
{
//	auto font = new sf::Font;
//	static bool first = true;
//
//	if (first) {
//		std::cerr << "1" << std::endl;
//		font->loadFromFile(text.getFontPath());
//		_text->setFont(*font);
//		_text->setString("hello");
//		_text->setPosition(10, 10);
//		_text->setCharacterSize(20);
//		_text->setColor(sf::Color::White);
//		first = false;
//	}
//	sf::Font font;
//	sf::Text t;
//	auto it = _fonts->find(text.getFontPath());
//
//	std::cerr << "1" << std::endl;
//	if (it == _fonts->end()) {
//		std::cerr << "2" << std::endl;
//		if (!font.loadFromFile(text.getFontPath())) {
//			return false;
//		}
//		_fonts->emplace(text.getFontPath(), font);
//		t.setFont(_fonts->find(text.getFontPath())->second);
//	} else {
//		t.setFont(it->second);
//	}
//	std::cerr << "3" << std::endl;
//	t.setPosition(text.getPosition().first, text.getPosition().second);
//	t.setString(text.getText());
//	t.setCharacterSize(20);
//	t.setColor(sf::Color(text.getColor()));
//	std::cerr << "4" << std::endl;
//	_texts->push_back(t);
//	std::cerr << "5" << std::endl;
//	return true;
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
