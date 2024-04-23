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


Game::Game(QObject *parent) : QGraphicsScene(parent) {
    setSceneRect(0, 0, 450, 650);
    BackgroundPic = new QGraphicsPixmapItem(QPixmap(":/ressources/backgroundimage/Background.jpg"));
    addItem(BackgroundPic);
    BackgroundPic->setPos(QPointF(0,0));
    spawnBird();

    setUpTimers();

}

void Game::spawnBird(){
    birdItem = new Bird(QPixmap(":/ressources/bird/up.png"));
    addItem(birdItem);

}

void Game::startGame(){

    isGameOn = 1;
    if(!pipeTimer->isActive()){
        pipeTimer->start(2000);
    }


}

void Game::setUpTimers(){
    pipeTimer = new QTimer(this);
    connect(pipeTimer, &QTimer::timeout, [=](){
        pipeItem = new Pipe;
        addItem(pipeItem);

    });
}

void Game::spawnPipe(){

}

void Game::keyPressEvent(QKeyEvent *event){

    if(isGameOn == 0){
        startGame();
    }
    if(event->key() == Qt::Key_Space){

        birdItem->Jump();

    }




}
