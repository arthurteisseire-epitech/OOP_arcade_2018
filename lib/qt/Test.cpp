/*
** EPITECH PROJECT, 2018
** OOP_arcade_2018
** File description:
** Test.cpp
*/

#include <QtGui>
#include <iostream>
#include "Test.hpp"

IGraphic *instantiate(int &ac, char *av[])
{
	return new App(ac, av);
}

App::App(int &ac, char *av[]) :
	_app(new QApplication(ac, av))
{
}

int App::exec()
{
        return _app->exec();
}

void App::createWidget()
{
	_widget = new QWidget();
	_widget->resize(100, 100);
}

void App::showWidget()
{
	_widget->show();
}
