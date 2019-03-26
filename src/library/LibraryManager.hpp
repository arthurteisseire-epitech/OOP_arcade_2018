/*
** EPITECH PROJECT, 2018
** arcade
** File description:
** LibraryManager.hpp
*/

#ifndef ARCADE_LIBRARYMANAGER_HPP
#define ARCADE_LIBRARYMANAGER_HPP

#include <string>
#include <vector>
#include <memory>
#include "LibraryChanger.hpp"

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
		void safeChangeLib(const std::string &newlib);
		void changeLib();

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
		_libs = LibraryChanger::scanLibraries(_libDir);
		if (libname.empty())
			_libname = _libs[0];
		else
			_libname = libname;
		_instance = _loader.loadInstance<T>(LibraryChanger::libPath(_libDir, _libname), _entryPoint);
	}

	template<typename T>
	void LibraryManager<T>::prevLib()
	{
		std::string newLib = LibraryChanger::prevLib(_libs, _libname, _libDir);
		safeChangeLib(newLib);
	}

	template<typename T>
	void LibraryManager<T>::nextLib()
	{
		std::string newLib = LibraryChanger::nextLib(_libs, _libname, _libDir);
		safeChangeLib(newLib);
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
		_instance = _loader.loadInstance<T>(LibraryChanger::libPath(_libDir, _libname), _entryPoint);
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
}

#endif
