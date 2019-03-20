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

arc::Core::Core(IGraphic *graphic, std::unique_ptr<LibraryLoader> libraryLoader) :
	_playerData(std::make_shared<PlayerData>()),
	_sceneManager(std::make_unique<SceneManager>(MENU, _playerData)),
	_graphicLibraryLoader(std::move(libraryLoader)),
	_gameLibraryLoader(std::make_unique<LibraryLoader>()),
	_graphic(graphic)
{
	_playerData->game = _gameLibraryLoader->loadInstance<IGame>("games/nibbler/lib_arcade_nibbler.so");
}

int arc::Core::exec()
{
	clock_t t = clock();

	while (_graphic->isOpen() && _sceneManager->nextScene() != nullptr) {
		update(_graphic->getKeys(), (float)(clock() - t) / CLOCKS_PER_SEC);
		t = clock();
		Process::components(_sceneManager->currentScene()->getComponents(), _graphic.get());
		_graphic->processEvents();
		_graphic->draw();
		usleep(100);
	}
	return 0;
}

void arc::Core::update(const std::map<arc::Key, arc::KeyState> &keys, float deltaTime)
{
	_sceneManager->currentScene()->update(keys, deltaTime);
}
