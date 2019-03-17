/*
** EPITECH PROJECT, 2018
** arcade
** File description:
** Cursor.cpp
*/

#include "Cursor.hpp"

arc::Cursor::Cursor(Text *focus) :
	Sprite(""),
	_focus(focus)
{
	setSize(std::pair<float, float>(0.02, 0.005));
	setPosition(focus->getPosition());
}

void arc::Cursor::changeFocus(arc::Text *newFocus)
{
	setPosition(newFocus->getPosition());
	_focus = newFocus;
}

