/*
** EPITECH PROJECT, 2018
** arcade
** File description:
** ConverterTest.cpp
*/

#include "gtest/gtest.h"
#include "Converter.hpp"
#include "Player.hpp"

namespace arc {
	TEST(ConverterTest, posToPourcent)
	{
		auto pos = Converter::PosToPourcent(Player::Position(0, 1), 10, 10);
		std::pair<float, float> expected = {0.0, 0.1};
		ASSERT_EQ(pos, expected);
	}
}
