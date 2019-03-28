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
	_sceneManager(MENU, _sharedData),
	_gameManager(GAME_DIR, GAME_ENTRY_POINT),
	_graphicManager(GRAPHIC_DIR, GRAPHIC_ENTRY_POINT, libname)
{
	updateSharedData();
}

int arc::Core::exec()
{
	while (_graphicManager.getInstance()->isOpen() &&
	       _sceneManager.nextScene(_graphicManager.getInstance()->getKeys(), _gameManager) != nullptr) {
		update(_graphicManager.getInstance()->getKeys(), calcDeltaTime());
		Process::components(_sceneManager.currentScene()->getComponents(), _graphicManager.getInstance());
		_graphicManager.getInstance()->processEvents();
		_graphicManager.getInstance()->draw();
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
			updateSharedData();
			return;
		}
	}
}

void arc::Core::prevGraphicalLib()
{
	_graphicManager.prevLib();
}

void arc::Core::nextGraphicalLib()
{
	_graphicManager.nextLib();
}

void arc::Core::prevGameLib()
{
	_gameManager.prevLib();
}

void arc::Core::nextGameLib()
{
	_gameManager.nextLib();
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
	_gameManager.reload();
}

float arc::Core::calcDeltaTime() const
{
	timespec time{};
	static float currentTime;
	static float lastFrame;
	float deltaTime;

	clock_gettime(CLOCK_MONOTONIC, &time);
	currentTime = float(time.tv_sec) + float(time.tv_nsec) / 1000000000.0f;
	deltaTime = currentTime - lastFrame;
	lastFrame = currentTime;
	return deltaTime;
}

void arc::Core::updateSharedData()
{
	_sharedData->games = _gameManager.getLibsName();
	_sharedData->gameName = _gameManager.getCurrentLibname();
	_sharedData->currentGame = _gameManager.getInstance();

	_sharedData->libs = _graphicManager.getLibsName();
	_sharedData->libname = _graphicManager.getCurrentLibname();
}
