/*
** EPITECH PROJECT, 2018
** arcade
** File description:
** NibblerTest.cpp,
*/

#include <functional>
#include "ISprite.hpp"
#include "IText.hpp"
#include "gtest/gtest.h"
#include "Nibbler.hpp"

TEST(GetComponents, UselessPleaseDelete)
{
	int ac = 3;

	Nibbler nibbler(ac, nullptr);
	std::vector<std::reference_wrapper<IComponent>> components = nibbler.getComponents();

	EXPECT_EQ(components[0].get().getType(), SPRITE);
	EXPECT_FLOAT_EQ(dynamic_cast<ISprite &>(components[0].get()).getSize().first, 0.1);
	EXPECT_FLOAT_EQ(dynamic_cast<ISprite &>(components[0].get()).getSize().second, 0.1);
}

TEST(Nibbler, GetComponentsScore)
{
	int ac = 0;
	Nibbler nibbler(ac, nullptr);
	std::vector<std::reference_wrapper<IComponent>> components = nibbler.getComponents();
	bool a = false;

	for (auto comp : components)
		if (comp.get().getType() == TEXT &&
		    strncmp(dynamic_cast<IText &>(comp.get()).getText().c_str(), "Score: ", sizeof("Score:")) == 0)
			a = true;
	ASSERT_TRUE(a);
}