/*
** EPITECH PROJECT, 2018
** arcade
** File description:
** Core.cpp
*/

#include "Core.hpp"

Core::Core(arc::MainMenu *mainMenu, IGraphic *graphic, IGame *game) :
	_mainMenu(mainMenu),
	_graphic(graphic),
	_game(game)
{
}
