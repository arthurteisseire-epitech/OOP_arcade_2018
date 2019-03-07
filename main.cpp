/*
** EPITECH PROJECT, 2018
** OOP_arcade_2018
** File description:
** main.cpp
*/

#include <QtWidgets/QApplication>
#include "SharedLibrary.hpp"
#include "IGraphic.hpp"

int main(int argc, char *argv[])
{
	SharedLibrary library;
	IGraphic *(*instantiate)(int &, char *[]);

	library.load("lib/qt/lib_arcade_qt5.so");
	instantiate = (IGraphic *(*)(int &, char *[]))library.sym("instantiate");

	IGraphic *g = instantiate(argc, argv);
	g->createWidget();
	g->showWidget();
	return g->exec();
}
