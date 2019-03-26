/*
** EPITECH PROJECT, 2018
** arcade
** File description:
** Core.cpp
*/

#include <unistd.h>
#include <dirent.h>
#include <regex>
#include <iostream>
#include "LibraryChanger.hpp"
#include "PlayerName.hpp"
#include "Text.hpp"
#include "Core.hpp"
#include "Process.hpp"

const std::string arc::Core::GRAPHIC_DIR = "lib/";
const std::string arc::Core::GAME_DIR = "games/";

const std::map<arc::Key, void (arc::Core::*)()> arc::Core::_keyAction = {
	{F3,     &arc::Core::prevGraphicalLib},
	{F4,     &arc::Core::nextGraphicalLib},
	{ESCAPE, &arc::Core::backToMenu},
	{SUPPR,  &arc::Core::exit},
	{R,      &arc::Core::reloadGame},
};

arc::Core::Core(const std::string &libname) :
	_sharedData(std::make_shared<SharedData>()),
	_sceneManager(MENU, _sharedData)
{
	_sharedData->libs = LibraryChanger::scanLibraries(GRAPHIC_DIR);
	_sharedData->games = LibraryChanger::scanLibraries(GAME_DIR);
	_sharedData->libname = libname;
	_sharedData->gameName = _sharedData->games[0];
	_sharedData->currentGame = _gameLibraryLoader.loadGameInstance(
		LibraryChanger::libPath(GAME_DIR, _sharedData->gameName));
	_graphic = std::unique_ptr<IGraphic>(_graphicLibraryLoader.loadGraphicInstance(
		LibraryChanger::libPath(GRAPHIC_DIR, _sharedData->libname)));
}

int arc::Core::exec()
{
	clock_t t = clock();

	while (_graphic->isOpen() && _sceneManager.nextScene(_graphic->getKeys()) != nullptr) {
		update(_graphic->getKeys(), (float)(clock() - t) / CLOCKS_PER_SEC);
		t = clock();
		Process::components(_sceneManager.currentScene()->getComponents(), _graphic.get());
		_graphic->processEvents();
		_graphic->draw();
		usleep(100);
	}
	return 0;
}

void arc::Core::update(const std::map<arc::Key, arc::KeyState> &keys, float deltaTime)
{
	_sceneManager.currentScene()->update(keys, deltaTime);
	processEvents(keys);
}

void arc::Core::processEvents(const std::map<arc::Key, arc::KeyState> &keys)
{
	for (auto &keyAction : _keyAction) {
		auto key = keys.find(keyAction.first);
		if (key != keys.end() && key->second == RELEASED) {
			(this->*keyAction.second)();
			return;
		}
	}
}

void arc::Core::prevGraphicalLib()
{
	std::string newLib = LibraryChanger::prevLib(_sharedData->libs, _sharedData->libname, GRAPHIC_DIR);
	safeChangeGraphicalLib(newLib);
}

void arc::Core::nextGraphicalLib()
{
	std::string newLib = LibraryChanger::nextLib(_sharedData->libs, _sharedData->libname, GRAPHIC_DIR);
	safeChangeGraphicalLib(newLib);
}

void arc::Core::safeChangeGraphicalLib(const std::string &newlib)
{
	if (!_sharedData->libs.empty() && newlib != _sharedData->libname) {
		_sharedData->libname = newlib;
		changeGraphicalLib();
	}
}

void arc::Core::changeGraphicalLib()
{
	std::string libPath = LibraryChanger::libPath(GRAPHIC_DIR, _sharedData->libname);

	_graphic = nullptr;
	_graphic = std::unique_ptr<arc::IGraphic>(_graphicLibraryLoader.loadGraphicInstance(libPath));
}

void arc::Core::backToMenu()
{
	_sceneManager.changeScene(MENU);
}

void arc::Core::exit()
{
	_sceneManager.changeScene(EXIT);
}

void arc::Core::reloadGame()
{
	delete _sharedData->currentGame;
	_sharedData->currentGame = _gameLibraryLoader.loadGameInstance(
		LibraryChanger::libPath(GAME_DIR, _sharedData->gameName));
}
