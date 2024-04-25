#ifndef CROWN_H
#define CROWN_H

#include <QObject>
#include <QGraphicsPixmapItem>
#include <QPropertyAnimation>

class Crown:public QObject, public QGraphicsPixmapItem
{
    Q_OBJECT
    Q_PROPERTY(qreal x READ x WRITE setX);
public:
    Crown(QObject *parent = nullptr);
    qreal x() const;
    void setX(qreal newX);
    void stopPrize();
    bool detectCollision();
    QGraphicsPixmapItem *crown;
private:
    QPropertyAnimation *crownAnimation;
    int yPos;
    qreal m_x;
};

#endif // CROWN_H
