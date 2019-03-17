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

namespace arc {
	class IScene;
	class SceneFactory {
	public:
		std::unique_ptr<IScene> create(SCENE scene);
	private:
		typedef std::function<std::unique_ptr<IScene>()> createFP;
		typedef std::map<SCENE, createFP> SceneType;
		static SceneType _scenesMap;
	};
}

#endif
