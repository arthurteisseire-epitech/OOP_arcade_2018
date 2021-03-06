/*
** EPITECH PROJECT, 2018
** arcade
** File description:
** SceneFactory.hpp
*/

#ifndef ARCADE_SCENEFACTORY_HPP
#define ARCADE_SCENEFACTORY_HPP

#include <memory>
#include "IScene.hpp"
#include "Scenes.hpp"
#include "SharedData.hpp"

namespace arc {
	class SceneFactory {
	public:
		std::unique_ptr<IScene> create(SCENE scene, const std::shared_ptr<SharedData> &playerData);
	private:
		typedef std::function<std::unique_ptr<IScene>(const std::shared_ptr<SharedData> &)> createFP;
		typedef std::map<SCENE, createFP> SceneType;
		static SceneType _scenesMap;
	};
}

#endif
