/*
** EPITECH PROJECT, 2018
** arcade
** File description:
** SceneManager.hpp
*/

#ifndef ARCADE_SCENEMANAGER_HPP
#define ARCADE_SCENEMANAGER_HPP

#include <map>
#include <memory>
#include "IScene.hpp"
#include "SceneFactory.hpp"
#include "Scenes.hpp"

namespace arc {
	class SceneManager {
	public:
		explicit SceneManager(SCENE scene);
		~SceneManager() = default;

		void changeScene(SCENE scene);
		const IScene &currentScene() const;
		void processEvents(const std::map<Key, KeyState> &map);
	protected:
		std::unique_ptr<SceneFactory> _factory;
		std::unique_ptr<IScene> _scene;
	};
}

#endif
