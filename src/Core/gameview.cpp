#include "gameview.h"
#include "game.h"
#include <QGraphicsPixmapItem>
#include <QLabel>
#include <QPushButton>

// TEST
#include "src/FEngine/Graphics/fanimationpng.h"

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

	// TEST FAnimationPNG
	std::vector<std::shared_ptr<QPixmap>> images;
	images.push_back(std::make_shared<QPixmap>(
	":/assets/images/animations/heavy damage/factory_heavy_damage_1.png"));
	images.push_back(std::make_shared<QPixmap>(
	":/assets/images/animations/heavy damage/factory_heavy_damage_2.png"));
	images.push_back(std::make_shared<QPixmap>(
	":/assets/images/animations/heavy damage/factory_heavy_damage_3.png"));

	*(images.at(0)) = images.at(0)->scaled(QSize(64, 64));
	QPointF point(0.0f, 0.0f);
	testAnim = new FEngine2d::Graphics::FAnimationPNG(scene, images, point);
	testAnim->setDuration(600);
	//	testAnim.m_timer->start(300);
	testAnim->run();
	connect(&t, &QTimer::timeout, [&] {
	testAnim->setPosition(QPointF(testAnim->getPosition().x() + 1,
					  testAnim->getPosition().y()));
	});
	t.start(20);
}

// init statics
QGraphicsScene *GameView::scene = nullptr;
