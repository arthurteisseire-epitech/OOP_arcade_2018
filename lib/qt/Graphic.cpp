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
	_app(std::make_unique<QApplication>(ac, av)),
	_centralWidget(std::make_unique<QWidget>()),
	_window(std::make_unique<QMainWindow>())
{
}

int Graphic::exec()
{
        return QApplication::exec();
}

void Graphic::processSprite()
{
}

void Graphic::draw()
{
	_window->show();
}

void Graphic::createWindow()
{
	_window->setCentralWidget(_centralWidget.get());
}
