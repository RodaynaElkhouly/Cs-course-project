#include "pipe.h"
#include <QGraphicsScene>
#include <QGraphicsPixmapItem>
#include <QPropertyAnimation>

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


qreal Pipe::x() const
{
    return m_x;
}

void Pipe::setX(qreal newX)
{
    m_x = newX;
    setPos(newX,yPosition);

}

void Pipe::RemovePipe(){
    scene()->removeItem(this);
    delete this;
}
