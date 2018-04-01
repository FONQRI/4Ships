#ifndef BULLET_H
#define BULLET_H
#include <QGraphicsPixmapItem>

class Bullet : public QGraphicsPixmapItem {
  public:
	Bullet(QGraphicsItem *parent = nullptr);
	Bullet(const QPixmap &pixmap, QGraphicsItem *parent = nullptr);
};

#endif // BULLET_H
