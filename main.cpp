/*
** EPITECH PROJECT, 2018
** OOP_arcade_2018
** File description:
** main.cpp
*/

#include <unistd.h>
#include <iostream>
#include "ArgParser.hpp"
#include "Core.hpp"
#include "Text.hpp"
#include "Process.hpp"
#include "LibraryLoader.hpp"
#include "IGraphic.hpp"
#include "MainMenu.hpp"
#include "IGame.hpp"

int main(int argc, char *argv[])
{
	arc::ArgParser argParser(argc, argv);
	auto core = argParser.createCore();

	return core.exec();
}