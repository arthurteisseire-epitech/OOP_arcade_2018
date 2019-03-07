/*
** EPITECH PROJECT, 2018
** OOP_arcade_2018
** File description:
** Test.cpp
*/

#include <QtGui>
#include <iostream>
#include "Graphic.hpp"

IGraphic *entryPoint(int &ac, char *av[])
{
	return new Graphic(ac, av);
}

Graphic::Graphic(int &ac, char *av[]) :
	_app(new QApplication(ac, av))
{
}

int Graphic::exec()
{
        return QApplication::exec();
}

void Graphic::createWidget()
{
	_widget = new QWidget();
	_widget->resize(100, 100);
}

void Graphic::showWidget()
{
	_widget->show();
}
