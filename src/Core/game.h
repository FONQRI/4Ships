#ifndef GAME_H
#define GAME_H

#include <QObject>
#include <QVBoxLayout>

#include "gameview.h"

class Game : public QObject {
	Q_OBJECT
  public:
	explicit Game(QObject *parent = nullptr);
	GameView *gameView;
	QVBoxLayout *layout;

	// global variables
	static int heightScreen;
	static int widthScreen;

  signals:

  public slots:
};

#endif // GAME_H
