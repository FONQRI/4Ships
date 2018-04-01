#include "gameview.h"
#include "game.h"
#include <QGraphicsPixmapItem>
#include <QLabel>

// TEST
#include "src/Engine/Graphics/fanimationpng.h"

GameView::GameView()
{

	// turn off scrollbars
	this->setHorizontalScrollBarPolicy(Qt::ScrollBarAlwaysOff);
	this->setVerticalScrollBarPolicy(Qt::ScrollBarAlwaysOff);

	// game background
	backgroundImage = new QGraphicsPixmapItem(
	QPixmap(":/assets/images/background.png")
		.scaled(QSize(Game::widthScreen, Game::heightScreen)));

	// setting scene
	scene = new QGraphicsScene();
	setScene(scene);
	scene->setSceneRect(0, 0, Game::widthScreen, Game::heightScreen);

	scene->addItem(backgroundImage);
	backgroundImage->setPos(0, 0);
	connect(&t, &QTimer::timeout, [&] {
	backgroundImage->setPixmap(QPixmap(":/assets/images/green.png"));
	});
	//	t.start(1000);

	// TEST FAnimationPNG
	FEngine2d::Graphics::FAnimationPNG testAnim;
	testAnim.setScene(scene);
}

// init statics
QGraphicsScene *GameView::scene = nullptr;
