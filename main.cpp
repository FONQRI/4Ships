#include <QApplication>
#include <QDebug>
#include <QDesktopWidget>

#include "src/Core/game.h"
#include <QObject>
#include <QTimer>
#include <iostream>

// TODO write add path for move by movementDeirect

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);

    // getting screen size
    QRect rec = QApplication::desktop()->screenGeometry();
    Game::heightScreen = rec.height();
    Game::widthScreen = rec.width();
    QColor col(255, 0, 0, 0);
    Game g;

    return a.exec();
}
