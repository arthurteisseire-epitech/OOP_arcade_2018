/*
** EPITECH PROJECT, 2018
** arcade
** File description:
** SceneManager.cpp
*/

#include <unistd.h>
#include "Process.hpp"
#include "MainMenu.hpp"
#include "SceneManager.hpp"

arc::SceneManager::SceneManager(SCENE scene, std::unique_ptr<LibraryLoader> libraryLoader, IGraphic *graphic) :
	_currScene(scene),
	_factory(std::make_unique<SceneFactory>()),
	_playerData(std::make_shared<PlayerData>()),
	_libraryLoader(std::move(libraryLoader)),
	_graphic(graphic)
{
	_scene[scene] = _factory->create(scene, _playerData);
}

void arc::SceneManager::changeScene(SCENE scene)
{
	_scene[scene] = _factory->create(scene, _playerData);
	_currScene = scene;
}

arc::IScene &arc::SceneManager::currentScene() const
{
	return *_scene.at(_currScene);
}

int arc::SceneManager::start()
{
	while (_graphic->isOpen() && currentScene().nextScene() != NONE) {
		if (currentScene().nextScene() == _currScene) {
			currentScene().update(_graphic->getKeys(), 0);
			Process::all(currentScene().getComponents(), _graphic.get());
			_graphic->processEvents();
			_graphic->draw();
			usleep(100);
		} else {
			changeScene(currentScene().nextScene());
		}
	}
	return 0;
}
