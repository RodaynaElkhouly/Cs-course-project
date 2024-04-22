#include "bird.h"
#include <QTimer>
Bird::Bird(QPixmap pixmap) :
    wingPos(WingPos::Up),
    WingDir(0)

{
    setPixmap (pixmap);
    QTimer * wingtimer= new QTimer(this);
    connect(wingtimer, &QTimer::timeout,[=](){
        updatePixmap();
    });

    wingtimer->start(60);
}

void Bird :: updatePixmap(){

    if (wingPos == WingPos::Middle){

        if (WingDir){
            setPixmap(QPixmap(":/ressources/bird/up.png"));
            wingPos=WingPos::Up;
            WingDir=0;
        }
     else {
        setPixmap(QPixmap(":/ressources/bird/down.png"));
        wingPos=WingPos::Down;
        WingDir=1;
    }
    }else{
        setPixmap(QPixmap(":/ressources/bird/middle.png"));
        wingPos=WingPos::Middle;
    }

}

qreal Bird::y() const
{
    return m_y;
}

void Bird::setY(qreal newY)
{
    m_y = newY;
}
