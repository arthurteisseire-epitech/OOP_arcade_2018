/*
** EPITECH PROJECT, 2018
** arcade
** File description:
** Core.cpp
*/

#include "PlayerName.hpp"
#include "Text.hpp"
#include "Core.hpp"
#include "Process.hpp"

arc::Core::Core(IGraphic *graphic, std::unique_ptr<LibraryLoader> libraryLoader) :
	_sceneManager(std::make_unique<SceneManager>(MENU, std::move(libraryLoader), graphic))
{
}

int arc::Core::exec()
{
	return _sceneManager->start();
}
