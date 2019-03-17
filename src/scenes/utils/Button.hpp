/*
** EPITECH PROJECT, 2018
** arcade
** File description:
** Button.hpp
*/

#ifndef ARCADE_BUTTON_HPP
#define ARCADE_BUTTON_HPP

#include <memory>
#include "SceneManager.hpp"
#include "Sprite.hpp"
#include "Text.hpp"

namespace arc {
	class Button {
	public:
		explicit Button(const std::string &filename, const std::string &text = "");
		void setPosition(const std::pair<float, float> &pos);
		const std::pair<float, float> &getPosition() const;
		void setSize(const std::pair<float, float> &pos);
		const std::pair<float, float> &getSize() const;
		Text &getText() const;
		Sprite &getSprite() const;

		void (*action)(SceneManager &sceneManager);
	private:
		std::unique_ptr<Sprite> _sprite;
		std::unique_ptr<Text> _text;
	};
}

#endif
