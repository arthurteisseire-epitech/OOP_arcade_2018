/*
** EPITECH PROJECT, 2018
** arcade
** File description:
** SceneManager.hpp
*/

#ifndef ARCADE_SCENE_MANAGER_HPP
#define ARCADE_SCENE_MANAGER_HPP

#include <map>
#include <memory>
#include "IScene.hpp"

namespace arc {
	class SceneManager {
	public:
		explicit SceneManager(IScene *scene);
		~SceneManager() = default;

		void changeScene(IScene *scene);
		const IScene &currentScene() const;
		void processEvents(const std::map<Key, KeyState> &map);
	protected:
		std::unique_ptr<IScene> _scene;
	};
}

#endif
