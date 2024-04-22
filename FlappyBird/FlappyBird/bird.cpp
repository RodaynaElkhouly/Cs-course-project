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
    groundPos = scenePos().y() + 550;
    yAnimation = new QPropertyAnimation(this,"y",this);
    yAnimation->setStartValue(scenePos().y());
    yAnimation->setEndValue(groundPos);
    yAnimation->setEasingCurve(QEasingCurve::InQuad);
    yAnimation->setDuration(1000);
    yAnimation->start();
    rotationAnimation = new QPropertyAnimation(this,"rotation",this);
    rotateTo(90,1200,QEasingCurve::InQuad);


}
void Bird :: rotateTo(const qreal &end, const int &duration, const QEasingCurve &curve){
    rotationAnimation->setStartValue(rotation());
    rotationAnimation->setEndValue(end);
    rotationAnimation->setEasingCurve(curve);
    rotationAnimation->setDuration(duration);

    rotationAnimation->start();
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
    moveBy(0,newY-m_y);
    m_y = newY;
}

qreal Bird::rotation() const
{
    return m_rotation;
}

void Bird::setRotation(qreal newRotation)
{
    m_rotation = newRotation;
    QPointF c = boundingRect().center();
    QTransform t;
    t.translate(c.x(), c.y());
    t.rotate(newRotation);
    t.translate(-c.x(), -c.y());
    setTransform(t);
}
