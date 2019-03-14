/*
** EPITECH PROJECT, 2018
** arcade
** File description:
** Text.cpp
*/

#include "Text.hpp"

Text::Text(const std::string &text, int size, const std::pair<float, float> &pos) :
	_text(text),
	_pos(pos),
	_size(size)
{
}

const std::string &Text::getText() const
{
        return _text;
}

const std::pair<float, float> &Text::getPosition() const
{
        return _pos;
}

const int &Text::getFontSize() const
{
        return _size;
}

ComponentType Text::getType() const
{
        return TEXT;
}
