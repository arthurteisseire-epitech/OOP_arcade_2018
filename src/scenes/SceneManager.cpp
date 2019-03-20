/*
** EPITECH PROJECT, 2018
** arcade
** File description:
** SceneManager.cpp
*/

#include "Process.hpp"
#include "MainMenu.hpp"
#include "SceneManager.hpp"

arc::SceneManager::SceneManager(SCENE scene, const std::shared_ptr<PlayerData> &playerData) :
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

arc::IScene *arc::SceneManager::nextScene()
{
	SCENE nextScene = currentScene()->nextScene();

	if (nextScene == NONE)
		return nullptr;
	if (nextScene != _currScene)
		changeScene(nextScene);
	return currentScene();
}
