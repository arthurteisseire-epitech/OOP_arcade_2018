/*
** EPITECH PROJECT, 2018
** arcade
** File description:
** Core.cpp
*/

#include <unistd.h>
#include <iostream>
#include "PlayerName.hpp"
#include "Text.hpp"
#include "Core.hpp"
#include "Process.hpp"

arc::Core::Core(IGraphic *graphic) :
	_sceneManager(std::make_unique<SceneManager>(MENU, graphic))
{
}

int arc::Core::exec()
{
	return _sceneManager->start();
}
