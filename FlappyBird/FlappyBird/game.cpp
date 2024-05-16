#include "game.h"
#include "bird.h"
#include "pipe.h"
#include "bird.h"
#include <QObject>
#include <QGraphicsScene>
#include <QGraphicsView>
#include <QGraphicsPixmapItem>
#include <QKeyEvent>
#include <QTimer>
#include <QDebug>


Game::Game(int level, int h, int score, int time, int items, int w, int hh, QObject *parent) : QGraphicsScene(parent), currentLevel(level), Health(h), Score(0) , remainingTime(time) , itemsToCollect(items) ,
    BestScore(score){

    levelTime = time;
    wBird = w;
    hBird = hh;
    setSceneRect(0, 0, 450, 650); //Intializing Scene and setting width and height

    PipeCollisionSound = new QMediaPlayer();
    PipeCollisionAudio = new QAudioOutput();
    PipeCollisionSound->setSource(QUrl("qrc:/resources/audios/PipeCollision.mp3"));
    PipeCollisionSound->setAudioOutput(PipeCollisionAudio);
    PipeCollisionAudio->setVolume(50);


    FlappingSound = new QMediaPlayer();
    FlappinAudio = new QAudioOutput();
    FlappingSound->setSource(QUrl("qrc:/resources/audios/FlappingSound.mp3"));
    FlappingSound->setAudioOutput(FlappinAudio);
    FlappinAudio->setVolume(50);



    PointSound = new QMediaPlayer();
    PointAudio = new QAudioOutput();
    PointSound->setSource(QUrl("qrc:/resources/audios/Point.mp3"));
    PointSound->setAudioOutput(PointAudio);
    PointAudio->setVolume(50);


    BackgroundSound = new QMediaPlayer();
    BackgroundAudio = new QAudioOutput();
    BackgroundSound->setSource(QUrl("qrc:/resources/audios/Background.mp3"));
    BackgroundSound->setAudioOutput(BackgroundAudio);
    BackgroundAudio->setVolume(100);





    //Intializing background Image
    BackgroundPic = new QGraphicsPixmapItem(QPixmap(":/ressources/backgroundimage/Background.jpg"));
    addItem(BackgroundPic);
    BackgroundPic->setPos(QPointF(0,0));

    //Intializing start Image
    startImage = new QGraphicsPixmapItem (QPixmap(":/resources/startimage/Overlay.png"));
    addItem (startImage);
    startImage->setPos(QPointF(0,0));

    //Displaying Health in scene
    healthDisplay = new QGraphicsTextItem();
    healthDisplay->setFont(QFont("Times new Roman", 16, QFont::Bold));
    healthDisplay->setDefaultTextColor(Qt::black);

    //Displaying Timer in scene
    timerDisplay = new QGraphicsTextItem();
    timerDisplay->setFont(QFont("Times new Roman", 16, QFont::Bold));
    timerDisplay->setDefaultTextColor(Qt::black);

    //Displaying items to collect in scene
    itemDisplay = new QGraphicsTextItem();
    itemDisplay->setFont(QFont("Times new Roman", 16, QFont::Bold));
    itemDisplay->setDefaultTextColor(Qt::black);

    levelDisplay = new QGraphicsTextItem();
    levelDisplay->setFont(QFont("Times new Roman", 16, QFont::Bold));
    levelDisplay->setDefaultTextColor(Qt::black);

    spawnBird(wBird, hBird);

    setUpTimers();

}

//destructor that checks if objects are not null, if theyre not it deletes them and resets them to null

Game::~Game(){
    if(pipeTimer){
        pipeTimer->stop();
        delete pipeTimer;
        pipeTimer = nullptr;
    }

    if(gameTimer){
        gameTimer->stop();
        delete gameTimer;
        pipeTimer = nullptr;

    }

    if(prizeTimer){
        prizeTimer->stop();
        delete prizeTimer;
        prizeTimer = nullptr;
    }

    delete PipeCollisionAudio;
    delete PipeCollisionSound;

    delete FlappinAudio;
    delete FlappingSound;

    delete PointSound;
    delete PointAudio;

    delete BackgroundSound;
    delete BackgroundAudio;

    if(BackgroundPic){
        removeItem(BackgroundPic);
        delete BackgroundPic;
        BackgroundPic = nullptr;
    }

    if(startImage){
        removeItem(startImage);
        delete startImage;
        startImage = nullptr;
    }

    if(healthDisplay){
        removeItem(healthDisplay);
        delete healthDisplay;

    }

    if(timerDisplay){
        removeItem(timerDisplay);
        delete timerDisplay;
        timerDisplay = nullptr;

    }

    if(itemDisplay){
        removeItem(itemDisplay);
        delete itemDisplay;
        itemDisplay = nullptr;
    }

    if(levelDisplay){
        removeItem(levelDisplay);
        delete levelDisplay;
        levelDisplay = nullptr;

    }

    if(birdItem){
        removeItem(birdItem);
        delete birdItem;
        birdItem = nullptr;
    }

    if(scoreText){
        removeItem(scoreText);
        delete scoreText;
        scoreText = nullptr;
    }

    cleanPipes();
    cleanPrizes();


}

//A function that displays the timer in mm:ss format
QString Game::formatTime(int seconds){
    int minutes = seconds / 60;
    int sec = seconds % 60;
    return QString("%1:%2").arg(minutes,2, 10, QLatin1Char('0')).arg(sec, 2, 10, QLatin1Char('0'));
}

int Game::getBestScore() const{
    return BestScore;
}
int Game::getScore() const{
    return Score;
}

//A function that spawns the bird to the scene
void Game::spawnBird(int w, int h){



    birdItem = new Bird(QPixmap(":/ressources/bird/up.png").scaled(w, h), w, h);
    this->addItem(birdItem);

}


//A function that starts the game when the space bar is pressed
void Game::startGame(){
    BackgroundSound->play();
    isGameOn = true;
    isGameOver = 0;
    //Removing the start image as soon as the game starts
    removeItem(startImage);
    delete(startImage);
    startImage = nullptr;

    //Starting the animation of the bird
    birdItem->startFlying();

    //Displaying health once the game starts
    healthDisplay->setPlainText("Health: " + QString::number(Health));
    healthDisplay->setPos(QPointF(450 - healthDisplay->boundingRect().width(),(650 - healthDisplay->boundingRect().height())));
    this->addItem(healthDisplay);


    //Displaying timer once the game starts
    timerDisplay->setPlainText(formatTime(remainingTime));
    timerDisplay->setPos(QPointF(450 - timerDisplay->boundingRect().width(), 0));
    this->addItem(timerDisplay);


    //Displaying health once the game starts
    itemDisplay->setPlainText("Crowns: " + QString::number(itemsToCollect));
    itemDisplay->setPos(QPointF(0, 650 - timerDisplay->boundingRect().height()));
    this->addItem(itemDisplay);

    levelDisplay->setPlainText("Level: " + QString::number(currentLevel));
    levelDisplay->setPos(QPointF(0,0));
    this->addItem(levelDisplay);



    //Checking if the timers are not active, if they're not activing them to start
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

void Game::restartGame(){

    BackgroundSound->play();
    healthDisplay->setPlainText("Health: " + QString::number(Health));
    healthDisplay->setPos( QPointF(450 - healthDisplay->boundingRect().width(),(650 - healthDisplay->boundingRect().height())));

    timerDisplay->setPlainText(formatTime(remainingTime));
    timerDisplay->setPos(QPointF(450 - timerDisplay->boundingRect().width(), 0));

    itemDisplay->setPlainText("Crowns: " + QString::number(itemsToCollect));
    itemDisplay->setPos(QPointF(0, 650 - timerDisplay->boundingRect().height()));

     birdItem->startFlying();
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

//A function that hanldes all the timers in the game

void Game::setUpTimers(){


    pipeTimer = new QTimer(this);
    //Spawning a new pipe in intervals
    connect(pipeTimer, &QTimer::timeout, this, &Game::spawnPipe);


    gameTimer = new QTimer;
    //Updating the timer
    connect(gameTimer, &QTimer::timeout, this, &Game::UpdateTime);

    prizeTimer = new QTimer;
    //Spawning prizes in intervals
    connect(prizeTimer, &QTimer::timeout, this, &Game::spawnPrizes);

}

//Incrementing the score

void Game::UpdateScore() {
    Score++;
    if (Score > BestScore ){
        BestScore = Score;
    }

}
//function to connect the collision between the bird and the pipe
void Game::spawnPipe(){
    Pipe * pipeItem = new Pipe;
    connect(pipeItem, &Pipe::BirdCollisionWithPipe, this , &Game::handlePipeCollision);
    this->addItem(pipeItem);
}

//A function that adds the prizes to the scene
void Game::spawnPrizes(){

    Prize * prizes = new Prize;
    connect(prizes, &Prize::ItemCollected, this, &Game::handleItemCollected); //Connecting the signal of ItemCollected to the function to handle the logic of collection
    this->addItem(prizes);

}


//A function that hanldes the logic of items collected
void Game::handleItemCollected(){

    PointSound->play();

    //Updating the items collected and displaying it on the scene
    itemsToCollect--;
    itemDisplay->setPlainText("Crowns: " + QString::number(itemsToCollect));
    itemDisplay->setPos(QPointF(0, 650 - timerDisplay->boundingRect().height()));

    //updating the score
    UpdateScore();

    //Once items are collected, the game stops and the player wins
    if(itemsToCollect == 0){
        //Logic that handles the game stoppingg
        prizeTimer->stop();
        gameTimer->stop();
        birdItem->stopFlying();
        pipeTimer->stop();
        BackgroundSound->stop();

        //pipe and prize item animation stops
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
        emit LevelCompleted();
        isLevelCompleted = true;




    }


}

// function tht connects the collision with the timer(stops) and the scene ( freezes)
void Game::handlePipeCollision(){
    PipeCollisionSound->play();
    pipeTimer->stop();
    FreezeScene();
}
//Function that updates the time, it counts down from 1 min, whenever it reaches 0, scene freezes
void Game::UpdateTime(){
    remainingTime--;
    timerDisplay->setPlainText(formatTime(remainingTime));
    timerDisplay->setPos(QPointF(450 - timerDisplay->boundingRect().width(), 0));

    if(remainingTime == 0){

        FreezeScene();
    }


}
//function that stops audio, timer, bird animation and prize timer whenever the scene freezes
void Game::FreezeScene(){

    BackgroundSound->stop();
    prizeTimer->stop();
    gameTimer->stop();
    birdItem->stopFlying();

    //pipe animation and prize animation stops
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
// setting game over to true, decrementing health
    isGameOver = 1;
    Health--;
    healthDisplay->setPlainText("Health: " + QString::number(Health));
//checking if health is 0, the player loses
    if(Health <= 0){
        isGameOn = true;
        restart = false;
        isGameOver = 1;
        emit GameOver();
    }else{
        //else, the level restarts
        QTimer::singleShot(1000, this, &Game::retryLevel);
    }

}

//function that allows you to retry level by cleaning pipes and prizes that were in the previous trial
//restarts the timer sets to 1 min and the game is on
void Game::retryLevel(){
        cleanPrizes();
        cleanPipes();
        Score = 0;
        remainingTime = levelTime;
        restart = true;
        isGameOver = 0;

}




//function that handles the key press bar event
void Game::keyPressEvent(QKeyEvent *event){
// if the game is not on yet, pressing the space bar to start the game
    if(isGameOn == false){
        startGame();
    }
    if(restart == true){
        restartGame();
    }

// if it's on it will check if the player didn't lose yet, then the space bar will make the bird jump
    if(event->key() == Qt::Key_Space){
        if(isGameOver == 0){

            birdItem->Jump();
            FlappingSound->play();

        }

    }

}
//function that cleans the pipe from the scene to restart the game later
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


//function that cleans the prize from the scene to restart the game later
void Game::cleanPrizes(){

    QList<QGraphicsItem *> ItemsInScene = items();
    foreach(QGraphicsItem *Item, ItemsInScene){
        Prize *prizes = dynamic_cast<Prize *>(Item);
        if(prizes){

            this->removeItem(prizes);
            delete prizes;
        }

    }


}
