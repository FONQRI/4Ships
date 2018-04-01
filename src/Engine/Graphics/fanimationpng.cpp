#include "fanimationpng.h"
namespace FEngine2d {
namespace Graphics {

FAnimationPNG::FAnimationPNG(QObject *parent)
	: QObject(parent), m_currentImageIndex(0)
{
	m_currentGraphicsPixmapItem = new QGraphicsPixmapItem();
	connect(&m_timer, &QTimer::timeout, this, &FAnimationPNG::changeImage);
}

std::vector<QPixmap> FAnimationPNG::getImages() const { return images; }

void FAnimationPNG::setImages(const std::vector<QPixmap> &value)
{
	images = value;
}

void FAnimationPNG::addImage(QPixmap image) { images.push_back(image); }

void FAnimationPNG::removeImage(size_t index)
{
	images.erase(images.begin() + index);
}

void FAnimationPNG::addPosition(std::shared_ptr<QPointF> point)
{
	m_PosList.append(point);
}

void FAnimationPNG::setScene(QGraphicsScene *scene)
{
	m_scene = scene;
	m_scene->addItem(m_currentGraphicsPixmapItem);
}

int FAnimationPNG::delay() const { return m_delay; }

void FAnimationPNG::setDelay(int delay) { m_delay = delay; }

void FAnimationPNG::run() { m_timer.setInterval(m_delay / images.size()); }

void FAnimationPNG::stop() {}

void FAnimationPNG::changeImage()
{
	if (m_currentImageIndex + 1 < images.size()) {
	}
	else {
		m_currentImageIndex = 0;
	}
	m_currentGraphicsPixmapItem->setPixmap(images.at(m_currentImageIndex));
}
} // End of Graphics namespace
} // End of FEngine namespace
