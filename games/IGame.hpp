/*
** EPITECH PROJECT, 2018
** arcade
** File description:
** IGame.hpp,
*/

#ifndef IGAME_HPP
#define IGAME_HPP

#include <vector>
#include "IComponent.hpp"

class IGame {
public:
	virtual ~IGame() = default;
	virtual std::vector<std::reference_wrapper<IComponent>> getComponents() = 0;
};


#endif //IGAME_HPP
