/*
** EPITECH PROJECT, 2018
** arcade
** File description:
** Scenes.cpp
*/

#include "MainMenu.hpp"
#include "Scenes.hpp"

arc::Scenes::Scenes(IScene *scene) :
	_scene(scene)
{
}

void arc::Scenes::changeScene(IScene *scene)
{
	_scene.reset(scene);
}

const arc::IScene &arc::Scenes::currentScene() const
{
        return *_scene;
}

void arc::Scenes::processEvents(const std::map<arc::Key, arc::KeyState> &map)
{
	_scene->processEvents(map);
}
