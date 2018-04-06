#include "fanimationpng.h"
#include <QDebug>
#include <iostream>

namespace FEngine2d {
namespace Graphics {

FAnimationPNG::FAnimationPNG(QGraphicsScene *scene,
				 std::vector<std::shared_ptr<QPixmap>> images,
				 QPointF position, bool selfDestruct,
				 QObject *parent)
	: QObject(parent), m_duration(1000), m_isRunning(false), shouldStop(false),
	  m_scene(scene), m_images(images), m_Position(position),
	  m_currentImageIndex(0), m_rotation(0), m_selfDestruct(selfDestruct)
{

	m_currentGraphicsPixmapItem = new QGraphicsPixmapItem();
	connect(&m_timer, &QTimer::timeout, this, &FAnimationPNG::changeImage);

	m_currentGraphicsPixmapItem->setPixmap(*(m_images.at(0).get()));
	m_scene->addItem(m_currentGraphicsPixmapItem);
	m_currentGraphicsPixmapItem->setPos(position);

	updateTransformOriginPoint();
}

std::vector<std::shared_ptr<QPixmap>> FAnimationPNG::getImages() const
{
	return m_images;
}

void FAnimationPNG::setImages(
	const std::vector<std::shared_ptr<QPixmap>> &value)
{
	m_images = value;
}

void FAnimationPNG::addImage(std::shared_ptr<QPixmap> image)
{
	m_images.push_back(image);
}

void FAnimationPNG::removeImage(size_t index)
{
	m_images.erase(m_images.begin() + index);
}

int FAnimationPNG::getDuration() const { return m_duration; }

void FAnimationPNG::setDuration(int duration) { m_duration = duration; }

QPointF FAnimationPNG::getPosition() const { return m_Position; }

void FAnimationPNG::setPosition(const QPointF &Position)
{
	m_Position = Position;
	m_currentGraphicsPixmapItem->setPos(Position);
}

size_t FAnimationPNG::getRotation() const { return m_rotation; }

void FAnimationPNG::setRotation(const size_t &rotation)
{
    m_rotation = rotation;
	m_currentGraphicsPixmapItem->setRotation(m_rotation);
}

void FAnimationPNG::updateTransformOriginPoint()
{
	m_currentGraphicsPixmapItem->setTransformOriginPoint(
	m_images.at(0)->size().width() / 2,
	m_images.at(0)->size().height() / 2);
}

void FAnimationPNG::updateTransformOriginPoint(const QPointF &newOriginPoint)
{
	m_currentGraphicsPixmapItem->setTransformOriginPoint(newOriginPoint);
}

bool FAnimationPNG::isSelfDestruct() const { return m_selfDestruct; }

void FAnimationPNG::setSelfDestruct(bool selfDestruct)
{
	m_selfDestruct = selfDestruct;
}

void FAnimationPNG::setScene(QGraphicsScene *scene)
{
	m_scene = scene;
	m_scene->addItem(m_currentGraphicsPixmapItem);
}

void FAnimationPNG::run()
{
	m_timer.setInterval(m_duration / m_images.size());
	m_timer.start();
}

void FAnimationPNG::stop() {}

void FAnimationPNG::forceStop() { m_timer.stop(); }

void FAnimationPNG::changeImage()
{
	if (m_currentImageIndex >= m_images.size()) {
		m_currentImageIndex = 0;

		// check if animation should stop
		if (shouldStop || m_selfDestruct) {
			forceStop();
			emit stopped();
		}
	}

	m_currentGraphicsPixmapItem->setPixmap(
	*(m_images.at(m_currentImageIndex).get()));
	m_currentImageIndex++;
}
} // End of Graphics namespace
} // End of FEngine namespace
