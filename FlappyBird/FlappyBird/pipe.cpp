#include "pipe.h"
#include <QGraphicsPixmapItem>
Pipe::Pipe() {
    Pipes = new QGraphicsPixmapItem(QPixmap(":/ressources/pipe/pillarr.png"));
    isPass = 0;
    int yPosition = -(200 + rand() %(480 - 200 + 1));
    Pipes->setPos(0, yPosition);
    addToGroup(Pipes);




}
