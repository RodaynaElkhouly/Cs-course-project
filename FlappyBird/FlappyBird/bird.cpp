#include "bird.h"
#include "prize.h"
#include <QTimer>
#include <QGraphicsScene>
Bird::Bird(QPixmap pixmap) : wing(WingPosition::Up), isWingDir(0), m_y(0)
{

    setPixmap (pixmap);

    QTimer * wingTimer= new QTimer(this);
    connect(wingTimer, &QTimer::timeout, this, &Bird::updatePixmap);
    wingTimer->start(60);

    groundPos = scenePos().y() + 550;

    BirdAnimation = new QPropertyAnimation(this,"y",this);
    BirdAnimation->setStartValue(scenePos().y());
    BirdAnimation->setEndValue(groundPos);
    BirdAnimation->setEasingCurve(QEasingCurve::InQuad);
    BirdAnimation->setDuration(1000);


    BirdRotation = new QPropertyAnimation(this, "rotation" ,this);
    rotateTo(90,1200,QEasingCurve::InQuad);


}
void Bird :: rotateTo(const qreal &end, const int &duration, const QEasingCurve &curve){

    BirdRotation->setStartValue(rotation());
    BirdRotation->setEndValue(end);
    BirdRotation->setEasingCurve(curve);
    BirdRotation->setDuration(duration);


}
void Bird :: updatePixmap(){

    if (wing == WingPosition::Middle){

        if (isWingDir){
            setPixmap(QPixmap(":/ressources/bird/up.png"));
            wing = WingPosition::Up;
            isWingDir = 0;
        }
        else {
            setPixmap(QPixmap(":/ressources/bird/down.png"));
            wing = WingPosition::Down;
            isWingDir = 1;
        }
    }else{
        setPixmap(QPixmap(":/ressources/bird/middle.png"));
        wing = WingPosition::Middle;
    }

}
void Bird::startFlying(){


    BirdAnimation->start();
    BirdRotation->start();
}
void Bird::Jump(){
    BirdAnimation->stop();
    BirdRotation->stop();

    qreal yPos = y();
    BirdAnimation->setStartValue(yPos);
    BirdAnimation->setEndValue(y() - 50);
    BirdAnimation->setEasingCurve(QEasingCurve::OutQuad);
    BirdAnimation->setDuration(250);

    connect(BirdAnimation, &QPropertyAnimation::finished, this,  &Bird::makeBirdFall);
    BirdAnimation->start();

    rotateTo(-20, 200, QEasingCurve::OutCubic);
    BirdRotation->start();


}
void Bird::makeBirdFall(){
    if(y() < groundPos){
        BirdRotation->stop();

        BirdAnimation->setStartValue(y());
        BirdAnimation->setEndValue(groundPos);
        BirdAnimation->setEasingCurve(QEasingCurve::InQuad);
        BirdAnimation->setDuration(1100);
        BirdAnimation->start();

        rotateTo(90, 1100, QEasingCurve::InCubic);
        BirdRotation->start();



    }

}
void Bird::stopFlying(){
    BirdAnimation->stop();
    BirdRotation->stop();

}
qreal Bird::y() const
{
    return m_y;
}

void Bird::setY(qreal newY)
{
    moveBy(0, (newY - m_y));
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


