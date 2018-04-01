#include "bullet.h"

Bullet::Bullet(QGraphicsItem *parent) : QGraphicsPixmapItem(parent) {}

Bullet::Bullet(const QPixmap &pixmap, QGraphicsItem *parent)
	: QGraphicsPixmapItem(pixmap, parent)
{
}
