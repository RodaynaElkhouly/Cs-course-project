#include "game.h"
#include "bird.h"
#include "pipe.h"
#include "ground.h"

#include <QObject>
#include <QGraphicsScene>
#include <QGraphicsPixmapItem>
#include <QTimer>


Game::Game(QObject *parent) : QGraphicsScene(parent) {
    setUpTimers();
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


}
