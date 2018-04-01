#ifndef FENGINE_GRAPHICS_FAnimationPNG_H
#define FENGINE_GRAPHICS_FAnimationPNG_H

// qt
#include <QGraphicsPixmapItem>
#include <QGraphicsScene>
#include <QList>
#include <QObject>
#include <QPointF>
#include <QTimer>

// pure c++
#include <memory>
#include <vector>

namespace FEngine2d {
namespace Graphics {

// TODO add shake by rotation
class FAnimationPNG : public QObject {
	Q_OBJECT
  public:
	explicit FAnimationPNG(QObject *parent = nullptr);

	void addPosition(std::shared_ptr<QPointF> point);

	void setScene(QGraphicsScene *scene);

	int delay() const;
	void setDelay(int delay);

	std::vector<QPixmap> getImages() const;
	void setImages(const std::vector<QPixmap> &value);
	void addImage(QPixmap image);
	void removeImage(size_t index);

  private:
	QList<std::shared_ptr<QPointF>> m_PosList;

	// delay between every two images to show
	int m_delay;
	bool m_isRunning;

	size_t m_currentImageIndex;

	QGraphicsScene *m_scene;

	QTimer m_timer;

	QGraphicsPixmapItem *m_currentGraphicsPixmapItem;

	// animation images
	std::vector<QPixmap> images;

	void changeImage();

  signals:

  public slots:

	void run();
	void stop();
};
} // End of Graphics namespace
} // End of FEngine namespace

#endif // FENGINE_GRAPHICS_FAnimationPNG_H
