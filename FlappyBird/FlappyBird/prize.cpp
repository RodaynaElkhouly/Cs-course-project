#include "prize.h"
#include "bird.h"
#include <QGraphicsPixmapItem>
#include <QPropertyAnimation>
#include <QGraphicsScene>

Prize::Prize(QObject *parent) : QObject(parent) {

    pixmapItem = new QGraphicsPixmapItem(QPixmap(":/resources/prizeImage/prizeImage-removebg-preview.png"), this);
    pixmapItem->setPos(-pixmapItem->boundingRect().width()/2, -pixmapItem->boundingRect().height()/2); // Center the pixmap

    setPos(400, rand() % (550 - 100 + 1) + 100);

    crownAnimation = new QPropertyAnimation(this, "x" , this);
    crownAnimation->setStartValue(400);
    crownAnimation->setEndValue(-50);
    crownAnimation->setEasingCurve(QEasingCurve::Linear);
    crownAnimation->setDuration(3000);

    connect(crownAnimation, &QPropertyAnimation::finished, this, &QObject::deleteLater);
    crownAnimation->start();


}
bool Prize::detectCollision(){
    QList <QGraphicsItem *> ItemsColliding = pixmapItem->collidingItems();
    foreach(QGraphicsItem *Item, ItemsColliding){
        Bird *birdItem =  dynamic_cast<Bird *>(Item);
        if(birdItem){
            return true;
        }
    }
    return false;





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
