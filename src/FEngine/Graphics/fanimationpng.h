/**


  */
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

/**
* @brief The FAnimationPNG class
*/
class FAnimationPNG : public QObject {
	Q_OBJECT
  public:
	/**
	 * @brief FAnimationPNG : constructor of class
	 * @param scene : scene pointer to show animation on that
	 * @param images : images of animation
	 * @param point : first point that show animation in view
	 * @param parent : QObject parrent
	 */
	explicit FAnimationPNG(QGraphicsScene *scene,
			   std::vector<std::shared_ptr<QPixmap>> images,
			   QPointF position, bool selfDestruct = false,
			   QObject *parent = nullptr);

	/**
	 * @brief setScene : set scene for animation
	 * @param scene
	 */
	void setScene(QGraphicsScene *scene);

	/**
	 * @brief getImages : get images vector
	 * @return  images vector
	 */
	std::vector<std::shared_ptr<QPixmap>> getImages() const;

	/**
	 * @brief setImages : set a vector for image vector of animation
	 * @param value : vector of shared_ptr of QPixmap to set as images vector
	 */
	void setImages(const std::vector<std::shared_ptr<QPixmap>> &value);

	/**
	 * @brief addImage : add and remove image from vector of animation
	 * @param image : a shared_ptr of QPixmap to add to images list of animation
	 */
	void addImage(std::shared_ptr<QPixmap> image);

	/**
	 * @brief removeImage : remove image from image list of animation
	 * @param index : index of image that should be removed
	 */
	void removeImage(size_t index);

	// get and set duration

	/**
	 * @brief getDuration : get duration
	 * @return duration
	 */
	int getDuration() const;

	/**
	 * @brief setDuration set duration
	 * @param duration
	 */
	void setDuration(int duration);

	/**
	 * @brief getPosition : return position of animation in scene
	 * @return Position
	 */
	QPointF getPosition() const;

	/**
	 * @brief setPosition : set position of animation
	 * @param Position
	 */
	void setPosition(const QPointF &Position);

	/**
	 * @brief getRotation : return rotation of animation
	 * @return rotation
	 */
	size_t getRotation() const;

	/**
	 * @brief setRotation :set rotation of animation from OriginPoint
	 * @param rotation
	 */
	void setRotation(const size_t &rotation);

	/**
	 * @brief updateTransformOriginPoint
	 */
	void updateTransformOriginPoint();

	/**
	 * @brief updateTransformOriginPoint
	 * @param newOriginPoint
	 */
	void updateTransformOriginPoint(const QPointF &newOriginPoint);

	/**
	 * @brief isSelfDestruct : retuen true if animation should play only one
	 * time
	 * @return selfDestruct : retuen true if animation should play only one time
	 */
	bool isSelfDestruct() const;

	/**
	 * @brief setSelfDestruct set true if animation should only one time
	 * @param selfDestruct
	 */
	void setSelfDestruct(bool selfDestruct);

  private:
	// duration of animation
	int m_duration;

	// true if is running
	bool m_isRunning;

	// true if animation should stop
	bool shouldStop;

	// scene that containing animation
	QGraphicsScene *m_scene;

	// timer for making animation
	QTimer m_timer;

	// current pixmap item that is showing in scene
	QGraphicsPixmapItem *m_currentGraphicsPixmapItem;

	// animation images vector
	std::vector<std::shared_ptr<QPixmap>> m_images;

	// position list that animation will be shown on them
	QPointF m_Position;

	// index of current image of animation
	size_t m_currentImageIndex;

	// rotation of animation
	size_t m_rotation;

	// true if animation should inly play one time
	bool m_selfDestruct;
	/**
	 * @brief change image to next one for animation
	 */
	void changeImage();

  signals:

	/**
	 * @brief stopped : call when animation stopped normally (Animation runs to
	 * the end)
	 */
	void stopped();

  public slots:

	/**
	 * @brief run :  run animation
	 */
	void run();

	/**
	 * @brief stop : stop animation normally and call stopped signal after that
	 */
	void stop();

	/**
	 * @brief forceStop : stop animation forcely
	 */
	void forceStop();
};
} // End of Graphics namespace
} // End of FEngine namespace

#endif // FENGINE_GRAPHICS_FAnimationPNG_H
