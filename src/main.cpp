/*
** EPITECH PROJECT, 2018
** OOP_arcade_2018
** File description:
** main.cpp
*/

#include <unistd.h>
#include "LibraryLoader.hpp"
#include "IGraphic.hpp"

int main(int argc, char *argv[])
{
	LibraryLoader loader(argc, argv);
	IGraphic *g = loader.loadGraphicInstance("lib/qt/lib_arcade_qt5.so");

	while (g->isOpen()) {
		g->processSprite();
		usleep(100);
	}
	return 0;
}
