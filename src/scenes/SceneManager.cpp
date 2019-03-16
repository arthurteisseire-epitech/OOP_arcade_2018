/*
** EPITECH PROJECT, 2018
** arcade
** File description:
** SceneManager.cpp
*/

#include "MainMenu.hpp"
#include "SceneManager.hpp"

arc::SceneManager::SceneManager(IScene *scene) :
	_scene(scene)
{
}

void arc::SceneManager::changeScene(IScene *scene)
{
	_scene.reset(scene);
}

const arc::IScene &arc::SceneManager::currentScene() const
{
        return *_scene;
}

void arc::SceneManager::processEvents(const std::map<arc::Key, arc::KeyState> &map)
{
	_scene->processEvents(map);
}
