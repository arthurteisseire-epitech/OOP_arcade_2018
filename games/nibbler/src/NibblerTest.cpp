/*
** EPITECH PROJECT, 2018
** arcade
** File description:
** NibblerTest.cpp,
*/

#include <functional>
#include <Sprite.hpp>
#include "gtest/gtest.h"
#include "Nibbler.hpp"

TEST(GetComponents, UselessPleaseDelete)
{
	int ac = 3;

	arc::Nibbler nibbler(ac, nullptr);
	std::vector<std::reference_wrapper<arc::IComponent>> components = nibbler.getComponents();

	EXPECT_EQ(components[0].get().getType(), arc::SPRITE);
	EXPECT_EQ(dynamic_cast<arc::Sprite &>(components[0].get()).getSize(), (std::pair<float, float>(0.5, 0.5)));
}