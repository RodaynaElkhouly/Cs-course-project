#include "crown.h"
#include <QGraphicsPixmapItem>
#include <QPropertyAnimation>

Crown::Crown(QObject *parent) : QObject(parent) {

    crown = new QGraphicsPixmapItem(QPixmap(":/resources/prizeImage/prizeImage-removebg-preview.png"));
    crown->setPos(400, rand() % (550 - 100 + 1) + 100);


    crownAnimation = new QPropertyAnimation(this, "x" , this);
    crownAnimation->setStartValue(400);
    crownAnimation->setEndValue(-50);
    crownAnimation->setEasingCurve(QEasingCurve::Linear);
    crownAnimation->setDuration(3000);

    connect(crownAnimation, &QPropertyAnimation::finished, this, &QObject::deleteLater);
    crownAnimation->start();

}

qreal Crown::x() const
{
    return m_x;
}

void Crown::setX(qreal newX)
{
    m_x = newX;
    setPos(newX, yPos);
}
