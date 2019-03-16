/*
** EPITECH PROJECT, 2018
** arcade
** File description:
** Scenes.cpp
*/

#include "Scenes.hpp"

arc::Scenes::Scenes() :
	_currScene(MENU)
{
}

void arc::Scenes::changeScene(SCENE scene)
{
	_currScene = scene;
}
