/*
** EPITECH PROJECT, 2018
** arcade
** File description:
** LibraryChanger.cpp
*/

#include <dirent.h>
#include <regex>
#include "LibraryChanger.hpp"

std::string arc::LibraryChanger::nextLib(std::vector<std::string> &libs,
                                         const std::string &currLib,
                                         const std::string &dir)
{
	libs = scanLibraries(dir);
	auto it = std::find(libs.begin(), libs.end(), currLib);
	if (it == libs.begin())
		it = libs.end();
	--it;
	return *it;
}

std::string arc::LibraryChanger::prevLib(std::vector<std::string> &libs,
                                         const std::string &currLib,
                                         const std::string &dir)
{
	libs = scanLibraries(dir);
	auto it = std::find(libs.begin(), libs.end(), currLib);
	if (it + 1 == libs.end())
		it = libs.begin();
	else
		++it;
	return *it;
}

std::string arc::LibraryChanger::libPath(const std::string &dir, const std::string &libname)
{
	return dir + "lib_arcade_" + libname + ".so";
}

std::vector<std::string> arc::LibraryChanger::scanLibraries(const std::string &libDir)
{
	std::vector<std::string> libs;
	std::regex e("^lib_arcade_(.*)\\.so$");
	std::smatch m;
	struct dirent *ent;
	DIR *dir = opendir(libDir.c_str());

	if (dir != nullptr) {
		while ((ent = readdir(dir)) != nullptr) {
			std::string s = ent->d_name;
			if (std::regex_search(s, m, e))
				libs.emplace_back(m[1]);
		}
		closedir(dir);
	}
	return libs;
}
