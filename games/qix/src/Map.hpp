/*
** EPITECH PROJECT, 2018
** arcade
** File description:
** Map.hpp
*/

#ifndef ARCADE_MAP_HPP
#define ARCADE_MAP_HPP

#include <vector>
#include "Position.hpp"
#include "Cell.hpp"
#include "Qix.hpp"

namespace arc {
	class Map {
	public:
		explicit Map(const Position &dimension);
		~Map();

		Position dimension() const;
		bool isIn(const Position &pos) const;
		bool isInBorders(const Position &pos) const;
		bool isInNoBorders(const Position &pos) const;
		bool isInWalkable(const Position &pos) const;
		bool isNextToWalkable(const Position &pos) const;
		void trail(const Position &pos);
		void transformTrailToBorder();
		std::vector<std::reference_wrapper<const IComponent>> getSprites() const;
		int findPercentCovered() const;
		void updateQix(float dTime, bool failed = false);
		bool isPlayerAlive() const;

	protected:
		const Position _dimension;
		std::vector<std::vector<Cell>> _cells;
		std::vector<std::reference_wrapper<const IComponent>> _sprites;
		Qix _qix;
		std::vector<Position> _qixPositions;
		bool _isPlayerAlive;

	private:
		Qix initQix();
		void fillCells(const Position &pos);
		Position findNonQixZone(const Position &pos);
		bool tryPosition(Position posToTry, Position *posToLook, Position *oppositePos,
		                 Position oppositePosToTry) const;
		void findPosToLook(Position *posToLook, Position *oppositePos, const Position &currPos) const;
		bool isQixInZone(const Position &position);
		bool tryAllZonePositions(const Position &position);
		void fillZone(const Position &position);
		const std::vector<arc::Position> findQixPositions() const;
		void moveQix(const Position &direction, bool sign);
		bool checkMovement(const arc::Position &direction, bool sign);
		const float _updateTime;
	};
}

#endif
