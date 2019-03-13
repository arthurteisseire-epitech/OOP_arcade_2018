/*
** EPITECH PROJECT, 2018
** OOP_arcade_2018
** File description:
** main.cpp
*/

#include <unistd.h>
#include <iostream>
#include "Process.hpp"
#include "LibraryLoader.hpp"
#include "IGraphic.hpp"
#include "MainMenu.hpp"
#include "IGame.hpp"

int main(int argc, char *argv[])
{
	MainMenu mainMenu;
	LibraryLoader graphicLoader(argc, argv);
	LibraryLoader gameLoader(argc, argv);
	IGraphic *graphic = nullptr;
	IGame *game = nullptr;

	try {
		graphic = graphicLoader.loadInstance<IGraphic>("lib/qt/lib_arcade_qt5.so");
		game = gameLoader.loadInstance<IGame>("games/nibbler/lib_arcade_nibbler.so");
	}
	catch (LibraryLoaderException &exception) {
		std::cerr << exception.what() << std::endl;
		return (84);
	}
	while (graphic->isOpen()) {
		Process::all(game->getComponents(), graphic);
		usleep(100);
	}
	return 0;
}
