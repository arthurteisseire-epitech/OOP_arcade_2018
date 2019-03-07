/*
** EPITECH PROJECT, 2018
** OOP_arcade_2018
** File description:
** IGraphic.hpp
*/

#ifndef OOP_ARCADE_2018_IGRAPHIC_HPP
#define OOP_ARCADE_2018_IGRAPHIC_HPP

class IGraphic {
public:
	virtual int exec() = 0;
	virtual void showWidget() = 0;
	virtual void createWidget() = 0;
};

#endif
