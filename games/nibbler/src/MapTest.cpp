/*
** EPITECH PROJECT, 2018
** arcade
** File description:
** MapTest.cpp
*/

#include <ostream>
#include "Map.hpp"
#include "gtest/gtest.h"
#include "quickcheck/quickcheck.hh"

//using namespace quickcheck;
namespace qc = quickcheck;

class SnakeTestUtils : public arc::Snake {
public:
	explicit SnakeTestUtils(const Snake &snake) : Snake(snake)
	{}

	bool isFoodNotInSnake(const pos_t &fruit_pos) const
	{
		for (auto &snake_part : _body_positions)
			if (snake_part == fruit_pos)
				return (false);
		return true;
	}

	std::ostream &operator<<(std::ostream &stream) const
	{
		stream << "Snake positions:" << std::endl << "[";
		for (auto &snake_pos : _body_positions)
			stream << "(" << snake_pos.first << ", " << snake_pos.second << ")" << std::endl;
		return stream << "]" << std::endl;
	}
};

class FoodTestUtils : public arc::Food {
public:
	explicit FoodTestUtils(const Food &food) : Food(food)
	{}

	pos_t getPos() const
	{ return _pos; }

	std::ostream &operator<<(std::ostream &stream) const
	{
		return stream << "Fruit pos:" << std::endl << "(" << _pos.first << ", " << _pos.second << ")"
			      << std::endl;
	}
};

class MapTestUtils : public arc::Map {
public:
	explicit MapTestUtils(unsigned int size = 100) : Map(size)
	{}

	SnakeTestUtils *getSnakeUtils() const
	{ return new SnakeTestUtils(_snake); }

	const FoodTestUtils *getFoodUtils() const
	{ return new FoodTestUtils(_food); }

	unsigned int getSize() const
	{ return _size; }

};

std::ostream &operator<<(std::ostream &stream, const MapTestUtils &mapTestUtils)
{
	return stream << mapTestUtils.getSnakeUtils() << mapTestUtils.getFoodUtils();
}


class PFruitNotInSnake : public qc::Property<MapTestUtils> {
	bool holdsFor(const MapTestUtils &map) override
	{
		MapTestUtils map1 = map;

		map1.generateFood();
		return (map1.getFoodUtils()->getPos().first < map1.getSize() &&
			map1.getFoodUtils()->getPos().first < map1.getSize() &&
			map1.getSnakeUtils()->isFoodNotInSnake(map1.getFoodUtils()->getPos()));
	}
};

void generate(size_t n, MapTestUtils &mapTestUtils)
{
	unsigned int i;
	unsigned int l;

	qc::generate(n, i);
	qc::generate(n, l);
	l = i != 4 ? l % (i - 4) : 0;
	mapTestUtils = MapTestUtils(i);
	for (unsigned int c = 0; c < l; ++c)
		mapTestUtils.getSnakeUtils()->eat();
}

TEST(MapTest, GenerateFood)
{
	PFruitNotInSnake pFruitNotInSnake;

	EXPECT_TRUE(pFruitNotInSnake.check());
}