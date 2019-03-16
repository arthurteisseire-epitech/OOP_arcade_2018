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
	{MENU,        []() { return std::make_unique<MainMenu>(); }},
	{PLAYER_NAME, []() { return std::make_unique<PlayerName>(); }},
};

std::unique_ptr<arc::IScene> arc::SceneFactory::create(SCENE scene)
{
	return _scenesMap[scene]();
}
