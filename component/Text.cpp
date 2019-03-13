/*
** EPITECH PROJECT, 2018
** arcade
** File description:
** Text.cpp,
*/

#include "Text.hpp"

Text::Text(const std::string &text, const std::pair<float, float> &pos, const std::string &font_path, int size) :
	_text(text),
	_pos(pos),
	_font_path(font_path),
	_size(size)
{
}

ComponentType Text::getType() const
{
	return TEXT;
}
