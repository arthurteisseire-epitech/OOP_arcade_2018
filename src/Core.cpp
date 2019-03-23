/*
** EPITECH PROJECT, 2018
** arcade
** File description:
** Core.cpp
*/

#include <unistd.h>
#include <dirent.h>
#include <filesystem>
#include <regex>
#include <iostream>
#include "PlayerName.hpp"
#include "Text.hpp"
#include "Core.hpp"
#include "Process.hpp"

arc::Core::Core(const std::string &libname) :
	_sharedData(std::make_shared<SharedData>()),
	_sceneManager(MENU, _sharedData)
{
	_sharedData->libs = scanLibraries("lib/");
	_sharedData->games = scanLibraries("games/");
	_sharedData->libIt = std::find(_sharedData->libs.begin(), _sharedData->libs.end(), libname);
	_sharedData->currentGame = _gameLibraryLoader.loadGameInstance(
		"games/lib_arcade_" + _sharedData->games[0] + ".so");
	_graphic = std::unique_ptr<IGraphic>(_graphicLibraryLoader.loadGraphicInstance(libPath()));
}

int arc::Core::exec()
{
	clock_t t = clock();

	while (_graphic->isOpen() && _sceneManager.nextScene() != nullptr) {
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
	auto key = keys.find(arc::F3);
	if (key != keys.end() && key->second == arc::RELEASED)
		changeLib();
}

void arc::Core::changeLib()
{
	if (_sharedData->libIt + 1 == _sharedData->libs.end())
		_sharedData->libIt = _sharedData->libs.begin();
	else
		++_sharedData->libIt;
	_graphic = nullptr;
	_graphic = std::unique_ptr<arc::IGraphic>(
		_graphicLibraryLoader.loadGraphicInstance(libPath()));
}

std::vector<std::string> arc::Core::scanLibraries(const std::string &libDir) const
{
	std::vector<std::string> libs;
	std::regex e("^lib_arcade_(.*)\\.so$");
	std::smatch m;
	struct dirent *ent;
	DIR *dir = opendir(libDir.c_str());

	if (dir != nullptr) {
		while ((ent = readdir(dir)) != nullptr) {
			std::string s = ent->d_name;
			if (std::regex_search(s, m, e))
				libs.emplace_back(m[1]);
		}
		closedir(dir);
	}
	return libs;
}

std::string arc::Core::libPath()
{
	return "lib/lib_arcade_" + *_sharedData->libIt + ".so";
}
