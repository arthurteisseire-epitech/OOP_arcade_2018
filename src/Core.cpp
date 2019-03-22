/*
** EPITECH PROJECT, 2018
** arcade
** File description:
** Core.cpp
*/

#include <unistd.h>
#include <filesystem>
#include <regex>
#include "PlayerName.hpp"
#include "Text.hpp"
#include "Core.hpp"
#include "Process.hpp"

arc::Core::Core(IGraphic *graphic, std::unique_ptr<LibraryLoader> libraryLoader) :
	_sharedData(std::make_shared<SharedData>()),
	_sceneManager(std::make_unique<SceneManager>(MENU, _sharedData)),
	_graphicLibraryLoader(std::move(libraryLoader)),
	_gameLibraryLoader(std::make_unique<LibraryLoader>()),
	_graphic(graphic)
{
//	_sharedData->libs = scanLibraries("lib");
//	_sharedData->games = scanLibraries("games");
//	if (!_sharedData->games.empty())
//		_sharedData->currentGame = _gameLibraryLoader->loadGameInstance(_sharedData->games[0]);
}

int arc::Core::exec()
{
	clock_t t = clock();

	while (_graphic->isOpen() && _sceneManager->nextScene() != nullptr) {
		update(_graphic->getKeys(), (float)(clock() - t) / CLOCKS_PER_SEC);
		t = clock();
		Process::components(_sceneManager->currentScene()->getComponents(), _graphic.get());
		_graphic->processEvents();
		_graphic->draw();
		usleep(100);
	}
	return 0;
}

void arc::Core::update(const std::map<arc::Key, arc::KeyState> &keys, float deltaTime)
{
	_sceneManager->currentScene()->update(keys, deltaTime);
}

std::vector<std::string> arc::Core::scanLibraries(const std::string &libDir) const
{
//	std::vector<std::string> libs;
//	std::regex e("^(.*/)?lib_arcade_.*.so$");
//
//	for (const auto &entry : std::filesystem::directory_iterator(libDir))
//		if (std::regex_match(std::string(entry.path()), e))
//			libs.emplace_back(entry.path());
//	return libs;
}
