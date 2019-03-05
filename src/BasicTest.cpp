/*
** EPITECH PROJECT, 2018
** OOP_nanotekspice_2018
** File description:
** BasicTest.cpp
*/

#include "gtest/gtest.h"
#include "Basic.hpp"

TEST(Add, Simple)
{
	Basic basic;

	ASSERT_EQ(basic.add(5, 7), 12);
	ASSERT_EQ(basic.add(1, 1), 2);
	ASSERT_EQ(basic.add(-1, -1), -2);
}
