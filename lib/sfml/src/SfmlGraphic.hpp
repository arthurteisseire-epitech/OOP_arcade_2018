/*
** EPITECH PROJECT, 2018
** arcade
** File description:
** SfmlGraphic.hpp
*/

#ifndef ARCADE_SFMLGRAPHIC_HPP
#define ARCADE_SFMLGRAPHIC_HPP

#include <SFML/Graphics.hpp>
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
		std::map<Key, KeyState> _keys;
	};
}

extern "C" __attribute__((visibility("default"))) arc::IGraphic *graphicEntryPoint();

#endif
