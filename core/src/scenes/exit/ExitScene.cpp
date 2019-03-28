/*
** EPITECH PROJECT, 2018
** arcade
** File description:
** ExitScene.cpp
*/

#include "ExitScene.hpp"

arc::ExitScene::ExitScene(const std::shared_ptr<arc::SharedData> &playerData) :
	Scene(playerData)
{
}

void arc::ExitScene::update(const std::map<arc::Key, arc::KeyState> &, float)
{
}

std::vector<std::reference_wrapper<const arc::IComponent>> arc::ExitScene::getComponents() const
{
	return std::vector<std::reference_wrapper<const arc::IComponent>>();
}

arc::SCENE arc::ExitScene::nextScene(const std::map<arc::Key, arc::KeyState> &) const
{
	return EXIT;
}
