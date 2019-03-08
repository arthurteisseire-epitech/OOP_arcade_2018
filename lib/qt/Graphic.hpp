/*
** EPITECH PROJECT, 2018
** OOP_arcade_2018
** File description:
** Test.hpp
*/

#include <QtGui>
#include <QtWidgets>
#include "IGraphic.hpp"

#if defined ARCADE
#define COMMON_SO Q_DECL_EXPORT
#else
#define COMMON_SO Q_DECL_IMPORT
#endif

class Graphic : public IGraphic {
public:
	Graphic(int &ac, char *av[]);
	~Graphic() override;
	void processSprite(QColor color) override;
	void draw() override;
	bool isOpen() override;
private:
	void startEventLoop(int &ac, char **av);

	std::unique_ptr<QApplication> _app;
	std::unique_ptr<QWidget> _centralWidget;
	std::unique_ptr<QMainWindow> _window;
	std::thread _thread;
};

extern "C" COMMON_SO IGraphic *entryPoint(int &ac, char *av[]);
