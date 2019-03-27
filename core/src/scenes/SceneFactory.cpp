/*
** EPITECH PROJECT, 2018
** arcade
** File description:
** SceneFactory.cpp
*/

#include "ExitScene.hpp"
#include "GameScene.hpp"
#include "PlayerName.hpp"
#include "MainMenu.hpp"
#include "SceneFactory.hpp"

arc::SceneFactory::SceneType arc::SceneFactory::_scenesMap = {
	{MENU,        [](const std::shared_ptr<SharedData> &p) { return std::make_unique<MainMenu>(p); }},
	{PLAYER_NAME, [](const std::shared_ptr<SharedData> &p) { return std::make_unique<PlayerName>(p); }},
	{GAME,        [](const std::shared_ptr<SharedData> &p) { return std::make_unique<GameScene>(p); }},
	{EXIT,        [](const std::shared_ptr<SharedData> &p) { return std::make_unique<ExitScene>(p); }},
};

std::unique_ptr<arc::IScene> arc::SceneFactory::create(SCENE scene, const std::shared_ptr<SharedData> &playerData)
{
	return _scenesMap[scene](playerData);
}
