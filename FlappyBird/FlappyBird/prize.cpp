#include "prize.h"
#include "bird.h"
#include <QGraphicsPixmapItem>
#include <QPropertyAnimation>
#include <QGraphicsScene>


//Constructor
Prize::Prize(QObject *parent) : QObject(parent) {

    Crown = new QGraphicsPixmapItem(QPixmap(":/resources/prizeImage/prizeImage-removebg-preview.png"), this);
    Crown->setPos(-Crown->boundingRect().width() / 2 , -Crown->boundingRect().height() /2);
    yPos = rand() % (550 - 100) + 100;
    setPos(400,yPos);


    crownAnimation = new QPropertyAnimation(this, "x" , this);
    crownAnimation->setStartValue(400);
    crownAnimation->setEndValue(-50);
    crownAnimation->setEasingCurve(QEasingCurve::Linear);
    crownAnimation->setDuration(2000);

    connect(crownAnimation, &QPropertyAnimation::finished, this, &QObject::deleteLater);
    crownAnimation->start();


}

//A function that detects whether the bird collides with the crown to remove it from the scene and send a signal to handle the collision
void Prize::detectCollision(){


    QList<QGraphicsItem *> CollidingItems = Crown->collidingItems();
    for(int i = 0; i < CollidingItems.size(); i++){
        if(typeid(*(CollidingItems[i])) == typeid(Bird)){
            emit ItemCollected();
            scene()->removeItem(this);
            delete this;

        }

    }




}



//Function that stops the animaton of the prive
void Prize::stopPrize(){
    crownAnimation->stop();
}

qreal Prize::x() const{
    return m_x;
}

//Everytime the x position updates, we will detect collison

void Prize::setX(qreal newX){

    m_x = newX;
    detectCollision();
    setPos(newX, yPos);
}
