#include "healthbar.h"

HealthBar::HealthBar(QGraphicsItem *parent) : QGraphicsPixmapItem(parent) {}

HealthBar::HealthBar(const QPixmap &pixmap, QGraphicsItem *parent)
	: QGraphicsPixmapItem(pixmap, parent)
{
}
