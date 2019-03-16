/*
** EPITECH PROJECT, 2018
** arcade
** File description:
** Core.cpp
*/

#include <unistd.h>
#include "PlayerName.hpp"
#include "Text.hpp"
#include "Core.hpp"
#include "Process.hpp"

arc::Core::Core(IGraphic *graphic) :
	_sceneManager(std::make_unique<SceneManager>(PLAYER_NAME)),
	_graphic(std::unique_ptr<IGraphic>(graphic))
{
}

int arc::Core::exec()
{
	const IScene &mainMenu = _sceneManager->currentScene();

	arc::Process::audios(mainMenu.getAudios(), _graphic.get());
	while (_graphic->isOpen()) {
		arc::Process::sprites(mainMenu.getSprites(), _graphic.get());
		arc::Process::texts(mainMenu.getTexts(), _graphic.get());
		_graphic->processEvents();
		_sceneManager->processEvents(_graphic->getKeys());
		_graphic->draw();
		usleep(100);
	}
	return 0;
}
