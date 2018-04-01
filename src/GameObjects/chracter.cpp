#include "chracter.h"

Chracter::Chracter(QGraphicsItem *parent) : QGraphicsPixmapItem(parent) {}

Chracter::Chracter(const QPixmap &pixmap, QGraphicsItem *parent)
	: QGraphicsPixmapItem(pixmap, parent)
{
}
