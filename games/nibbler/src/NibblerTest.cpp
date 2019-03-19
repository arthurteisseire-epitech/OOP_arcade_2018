/*
** EPITECH PROJECT, 2018
** arcade
** File description:
** NibblerTest.cpp
*/

#include <functional>
#include "ISprite.hpp"
#include "IText.hpp"
#include "gtest/gtest.h"
#include "Nibbler.hpp"

TEST(GetComponents, UselessPleaseDelete)
{
	int ac = 3;

	arc::Nibbler nibbler(ac, nullptr);
	std::vector<std::reference_wrapper<arc::IComponent>> components = nibbler.getComponents();

	EXPECT_EQ(components[0].get().getType(), arc::SPRITE);
	EXPECT_FLOAT_EQ(dynamic_cast<arc::ISprite &>(components[0].get()).getSize().first, 0.1);
	EXPECT_FLOAT_EQ(dynamic_cast<arc::ISprite &>(components[0].get()).getSize().second, 0.1);
}

TEST(Nibbler, GetComponentsScore)
{
	int ac = 0;
	arc::Nibbler nibbler(ac, nullptr);
	std::vector<std::reference_wrapper<arc::IComponent>> components = nibbler.getComponents();
	bool a = false;

	for (auto comp : components)
		if (comp.get().getType() == arc::TEXT &&
		    strncmp(dynamic_cast<arc::IText &>(comp.get()).getText().c_str(), "Score: ", sizeof("Score:")) == 0)
			a = true;
	ASSERT_TRUE(a);
}