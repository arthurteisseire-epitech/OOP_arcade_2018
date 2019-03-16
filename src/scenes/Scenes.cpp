/*
** EPITECH PROJECT, 2018
** arcade
** File description:
** Scenes.cpp
*/

#include "Scenes.hpp"

arc::Scenes::Scenes() :
	_currScene(0)
{
}

void arc::Scenes::changeScene(int idx)
{
	_currScene = idx;
}
