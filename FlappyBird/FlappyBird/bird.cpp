#include "bird.h"
#include "prize.h"
#include <QTimer>
#include <QGraphicsScene>
//construstor
Bird::Bird(QPixmap pixmap, int w, int h) : wing(WingPosition::Up), isWingDir(0), m_y(0)
{
    widthBird = w;
    heightBird = h;
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
//Destructors that checks if pointer objects are null if they are, it deletes them and resetes theyr pointer to null
Bird::~Bird(){
    if(BirdAnimation){
        BirdAnimation->stop();
        delete BirdAnimation;
        BirdAnimation = nullptr;
    }

    if(BirdRotation){
        BirdRotation->stop();
        delete BirdRotation;
        BirdRotation = nullptr;
    }
}
//function that controls the bird rotation
void Bird :: rotateTo(const qreal &end, const int &duration, const QEasingCurve &curve){

    BirdRotation->setStartValue(rotation());
    BirdRotation->setEndValue(end);
    BirdRotation->setEasingCurve(curve);
    BirdRotation->setDuration(duration);


}
//function that updates the bird wings positions
void Bird :: updatePixmap(){

    if (wing == WingPosition::Middle){

        if (isWingDir){
            setPixmap(QPixmap(":/ressources/bird/up.png").scaled(widthBird, heightBird));
            wing = WingPosition::Up;
            isWingDir = 0;
        }
        else {
            setPixmap(QPixmap(":/ressources/bird/down.png").scaled(widthBird, heightBird));
            wing = WingPosition::Down;
            isWingDir = 1;
        }
    }else{
        setPixmap(QPixmap(":/ressources/bird/middle.png").scaled(widthBird, heightBird));
        wing = WingPosition::Middle;
    }

}
//function that starts the animation of the bird
void Bird::startFlying(){

    BirdAnimation->start();
    BirdRotation->start();
}

//function that handles the animation of the bird jumping once the space bar key is pressed
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

//function that makes the bird falls so it doesn't keep going upwards
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

//function that stops the bird animation i.e stops the bird from flying
void Bird::stopFlying(){
    BirdAnimation->stop();
    BirdRotation->stop();

}
qreal Bird::y() const
{
    return m_y;
}

//Updates the new position of the bird
void Bird::setY(qreal newY)
{
    moveBy(0, (newY - m_y));
    m_y = newY;
}

qreal Bird::rotation() const
{
    return m_rotation;
}


//function that handles the transformation of the bird when it rotates
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







