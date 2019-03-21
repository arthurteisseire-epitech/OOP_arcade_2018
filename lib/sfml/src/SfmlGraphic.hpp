/*
** EPITECH PROJECT, 2018
** arcade
** File description:
** SfmlGraphic.hpp
*/

#ifndef ARCADE_SFMLGRAPHIC_HPP
#define ARCADE_SFMLGRAPHIC_HPP

#include <SFML/Graphics.hpp>
#include <SFML/Window.hpp>
#include "IGraphic.hpp"

namespace arc {
	class SfmlGraphic : public IGraphic {
	public:
		SfmlGraphic();
		bool isOpen() const override;
		void draw() override;
		bool processSprite(const ISprite &sprite) override;
		bool processText(const IText &text) override;
		bool processAudio(const IAudio &audio) override;
		void processEvents() override;
		const std::map<Key, KeyState> &getKeys() const override;
	private:
		void updateKeysState();
		void processKeys(const sf::Event &event, sf::Event::EventType type, arc::KeyState state);

		std::unique_ptr<sf::RenderWindow> _window;
		std::unique_ptr<std::map<std::string, sf::Texture>> _textures;
		std::unique_ptr<std::vector<sf::RectangleShape>> _rects;
		std::unique_ptr<std::map<std::string, sf::Font>> _fonts;
		std::map<Key, KeyState> _keys;
		static const std::map<sf::Keyboard::Key, Key> _sfmlKeys;
	};
}

extern "C" __attribute__((visibility("default"))) arc::IGraphic *graphicEntryPoint();

#endif
