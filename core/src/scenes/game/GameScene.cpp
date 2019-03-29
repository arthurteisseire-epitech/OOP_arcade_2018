/*
** EPITECH PROJECT, 2018
** arcade
** File description:
** GameScene.cpp
*/

#include "Score.hpp"
#include "GameScene.hpp"

arc::GameScene::GameScene(const std::shared_ptr<arc::SharedData> &playerData) :
	Scene(playerData)
{
}

void arc::GameScene::update(const std::map<arc::Key, arc::KeyState> &keys, float deltaTime)
{
	if (_sharedData->currentGame)
		_sharedData->currentGame->update(keys, deltaTime, _sharedData->winSize);
}

std::vector<std::reference_wrapper<const arc::IComponent>> arc::GameScene::getComponents() const
{
        if (_sharedData->currentGame)
        	return _sharedData->currentGame->getComponents();
        return std::vector<std::reference_wrapper<const IComponent>>();
}

arc::SCENE arc::GameScene::nextScene(const std::map<Key, KeyState> &) const
{
        if (_sharedData->currentGame && _sharedData->currentGame->isRunning())
	        return GAME;
        Score::write(_sharedData->gameName, _sharedData->playerName, _sharedData->currentGame->getScore());
	return MENU;
}
