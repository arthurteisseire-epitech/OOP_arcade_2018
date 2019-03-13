/*
** EPITECH PROJECT, 2018
** arcade
** File description:
** Text.hpp,
*/

#ifndef ARCADE_TEXT_HPP
#define ARCADE_TEXT_HPP

#include "IText.hpp"

class Text : public IText {
public:
	explicit Text(const std::string &text = "", const std::pair<float, float> &pos = {0.0, 0.0}, const std::string &font_path = "assets/fonts/default_font.ttf", int size = 1);
	~Text() override = default;

	ComponentType getType() const final;
	const std::string &getText() const override {return _text;}
	const std::pair<float, float> &getPosition() const override {return _pos;}
	const std::string &getFontPath() const override {return _font_path;}
	const int &getFontSize() const override {return _size;}
private:
	std::string _text;
	std::pair<float, float> _pos;
	std::string _font_path;
	int _size;
};


#endif //ARCADE_TEXT_HPP
