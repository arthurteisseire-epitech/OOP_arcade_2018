/*
** EPITECH PROJECT, 2018
** arcade
** File description:
** SceneManager.cpp
*/

#include "MainMenu.hpp"
#include "SceneManager.hpp"

arc::SceneManager::SceneManager(SCENE scene) :
	_factory(),
	_currScene(scene)
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
		if (key.first == ENTER && key.second == RELEASED)
			_scene[_currScene]->action(*this);
	_scene[_currScene]->processEvents(keys);
}
