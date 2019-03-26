/*
** EPITECH PROJECT, 2018
** arcade
** File description:
** Core.cpp
*/

#include <unistd.h>
#include "LibraryChanger.hpp"
#include "PlayerName.hpp"
#include "Text.hpp"
#include "Core.hpp"
#include "Process.hpp"

const std::string arc::Core::GRAPHIC_DIR = "lib/";
const std::string arc::Core::GAME_DIR = "games/";

const std::string arc::Core::GRAPHIC_ENTRY_POINT = "graphicEntryPoint";
const std::string arc::Core::GAME_ENTRY_POINT = "gameEntryPoint";

const std::map<arc::Key, void (arc::Core::*)()> arc::Core::_keyAction = {
	{F1,     &arc::Core::prevGameLib},
	{F2,     &arc::Core::nextGameLib},
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
	_sharedData->libname = libname;
	_sharedData->games = LibraryChanger::scanLibraries(GAME_DIR);
	_sharedData->gameName = _sharedData->games[0];
	_graphicManager = new LibraryManager<IGraphic>(_sharedData->libs, _sharedData->libname,
	                                               GRAPHIC_DIR, GRAPHIC_ENTRY_POINT);
	_gameManager = new LibraryManager<IGame>(_sharedData->games, _sharedData->gameName,
	                                         GAME_DIR, GAME_ENTRY_POINT);
	_sharedData->currentGame = _gameManager->instance();
}

int arc::Core::exec()
{
	clock_t t = clock();

	while (_graphicManager->instance()->isOpen() && _sceneManager.nextScene(_graphicManager->instance()->getKeys()) != nullptr) {
		update(_graphicManager->instance()->getKeys(), (float)(clock() - t) / CLOCKS_PER_SEC);
		t = clock();
		Process::components(_sceneManager.currentScene()->getComponents(), _graphicManager->instance());
		_graphicManager->instance()->processEvents();
		_graphicManager->instance()->draw();
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
	_graphicManager->prevLib();
}

void arc::Core::nextGraphicalLib()
{
	_graphicManager->nextLib();
}

void arc::Core::prevGameLib()
{
	_gameManager->prevLib();
	_sharedData->currentGame = _gameManager->instance();
}

void arc::Core::nextGameLib()
{
	_gameManager->nextLib();
	_sharedData->currentGame = _gameManager->instance();
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
//	delete _sharedData->currentGame;
//	_sharedData->currentGame = _gameLibraryLoader.loadGameInstance(
//		LibraryChanger::libPath(GAME_DIR, _sharedData->gameName));
}
