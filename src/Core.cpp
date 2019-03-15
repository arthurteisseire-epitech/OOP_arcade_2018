/*
** EPITECH PROJECT, 2018
** arcade
** File description:
** Core.cpp
*/

#include <unistd.h>
#include "Text.hpp"
#include "Core.hpp"
#include "Process.hpp"

arc::Core::Core(IGraphic *graphic, IGame *game) :
	_mainMenu(new MainMenu()),
	_graphic(std::unique_ptr<IGraphic>(graphic)),
	_game(std::unique_ptr<IGame>(game))
{
}

#include <iostream>
int arc::Core::exec()
{
	clock_t prog_time = clock();
	clock_t new_time;

	while (_graphic->isOpen()) {
		_graphic->processEvents();
		new_time = clock();
		_game->update(_graphic->getKeys(), (new_time - prog_time) / CLOCKS_PER_SEC);
		prog_time = new_time;
		Process::all(_game->getComponents(), _graphic.get());
		_graphic->draw();
		usleep(100);
	}
	return 0;
}
