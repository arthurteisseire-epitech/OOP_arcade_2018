/*
** EPITECH PROJECT, 2018
** arcade
** File description:
** Core.cpp
*/

#include <unistd.h>
#include <iostream>
#include "PlayerName.hpp"
#include "Text.hpp"
#include "Core.hpp"
#include "Process.hpp"

arc::Core::Core(IGraphic *graphic, IGame *game) :
	_sceneManager(std::make_unique<SceneManager>(MENU)),
	_graphic(std::unique_ptr<IGraphic>(graphic)),
	_game(game)
{
}

int arc::Core::exec()
{
	arc::Process::audios(_sceneManager->currentScene().getAudios(), _graphic.get());
	while (_graphic->isOpen()) {
		_sceneManager->processEvents(_graphic->getKeys());
		/*arc::Process::sprites(_sceneManager->currentScene().getSprites(), _graphic.get());
		arc::Process::texts(_sceneManager->currentScene().getTexts(), _graphic.get());*/
		_game->update(_graphic->getKeys(), 0.1);
		arc::Process::all(_game->getComponents(), _graphic.get());
		_graphic->processEvents();
		_graphic->draw();
		usleep(100);
	}
	return 0;
}
