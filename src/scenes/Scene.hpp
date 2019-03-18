/*
** EPITECH PROJECT, 2018
** arcade
** File description:
** Scene.hpp
*/

#ifndef ARCADE_SCENE_HPP
#define ARCADE_SCENE_HPP

#include "IScene.hpp"
#include "Scenes.hpp"

namespace arc {
	class Scene : public IScene {
	public:
		~Scene() override = default;
	};
}

#endif
