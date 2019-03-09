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

class QtGraphic : public IGraphic, public QObject {
public:
	QtGraphic(int &ac, char *av[]);
	~QtGraphic() override;
	void draw() override;
	bool isOpen() override;
	void processSprite(QColor color) override;
private:
	std::unique_ptr<QApplication> _app;
	std::unique_ptr<QWidget> _centralWidget;
	std::unique_ptr<QMainWindow> _window;
};

extern "C" COMMON_SO IGraphic *entryPoint(int &ac, char *av[]);

#endif
