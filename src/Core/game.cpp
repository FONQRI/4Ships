#include "game.h"
#include <QDesktopWidget>

// making fullscreen
// namespace sysvar
//{
// const Qt::WindowModality WindowsFormShow =Qt::ApplicationModal;
// const Qt::WindowType WindowsFormStyle=Qt::FramelessWindowHint;
// const Qt::WindowStates WindowsFormState=Qt::WindowFullScreen;
//}

Game::Game(QObject *parent) : QObject(parent)
{
	gameView = new GameView();
	gameView->show();

	// making game window fullscreen
	//    gameView->setWindowFlags( sysvar::WindowsFormStyle );
	//    gameView->setWindowState(
	//    gameView->windowState()|sysvar::WindowsFormState);
	//    gameView->setWindowModality(sysvar::WindowsFormShow);
	gameView->showFullScreen();
}

// init statics
int Game::heightScreen = 0;
int Game::widthScreen = 0;
