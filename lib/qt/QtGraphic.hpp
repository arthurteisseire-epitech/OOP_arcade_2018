/*
** EPITECH PROJECT, 2018
** OOP_arcade_2018
** File description:
** QtGraphic.hpp
*/

#include <QtGui>
#include <QtWidgets>
#include "IGraphic.hpp"

#ifndef OOP_ARCADE_2018_QTGRAPHIC_HPP
#define OOP_ARCADE_2018_QTGRAPHIC_HPP

#if defined ARCADE
#define COMMON_SO Q_DECL_EXPORT
#else
#define COMMON_SO Q_DECL_IMPORT
#endif

class QtGraphic : public IGraphic {
public:
	QtGraphic(int &ac, char *av[]);
	~QtGraphic();
	void processSprite(QColor color) override;
	void draw() override;
	bool isOpen() override;
private:
	void init(int *ac, char **av);

	std::unique_ptr<QApplication> _app;
	std::unique_ptr<QWidget> _centralWidget;
	std::unique_ptr<QMainWindow> _window;
	std::thread _thread;
};

extern "C" COMMON_SO IGraphic *entryPoint(int &ac, char *av[]);

#endif
