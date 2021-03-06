/*
** EPITECH PROJECT, 2018
** arcade
** File description:
** Cursor.cpp
*/

#include "Cursor.hpp"

arc::Cursor::Cursor(Text *focus) : Sprite("", {0.02, 0.04}),
	_focus(focus)
{
	changeFocus(focus);
}

void arc::Cursor::changeFocus(arc::Text *newFocus)
{
	std::pair<float, float> textPos(newFocus->getPosition().first - getSize().first / 2.0,
	                                newFocus->getPosition().second - getSize().second / 2.0);

	setPosition(textPos);
	_focus = newFocus;
}

