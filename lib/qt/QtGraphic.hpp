/*
** EPITECH PROJECT, 2018
** OOP_arcade_2018
** File description:
** QtGraphic.hpp
*/

#ifndef OOP_ARCADE_2018_QTGRAPHIC_HPP
#define OOP_ARCADE_2018_QTGRAPHIC_HPP

#if defined ARCADE
#define COMMON_SO Q_DECL_EXPORT
#else
#define COMMON_SO Q_DECL_IMPORT
#endif

#include <QtGui>
#include <QtWidgets>
#include "IGraphic.hpp"
#include "ASprite.hpp"

class QtGraphic : public IGraphic, public QObject {
public:
	QtGraphic(int &ac, char *av[]);
	void draw() override;
	bool isOpen() override;
	void processSprite(const ASprite &sprite) override;
private:
	std::unique_ptr<QApplication> _app;
	std::unique_ptr<QWidget> _centralWidget;
	std::unique_ptr<QMainWindow> _window;
	std::unique_ptr<QPushButton> _button;
};

extern "C" COMMON_SO IGraphic *entryPoint(int &ac, char *av[]);

#endif
