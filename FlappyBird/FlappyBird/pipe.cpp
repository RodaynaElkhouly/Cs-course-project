#include "pipe.h"
#include "bird.h"
#include <QGraphicsScene>
#include <QGraphicsPixmapItem>
#include <QPropertyAnimation>
#include "game.h"

Pipe::Pipe() {
    Pipes = new QGraphicsPixmapItem(QPixmap(":/ressources/pipe/pillarr.png"));
    isPass = 0;
    yPosition = -(200 + rand() %(480 - 200 + 1));
    Pipes->setPos(500, yPosition);

    PipeAnimation = new QPropertyAnimation(this, "x", this);
    PipeAnimation->setStartValue(480);
    PipeAnimation->setEndValue(-200);
    PipeAnimation->setEasingCurve(QEasingCurve::Linear);
    PipeAnimation->setDuration(3000);

    connect(PipeAnimation, &QPropertyAnimation::finished, this, &Pipe::RemovePipe);

    PipeAnimation->start();
    addToGroup(Pipes);

}

bool Pipe::detectCollision(){

    QList <QGraphicsItem *> ItemsColliding = Pipes->collidingItems();
    foreach(QGraphicsItem *Item, ItemsColliding){
        Bird *birdItem =  dynamic_cast<Bird *>(Item);
        if(birdItem){
            return true;
        }
    }
    return false;
}

qreal Pipe::x() const
{
    return m_x;
}

void Pipe::setX(qreal newX)
{
    m_x = newX;
    if(detectCollision()){
        emit BirdCollisionWithPipe();
    }
    setPos(newX,yPosition);

    if (newX < 0 && !isPass){
        isPass = 1;
        QGraphicsScene * currentScene = scene();
        Game * myGame = dynamic_cast < Game * > (currentScene);
        myGame -> UpdateScore();

    }

}

void Pipe::stopPipe(){
    PipeAnimation->stop();
}

void Pipe::RemovePipe(){
    scene()->removeItem(this);
    delete this;
}
