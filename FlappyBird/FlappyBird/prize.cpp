#include "prize.h"
#include <QGraphicsPixmapItem>
#include <QPropertyAnimation>

Prize::Prize(QObject *parent) : QObject{parent}{

    QPixmap pic(":/resources/prizeImage/prizeImage-removebg-preview.png");
    setPixmap(pic);

    setPos(400, rand() % (550 - 100 + 1) + 100);

    crownAnimation = new QPropertyAnimation(this, "x" , this);
    crownAnimation->setStartValue(400);
    crownAnimation->setEndValue(-50);
    crownAnimation->setEasingCurve(QEasingCurve::Linear);
    crownAnimation->setDuration(3000);
    connect(crownAnimation, &QPropertyAnimation::finished, this, &QObject::deleteLater);
    crownAnimation->start();


}

void Prize::stopPrize(){
    crownAnimation->stop();
}

qreal Prize::x() const{
    return m_x;
}

void Prize::setX(qreal newX){

    m_x = newX;
    setPos(newX, yPos);
}
