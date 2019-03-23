/*
** EPITECH PROJECT, 2018
** arcade
** File description:
** main.cpp
*/

#include <iostream>
#include "Core.hpp"

static bool areArgsValid(int &argc, char **argv)
{
	if (argc != 2) {
		std::cerr << "Usage : " << std::endl
		          << "\t" << std::string(argv[0]) + " ./lib[graphical_libname].so" << std::endl
		          << std::endl;
		return false;
	}
	return true;
}

static int exec(int argc, char **argv)
{
	if (areArgsValid(argc, argv)) {
	        arc::Core core(argv[1]);
	        return core.exec();
        }
	return 84;
}

int main(int argc, char *argv[])
{
	try {
		return exec(argc, argv);
	} catch (const std::exception &e) {
		std::cerr << e.what() << std::endl;
		return 84;
	}
}