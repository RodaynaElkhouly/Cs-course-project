#include "game.h"
#include "bird.h"
#include "pipe.h"
#include "bird.h"

#include <QObject>
#include <QGraphicsScene>
#include <QGraphicsPixmapItem>
#include <QKeyEvent>
#include <QTimer>


Game::Game(QObject *parent) : QGraphicsScene(parent), Health(3), Score(0) , remainingTime(60) , itemsToCollect(3) ,
    BestScore(0){

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

    itemDisplay = new QGraphicsTextItem();
    itemDisplay->setFont(QFont("Ariel", 16, QFont::Bold));
    itemDisplay->setDefaultTextColor(Qt::black);

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


    itemDisplay->setPlainText("Crowns: " + QString::number(itemsToCollect));
    itemDisplay->setPos(QPointF(0, 650 - timerDisplay->boundingRect().height()));
    addItem(itemDisplay);



    if(!pipeTimer->isActive()){
        pipeTimer->start(2000);
    }

    if(!gameTimer->isActive()){
        gameTimer->start(1000);
    }

    if(!prizeTimer->isActive()){
        prizeTimer->start(2000);
    }

}

void Game::setUpTimers(){
    pipeTimer = new QTimer(this);
    connect(pipeTimer, &QTimer::timeout, this, &Game::spawnPipe);

    gameTimer = new QTimer;
    connect(gameTimer, &QTimer::timeout, this, &Game::UpdateTime);

    prizeTimer = new QTimer;
    connect(prizeTimer, &QTimer::timeout, this, &Game::spawnPrizes);

}

void Game::UpdateScore() {
    Score++;
    if (Score > BestScore )
        BestScore = Score;
}

void Game::spawnPrizes(){

    prizes = new Prize;
    connect(prizes, &Prize::ItemCollected, this, &Game::handleItemCollected);
    addItem(prizes);



}

void Game::handleItemCollected(){
    itemsToCollect--;

    itemDisplay->setPlainText("Crowns: " + QString::number(itemsToCollect));
    itemDisplay->setPos(QPointF(0, 650 - timerDisplay->boundingRect().height()));
    if(itemsToCollect == 0){

        prizeTimer->stop();
        gameTimer->stop();
        birdItem->stopFlying();
        pipeTimer->stop();
        QList<QGraphicsItem *> ItemsInScene = items();
        foreach(QGraphicsItem *Item, ItemsInScene){
            Pipe *pipe = dynamic_cast<Pipe *>(Item);
            if(pipe){
                pipe->stopPipe();
            }

        }
        foreach(QGraphicsItem *Item, ItemsInScene){
            Prize *prize = dynamic_cast<Prize *>(Item);
            if(prize){
                prize->stopPrize();
            }

        }
    }


}

void Game::spawnPipe(){
    pipeItem = new Pipe;
    connect(pipeItem, &Pipe::BirdCollisionWithPipe, this , &Game::handlePipeCollision);
    addItem(pipeItem);
}

void Game::handlePipeCollision(){

    pipeTimer->stop();
    FreezeScene();
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

    prizeTimer->stop();
    gameTimer->stop();
    birdItem->stopFlying();
    QList<QGraphicsItem *> ItemsInScene = items();
    foreach(QGraphicsItem *Item, ItemsInScene){
        Pipe *pipe = dynamic_cast<Pipe *>(Item);
        if(pipe){
            pipe->stopPipe();
        }

    }
    foreach(QGraphicsItem *Item, ItemsInScene){
        Prize *prize = dynamic_cast<Prize *>(Item);
        if(prize){
            prize->stopPrize();
        }

    }

    isGameOver = 1;
    Health--;
    healthDisplay->setPlainText("Health: " + QString::number(Health));

    if(Health <= 0){
        return;
    }
    else{

        QTimer::singleShot(1000, this, &Game::retryLevel);
    }

}


void Game::retryLevel(){
    cleanPrizes();
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

void Game::cleanPrizes(){

    QList<QGraphicsItem *> ItemsInScene = items();
    foreach(QGraphicsItem *Item, ItemsInScene){
        Prize *prizes = dynamic_cast<Prize *>(Item);
        if(prizes){
            removeItem(prizes);
            delete prizes;
        }

    }


}

void Game::displayYouWon(){

    YouWon = new QGraphicsPixmapItem;


}
