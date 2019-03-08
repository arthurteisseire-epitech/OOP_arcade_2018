/*
** EPITECH PROJECT, 2018
** OOP_arcade_2018
** File description:
** main.cpp
*/

#include <QtGui/QColor>
#include <thread>
#include <unistd.h>
#include "LibraryLoader.hpp"
#include "IGraphic.hpp"

int main(int argc, char *argv[])
{
	LibraryLoader loader(argc, argv);
	IGraphic *g = loader.loadGraphicInstance("lib/qt/lib_arcade_qt5.so");

	for (int i = 0; i < 10; ++i) {
		usleep(1000000);
		if (i % 2 == 0)
			g->processSprite(Qt::black);
		else
			g->processSprite(Qt::white);
		g->draw();
	}
	return 0;
}
