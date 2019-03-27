/*
** EPITECH PROJECT, 2018
** arcade
** File description:
** Scene.hpp
*/

#ifndef ARCADE_SCENE_HPP
#define ARCADE_SCENE_HPP

#include <memory>
#include "IScene.hpp"
#include "Scenes.hpp"
#include "SharedData.hpp"

namespace arc {
	class Scene : public IScene {
	public:
		explicit Scene(const std::shared_ptr<SharedData> &playerData);
		~Scene() override = default;
	protected:
		std::shared_ptr<SharedData> _playerData;
	};
}

#endif
