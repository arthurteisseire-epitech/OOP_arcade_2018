/*
** EPITECH PROJECT, 2018
** arcade
** File description:
** GameScene.cpp
*/

#include "GameScene.hpp"

arc::GameScene::GameScene(const std::shared_ptr<arc::SharedData> &playerData) :
	Scene(playerData)
{
}

void arc::GameScene::update(const std::map<arc::Key, arc::KeyState> &keys, float deltaTime)
{
	if (_playerData->currentGame)
		_playerData->currentGame->update(keys, deltaTime);
}

std::vector<std::reference_wrapper<const arc::IComponent>> arc::GameScene::getComponents() const
{
        if (_playerData->currentGame)
        	return _playerData->currentGame->getComponents();
        return std::vector<std::reference_wrapper<const IComponent>>();
}

arc::SCENE arc::GameScene::nextScene() const
{
        if (_playerData->currentGame && _playerData->currentGame->isRunning())
	        return GAME;
	return MENU;
}
