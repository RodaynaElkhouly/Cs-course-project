#ifndef PRIZE_H
#define PRIZE_H

#include <QObject>
#include <QGraphicsPixmapItem>
#include <QPropertyAnimation>

class Prize :public QObject, public QGraphicsPixmapItem
{
    Q_OBJECT
    Q_PROPERTY(qreal x READ x WRITE setX);
public:
    Prize(QObject *parent = nullptr);
    qreal x() const;
    void setX(qreal newX);
    void stopPrize();
    void detectCollision();
    QGraphicsPixmapItem *Crown ;

private:

    QPropertyAnimation *crownAnimation;
    int yPos;

    qreal m_x;

signals:
    void ItemCollected();
};

#endif // PRIZE_H
