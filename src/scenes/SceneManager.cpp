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
	_scene(_factory->create(scene))
{
}

void arc::SceneManager::changeScene(SCENE scene)
{
	_scene = _factory->create(scene);
}

const arc::IScene &arc::SceneManager::currentScene() const
{
        return *_scene;
}

void arc::SceneManager::processEvents(const std::map<arc::Key, arc::KeyState> &map)
{
	_scene->processEvents(map);
}
