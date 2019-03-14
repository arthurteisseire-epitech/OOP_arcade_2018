/*
** EPITECH PROJECT, 2018
** arcade
** File description:
** LibraryLoader.hpp
*/

#ifndef ARCADE_LIBRARYLOADER_HPP
#define ARCADE_LIBRARYLOADER_HPP

#include <string>
#include "IGraphic.hpp"
#include "LibraryLoaderException.hpp"

namespace arc {
	class LibraryLoader {
	public:
		LibraryLoader(int &argc, char **argv);
		~LibraryLoader();
		void load(const std::string &libname);
		void *findSym(const std::string &symname);

		template<typename T>
		T *loadInstance(const std::string &libname)
		{
			T *(*instantiate)(int &, char *[]);

			load(libname);
			instantiate = (T *(*)(int &, char *[]))findSym("entryPoint");
			return instantiate(_argc, _argv);
		}

	private:
		bool check_file_exists(const std::string &name) const;
		void *_lib;
		int _argc;
		char **_argv;
	};
}

#endif
