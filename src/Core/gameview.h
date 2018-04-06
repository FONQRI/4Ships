#ifndef GAMEVIEW_H
#define GAMEVIEW_H

#include "src/FEngine/Graphics/fanimationpng.h"
#include <QGraphicsScene>
#include <QGraphicsView>
#include <QPixmap>
#include <QPropertyAnimation>
#include <QTimer>

#include <iostream>
#include <memory>

class GameView : public QGraphicsView {
  public:
	GameView();
	static QGraphicsScene *scene;
	QGraphicsPixmapItem *backgroundImage;
	FEngine2d::Graphics::FAnimationPNG *testAnim;

	QTimer t;
};

#endif // GAMEVIEW_H
