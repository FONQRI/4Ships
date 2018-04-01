#include "timerbar.h"

TimerBar::TimerBar(QGraphicsItem *parent) : QGraphicsPixmapItem(parent) {}

TimerBar::TimerBar(const QPixmap &pixmap, QGraphicsItem *parent)
	: QGraphicsPixmapItem(pixmap, parent)
{
}
