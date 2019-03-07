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
	LibraryLoader loader(argc, argv);
	IGraphic *g = loader.loadGraphicInstance("lib/qt/lib_arcade_qt5.so");

	g->createWidget();
	g->showWidget();
	return g->exec();
}
