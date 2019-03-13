/*
** EPITECH PROJECT, 2018
** arcade
** File description:
** Nibbler.hpp,
*/

#ifndef ARCADE_NIBBLER_HPP
#define ARCADE_NIBBLER_HPP

#include "IGame.hpp"

class Nibbler : public IGame {
public:
	Nibbler(int &ac, char *av[]);
	std::vector<std::reference_wrapper<IComponent>> getComponents() override;
};

extern "C" __attribute__((visibility("default"))) IGame *entryPoint(int &ac, char *av[]);

#endif //ARCADE_NIBBLER_HPP
