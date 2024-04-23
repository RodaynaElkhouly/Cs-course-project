#include "game.h"
#include "bird.h"
#include "pipe.h"
#include "bird.h"
#include "ground.h"

#include <QObject>
#include <QGraphicsScene>
#include <QGraphicsPixmapItem>
#include <QKeyEvent>
#include <QTimer>


Game::Game(QObject *parent) : QGraphicsScene(parent), Health(3), Score(0) , remainingTime(60){

    setSceneRect(0, 0, 450, 650);
    BackgroundPic = new QGraphicsPixmapItem(QPixmap(":/ressources/backgroundimage/Background.jpg"));
    addItem(BackgroundPic);
    BackgroundPic->setPos(QPointF(0,0));

    healthDisplay = new QGraphicsTextItem();
    healthDisplay->setPlainText("Health: " + QString::number(Health));
    healthDisplay->setFont(QFont("Ariel", 16, QFont::Bold));
    healthDisplay->setDefaultTextColor(Qt::black);
    healthDisplay->setPos( QPointF(450 - healthDisplay->boundingRect().width(),(650 - healthDisplay->boundingRect().height())));
    addItem(healthDisplay);

    timerDisplay = new QGraphicsTextItem();
    timerDisplay->setPlainText(formatTime(remainingTime));
    timerDisplay->setFont(QFont("Ariel", 16, QFont::Bold));
    timerDisplay->setDefaultTextColor(Qt::black);
    timerDisplay->setPos(QPointF(450 / 2 - timerDisplay->boundingRect().width(), 0));
    addItem(timerDisplay);

    spawnBird();
    setUpTimers();

}

QString Game::formatTime(int seconds){
    int minutes = seconds / 60;
    int sec = seconds % 60;
    return QString("%1:%2").arg(minutes,2, 10, QLatin1Char('0')).arg(sec, 2, 10, QLatin1Char('0'));
}

void Game::spawnBird(){

    birdItem = new Bird(QPixmap(":/ressources/bird/up.png"));
    addItem(birdItem);

}

void Game::startGame(){

    isGameOn = 1;
    birdItem->startFlying();

    if(!pipeTimer->isActive()){
        pipeTimer->start(2000);
    }

    if(!gameTimer->isActive()){
        gameTimer->start(1000);
    }

}

void Game::setUpTimers(){
    pipeTimer = new QTimer(this);
    connect(pipeTimer, &QTimer::timeout, this, &Game::spawnPipe);

    gameTimer = new QTimer;
    connect(gameTimer, &QTimer::timeout, this, &Game::UpdateTime);

}

void Game::spawnPipe(){
    pipeItem = new Pipe;
    connect(pipeItem, &Pipe::BirdCollisionWithPipe, [=](){
        pipeTimer->stop();
        FreezeScene();
    });
    addItem(pipeItem);
}
void Game::UpdateTime(){
    remainingTime--;
    timerDisplay->setPlainText(formatTime(remainingTime));
    timerDisplay->setPos(QPointF(450 / 2 - timerDisplay->boundingRect().width(), 0));

    if(remainingTime == 0){
        gameTimer->stop();
        FreezeScene();

    }


}

void Game::FreezeScene(){
    birdItem->stopFlying();
    QList<QGraphicsItem *> ItemsInScene = items();
    foreach(QGraphicsItem *Item, ItemsInScene){
        Pipe *pipe = dynamic_cast<Pipe *>(Item);
        if(pipe){
            pipe->stopPipe();
        }

    }




}
void Game::keyPressEvent(QKeyEvent *event){

    if(isGameOn == 0){
        startGame();
    }
    if(event->key() == Qt::Key_Space){

        birdItem->Jump();

    }




}
