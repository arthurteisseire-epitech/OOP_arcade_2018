/*
** EPITECH PROJECT, 2018
** arcade
** File description:
** Core.cpp
*/

#include "Core.hpp"

arc::Core::Core(IGraphic *graphic) :
	_mainMenu(new MainMenu()),
	_graphic(graphic)
{
}
