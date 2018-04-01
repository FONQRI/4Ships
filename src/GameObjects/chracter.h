#ifndef CHRACTER_H
#define CHRACTER_H

#include <QGraphicsPixmapItem>

class Chracter : public QGraphicsPixmapItem {
  public:
	Chracter(QGraphicsItem *parent = nullptr);
	Chracter(const QPixmap &pixmap, QGraphicsItem *parent = nullptr);
};

#endif // CHRACTER_H
