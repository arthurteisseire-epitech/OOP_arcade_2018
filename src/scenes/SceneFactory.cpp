/*
** EPITECH PROJECT, 2018
** arcade
** File description:
** SceneFactory.cpp
*/

#include "PlayerName.hpp"
#include "MainMenu.hpp"
#include "SceneFactory.hpp"

arc::SceneFactory::SceneType arc::SceneFactory::_scenesMap = {
	{MENU,        [](const std::shared_ptr<PlayerData> &p) { return std::make_unique<MainMenu>(p); }},
	{PLAYER_NAME, [](const std::shared_ptr<PlayerData> &p) { return std::make_unique<PlayerName>(p); }},
};

std::unique_ptr<arc::IScene> arc::SceneFactory::create(SCENE scene, const std::shared_ptr<PlayerData> &playerData)
{
	return _scenesMap[scene](playerData);
}
