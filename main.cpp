#include <QApplication>
#include <QDebug>
#include <QDesktopWidget>

#include "src/Core/game.h"

int main(int argc, char *argv[])
{
	QApplication a(argc, argv);

	// getting screen size
	QRect rec = QApplication::desktop()->screenGeometry();
	Game::heightScreen = rec.height();
	Game::widthScreen = rec.width();

	Game g;

	return a.exec();
}
