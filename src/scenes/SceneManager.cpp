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

arc::SceneManager::SceneManager(arc::SCENE scene, arc::IGraphic *graphic) :
	_currScene(scene),
	_graphic(graphic),
	_factory()
{
	_scene[scene] = _factory->create(scene);
}

void arc::SceneManager::changeScene(SCENE scene)
{
	_scene[scene] = _factory->create(scene);
	_currScene = scene;
}

const arc::IScene &arc::SceneManager::currentScene() const
{
	return *_scene.at(_currScene);
}

void arc::SceneManager::processEvents(const std::map<arc::Key, arc::KeyState> &keys)
{
	for (auto &key : keys)
		if (key.first == ENTER && key.second == PRESSED)
			_scene[_currScene]->action(*this);
	_scene[_currScene]->processEvents(keys);
}

int arc::SceneManager::start()
{
	arc::Process::audios(currentScene().getAudios(), _graphic.get());
	while (_graphic->isOpen()) {
		processEvents(_graphic->getKeys());
		arc::Process::sprites(currentScene().getSprites(), _graphic.get());
		arc::Process::texts(currentScene().getTexts(), _graphic.get());
		_graphic->processEvents();
		_graphic->draw();
		usleep(100);
	}
	return 0;
}
