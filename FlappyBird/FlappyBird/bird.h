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
    enum WingPosition{
        Up,
        Middle,
        Down,
    };
    void updatePixmap ();

    WingPosition wing;
    bool isWingDir;

    qreal m_y;
    qreal m_rotation;
    QPropertyAnimation * BirdAnimation;
    QPropertyAnimation * BirdRotation;
    qreal groundPos;

public:
    explicit Bird ( QPixmap pixmap, int, int);
    int widthBird;
    int heightBird;
    qreal y() const;
    qreal rotation() const;
    void Jump();
    void makeBirdFall();
    void startFlying();
    void stopFlying();
    void Collision();



signals:
public slots:
    void setRotation(qreal newRotation);
     void setY(qreal newY);
    void rotateTo(const qreal &end, const int& duration, const QEasingCurve& curve);
};

#endif // BIRD_H
