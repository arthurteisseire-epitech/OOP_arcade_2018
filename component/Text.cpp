/*
** EPITECH PROJECT, 2018
** arcade
** File description:
** Text.cpp
*/

#include "Text.hpp"

arc::Text::Text(const std::string &text, const std::pair<float, float> &pos, int size, const std::string &fontPath) :
	_text(text),
	_pos(pos),
	_fontPath(fontPath),
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

int arc::Text::getFontSize() const
{
	return _size;
}

arc::ComponentType arc::Text::getType() const
{
	return TEXT;
}

const std::string &arc::Text::getFontPath() const
{
	return _fontPath;
}

void arc::Text::setPosition(const std::pair<float, float> &pos)
{
	_pos = pos;
}

void arc::Text::setSize(int size)
{
	_size = size;
}
