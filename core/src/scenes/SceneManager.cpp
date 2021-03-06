/*
** EPITECH PROJECT, 2018
** arcade
** File description:
** SceneManager.cpp
*/

#include "Process.hpp"
#include "MainMenu.hpp"
#include "SceneManager.hpp"

arc::SceneManager::SceneManager(SCENE scene, const std::shared_ptr<SharedData> &playerData) :
	_currScene(scene),
	_factory(std::make_unique<SceneFactory>()),
	_playerData(playerData)
{
	_scene[scene] = _factory->create(scene, _playerData);
}

void arc::SceneManager::changeScene(SCENE scene)
{
	_scene[scene] = _factory->create(scene, _playerData);
	_currScene = scene;
}

arc::IScene *arc::SceneManager::currentScene() const
{
	return _scene.at(_currScene).get();
}

arc::IScene *arc::SceneManager::nextScene(const std::map<Key, KeyState> &keys, LibraryManager<IGame> &gameManager)
{
	SCENE nextScene = currentScene()->nextScene(keys);

	if (nextScene == EXIT)
		return nullptr;
	if (nextScene != _currScene) {
		if (nextScene == GAME) {
			gameManager.reload();
			_playerData->currentGame = gameManager.getInstance();
		}
		changeScene(nextScene);
	}
	return currentScene();
}
