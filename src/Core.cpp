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
	Text text("hello", std::pair<float, float>(0.1, 0.1), 60);
	std::vector<std::reference_wrapper<IComponent>> components;
	std::vector<std::reference_wrapper<ISprite>> sprite;

	components = _game->getComponents();
	sprite.emplace_back(dynamic_cast<ISprite &>(components[0].get()));
	std::cout << sprite.back().get().getSize().first << std::endl;
	while (_graphic->isOpen()) {
		arc::Process::sprites(sprite, _graphic.get());
		arc::Process::all(components, _graphic.get());
		_graphic->processText(text);
		_graphic->processEvents();
		_mainMenu->processEvents(_graphic->getKeys());
		_graphic->draw();
		usleep(100);
	}
	return 0;
}
