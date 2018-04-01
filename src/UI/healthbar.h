#ifndef HEALTHBAR_H
#define HEALTHBAR_H

#include <QGraphicsPixmapItem>

class HealthBar : public QGraphicsPixmapItem {
  public:
	HealthBar(QGraphicsItem *parent = nullptr);
	HealthBar(const QPixmap &pixmap, QGraphicsItem *parent = nullptr);
};

#endif // HEALTHBAR_H
