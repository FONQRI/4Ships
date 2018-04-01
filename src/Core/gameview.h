#ifndef GAMEVIEW_H
#define GAMEVIEW_H

#include <QGraphicsScene>
#include <QGraphicsView>
#include <QPixmap>
#include <QTimer>

class GameView : public QGraphicsView {
  public:
	GameView();
	static QGraphicsScene *scene;
	QGraphicsPixmapItem *backgroundImage;

	QTimer t;
};

#endif // GAMEVIEW_H
