/*
** EPITECH PROJECT, 2018
** arcade
** File description:
** Text.hpp
*/

#ifndef ARCADE_TEXT_HPP
#define ARCADE_TEXT_HPP

#include "IText.hpp"

class Text : public IText {
public:
	explicit Text(const std::string &text, int size = 1, const std::pair<float, float> &pos = {0.0, 0.0});
	~Text() override = default;

	const std::string &getText() const override;
	const std::pair<float, float> &getPosition() const override;
	const int &getFontSize() const override;
	ComponentType getType() const override;
private:
	std::string _text;
	std::pair<float, float> _pos;
	int _size;
};

#endif
