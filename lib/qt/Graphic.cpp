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
	_window->setCentralWidget(_centralWidget.get());
}

int Graphic::exec()
{
        return QApplication::exec();
}

void Graphic::processSprite()
{
	QPalette palette;
	palette.setColor(QPalette::Background, Qt::black);
	_centralWidget->setAutoFillBackground(true);
	_centralWidget->setPalette(palette);
}

void Graphic::draw()
{
	_window->show();
}
