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

arc::Core::Core(IGraphic *graphic) :
	_mainMenu(new MainMenu()),
	_graphic(std::unique_ptr<IGraphic>(graphic))
{
}

int arc::Core::exec()
{
	Text text("hello", std::pair<float, float>(0.1, 0.1), 60);

	while (_graphic->isOpen()) {
		arc::Process::sprites(_mainMenu->getSprites(), _graphic.get());
		_graphic->processText(text);
		_graphic->processEvents();
		_mainMenu->processEvents(_graphic->getKeys());
		_graphic->draw();
		usleep(100);
	}
	return 0;
}
