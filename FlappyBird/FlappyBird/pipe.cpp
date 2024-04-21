#include "pipe.h"
#include "game.h"
#include <QGraphicsPixmapItem>
#include <QPropertyAnimation>

Pipe::Pipe() {
    Pipes = new QGraphicsPixmapItem(QPixmap(":/ressources/pipe/pillarr.png"));
    isPass = 0;
    yPosition = -(200 + rand() %(480 - 200 + 1));
    Pipes->setPos(500, yPosition);

}

qreal Pipe::x() const
{
    return m_x;
}

void Pipe::setX(qreal newX)
{
    m_x = newX;

}
