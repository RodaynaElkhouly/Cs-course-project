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
    healthDisplay->setFont(QFont("Ariel", 16, QFont::Bold));
    healthDisplay->setDefaultTextColor(Qt::black);


    timerDisplay = new QGraphicsTextItem();
    timerDisplay->setFont(QFont("Ariel", 16, QFont::Bold));
    timerDisplay->setDefaultTextColor(Qt::black);


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
    isGameOver = 0;
    birdItem->startFlying();

    healthDisplay->setPlainText("Health: " + QString::number(Health));
    healthDisplay->setPos( QPointF(450 - healthDisplay->boundingRect().width(),(650 - healthDisplay->boundingRect().height())));
    addItem(healthDisplay);


    timerDisplay->setPlainText(formatTime(remainingTime));
    timerDisplay->setPos(QPointF(450 / 2 - timerDisplay->boundingRect().width(), 0));
    addItem(timerDisplay);

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

        FreezeScene();
    }


}

void Game::FreezeScene(){

    gameTimer->stop();
    birdItem->stopFlying();
    QList<QGraphicsItem *> ItemsInScene = items();
    foreach(QGraphicsItem *Item, ItemsInScene){
        Pipe *pipe = dynamic_cast<Pipe *>(Item);
        if(pipe){
            pipe->stopPipe();
        }

    }

    isGameOver = 1;
    Health--;  // Decrement health each time the scene freezes
    healthDisplay->setPlainText("Health: " + QString::number(Health));  // Update health display
    if (Health <= 0) {
        return;
    } else {
        QTimer::singleShot(1000, this, &Game::retryLevel);  // Delay before restart
    }

}


void Game::retryLevel(){
    cleanPipes();
    removeItem(timerDisplay);
    removeItem(healthDisplay);
    remainingTime = 60;
    setUpTimers();
    isGameOn = 0;

}


void Game::keyPressEvent(QKeyEvent *event){

    if(isGameOn == 0){
        startGame();
    }
    if(event->key() == Qt::Key_Space){
        if(isGameOver == 0){

            birdItem->Jump();


        }

    }

}
void Game::cleanPipes(){

    QList<QGraphicsItem *> ItemsInScene = items();
    foreach(QGraphicsItem *Item, ItemsInScene){
        Pipe *pipe = dynamic_cast<Pipe *>(Item);
        if(pipe){
            removeItem(pipe);
            delete pipe;
        }

    }



}



