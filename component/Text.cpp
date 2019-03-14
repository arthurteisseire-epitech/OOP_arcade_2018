/*
** EPITECH PROJECT, 2018
** arcade
** File description:
** Text.cpp
*/

#include "Text.hpp"

arc::Text::Text(const std::string &text, const std::pair<float, float> &pos, int size, const std::string &font_path) :
	_text(text),
	_pos(pos),
	_font_path(font_path),
	_size(size)
{
}

const std::string &arc::Text::getText() const
{
        return _text;
}

const std::pair<float, float> &arc::Text::getPosition() const
{
        return _pos;
}

const int &arc::Text::getFontSize() const
{
        return _size;
}

arc::ComponentType arc::Text::getType() const
{
        return TEXT;
}

const std::string &arc::Text::getFontPath() const
{
	return _font_path;
}