/*
** EPITECH PROJECT, 2018
** arcade
** File description:
** main.cpp
*/

#include <iostream>
#include <regex>
#include "Core.hpp"

static bool areArgsValid(int &argc, char **argv)
{
	if (argc != 2) {
		std::cerr << "Usage : " << std::endl
		          << "\t" << std::string(argv[0]) + " lib/lib_arcade_[graphical_libname].so" << std::endl
		          << std::endl;
		return false;
	}
	return true;
}

static std::string parseLibname(const std::string &libpath)
{
	std::regex e("^(.*/)*lib_arcade_(.*)\\.so$");
	std::smatch m;

	if (std::regex_search(libpath, m, e))
		return m[2];
	return libpath;
}

static int exec(int argc, char **argv)
{
	std::string libname;

	if (areArgsValid(argc, argv)) {
		libname = parseLibname(argv[1]);
	        arc::Core core(libname);
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