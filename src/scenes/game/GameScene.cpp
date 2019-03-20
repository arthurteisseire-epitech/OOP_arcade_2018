/*
** EPITECH PROJECT, 2018
** arcade
** File description:
** GameScene.cpp
*/

#include "GameScene.hpp"

arc::GameScene::GameScene(const std::shared_ptr<arc::PlayerData> &playerData) :
	Scene(playerData)
{
}

void arc::GameScene::update(const std::map<arc::Key, arc::KeyState> &keys, float deltaTime)
{
	if (_playerData->game)
		_playerData->game->update(keys, deltaTime);
}

std::vector<std::reference_wrapper<arc::IComponent>> arc::GameScene::getComponents() const
{
        if (_playerData->game)
        	return _playerData->game->getComponents();
        return std::vector<std::reference_wrapper<IComponent>>();
}

arc::SCENE arc::GameScene::nextScene() const
{
        if (_playerData->game && _playerData->game->isRunning())
	        return GAME;
	return MENU;
}
