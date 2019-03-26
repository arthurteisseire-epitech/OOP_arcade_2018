/*
** EPITECH PROJECT, 2018
** arcade
** File description:
** LibraryManager.hpp
*/

#ifndef ARCADE_LIBRARYMANAGER_HPP
#define ARCADE_LIBRARYMANAGER_HPP

#include <dirent.h>
#include <string>
#include <vector>
#include <memory>
#include <iostream>
#include <regex>
#include "LibraryLoader.hpp"
#include "LibraryLoaderException.hpp"

namespace arc {
	template<typename T>
	class LibraryManager {
	public:
		explicit LibraryManager(const std::string &libDir, const std::string &entryPoint,
		                        const std::string &libname = "");

		void prevLib();
		void nextLib();
		T *getInstance();
		const std::vector<std::string> &getLibsName();
		const std::string &getCurrentLibname();
	private:
		void scanDir();
		void safeChangeLib(const std::string &newlib);
		void changeLib();
		std::string libPath();

		T *_instance;
		LibraryLoader _loader;
		std::vector<std::string> _libs;
		std::string _libname;
		const std::string &_libDir;
		const std::string &_entryPoint;
	};

	template<typename T>
	LibraryManager<T>::LibraryManager(const std::string &libDir, const std::string &entryPoint,
	                                  const std::string &libname) :
		_libDir(libDir),
		_entryPoint(entryPoint)
	{
		scanDir();
		if (_libs.empty())
			throw LibraryLoaderException("No valid .so found in " + libDir);
		if (libname.empty())
			_libname = _libs[0];
		else
			_libname = libname;
		_instance = _loader.loadInstance<T>(libPath(), _entryPoint);
	}

	template<typename T>
	void LibraryManager<T>::prevLib()
	{
		scanDir();
		auto it = std::find(_libs.begin(), _libs.end(), _libname);
		if (it + 1 == _libs.end())
			it = _libs.begin();
		else
			++it;
		safeChangeLib(*it);
	}

	template<typename T>
	void LibraryManager<T>::nextLib()
	{
		scanDir();
		auto it = std::find(_libs.begin(), _libs.end(), _libname);
		if (it == _libs.begin())
			it = _libs.end();
		--it;
		safeChangeLib(*it);
	}

	template<typename T>
	void LibraryManager<T>::safeChangeLib(const std::string &newlib)
	{
		if (!_libs.empty() && newlib != _libname) {
			_libname = newlib;
			changeLib();
		}
	}

	template<typename T>
	void LibraryManager<T>::changeLib()
	{
		delete _instance;
		_instance = _loader.loadInstance<T>(libPath(), _entryPoint);
	}

	template<typename T>
	T *LibraryManager<T>::getInstance()
	{
		return _instance;
	}

	template<typename T>
	const std::vector<std::string> &LibraryManager<T>::getLibsName()
	{
                return _libs;
	}

	template<typename T>
	const std::string &LibraryManager<T>::getCurrentLibname()
	{
		return _libname;
	}

	template<typename T>
	void LibraryManager<T>::scanDir()
	{
		std::regex e("^lib_arcade_(.*)\\.so$");
		std::smatch m;
		struct dirent *ent;
		DIR *dir = opendir(_libDir.c_str());

		_libs.clear();
		if (dir != nullptr) {
			while ((ent = readdir(dir)) != nullptr) {
				std::string s = ent->d_name;
				if (std::regex_search(s, m, e))
				_libs.emplace_back(m[1]);
			}
			closedir(dir);
		}
	}

	template<typename T>
	std::string LibraryManager<T>::libPath()
	{
		return _libDir + "lib_arcade_" + _libname + ".so";
	}
}

#endif
