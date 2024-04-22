#ifndef BIRD_H
#define BIRD_H
#include <QObject>
#include <QGraphicsPixmapItem>
#include <QPropertyAnimation>

class Bird : public QObject , public QGraphicsPixmapItem
{
    Q_OBJECT
    Q_PROPERTY (qreal y READ y WRITE setY)
    Q_PROPERTY (qreal rotation READ rotation WRITE setRotation)

private:
    enum WingPos{
        Up,
        Middle,
        Down,
    };
    void updatePixmap ();

    WingPos wingPos;
    bool WingDir ;

    qreal m_y;

public:
   explicit Bird ( QPixmap pixmap);


   qreal y() const;
   void setY(qreal newY);
};

#endif // BIRD_H
