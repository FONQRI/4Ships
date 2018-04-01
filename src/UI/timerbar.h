#ifndef TIMERBAR_H
#define TIMERBAR_H

#include <QGraphicsPixmapItem>

class TimerBar : public QGraphicsPixmapItem {
  public:
	TimerBar(QGraphicsItem *parent = nullptr);
	TimerBar(const QPixmap &pixmap, QGraphicsItem *parent = nullptr);
};

#endif // TIMERBAR_H
