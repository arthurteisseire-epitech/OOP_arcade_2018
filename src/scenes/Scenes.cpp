/*
** EPITECH PROJECT, 2018
** arcade
** File description:
** Scenes.cpp
*/

#include "MainMenu.hpp"
#include "Scenes.hpp"

arc::Scenes::Scenes() :
	_scene(new MainMenu())
{
}

void arc::Scenes::changeScene(IScene *scene)
{
	_scene.reset(scene);
}
