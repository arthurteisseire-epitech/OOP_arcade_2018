/*
** EPITECH PROJECT, 2018
** arcade
** File description:
** Core.cpp
*/

#include <unistd.h>
#include "PlayerName.hpp"
#include "Text.hpp"
#include "Core.hpp"
#include "Process.hpp"

arc::Core::Core(IGraphic *graphic, std::unique_ptr<LibraryLoader> libraryLoader) :
	_sceneManager(std::make_unique<SceneManager>(MENU)),
	_libraryLoader(std::move(libraryLoader)),
	_graphic(graphic)
{
}

int arc::Core::exec()
{
	while (_graphic->isOpen() && nextScene() != nullptr) {
		currentScene()->update(_graphic->getKeys(), 0);
		Process::components(currentScene()->getComponents(), _graphic.get());
		_graphic->processEvents();
		_graphic->draw();
		usleep(100);
	}
	return 0;
}

arc::IScene *arc::Core::currentScene() const
{
	return _sceneManager->currentScene();
}

arc::IScene *arc::Core::nextScene() const
{
        return _sceneManager->nextScene();
}
