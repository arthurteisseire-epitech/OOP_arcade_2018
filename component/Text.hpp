/*
** EPITECH PROJECT, 2018
** arcade
** File description:
** Text.hpp
*/

#ifndef ARCADE_TEXT_HPP
#define ARCADE_TEXT_HPP

#include "IText.hpp"

namespace arc {
	class Text : public IText {
	public:
		explicit Text(const std::string &text = "", const std::pair<float, float> &pos = {0.0, 0.0},
			      int size = 1, const std::string &font_path = "assets/fonts/default_font.ttf");
		~Text() override = default;

		ComponentType getType() const final;
		const std::string &getText() const override;
		const std::pair<float, float> &getPosition() const override;
		const std::string &getFontPath() const override;
		int getFontSize() const override;

		void setPosition(const std::pair<float, float> &pos);
		void setSize(int size);
	private:
		std::string _text;
		std::pair<float, float> _pos;
		std::string _font_path;
		int _size;
	};
}

#endif
