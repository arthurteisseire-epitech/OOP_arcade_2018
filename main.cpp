/*
** EPITECH PROJECT, 2018
** OOP_arcade_2018
** File description:
** main.cpp
*/

#include "LibraryLoader.hpp"
#include "IGraphic.hpp"

int main(int argc, char *argv[])
{
	LibraryLoader loader;
	IGraphic *(*instantiate)(int &, char *[]);

	loader.load("lib/qt/lib_arcade_qt5.so");
	instantiate = (IGraphic *(*)(int &, char *[]))loader.findSym("instantiate");

	IGraphic *g = instantiate(argc, argv);
	g->createWidget();
	g->showWidget();
	return g->exec();
}
