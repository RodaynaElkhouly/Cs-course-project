#include "mainwindow.h"
#include "ui_mainwindow.h"
#include <QTimer>
#include <QGraphicsPixmapItem>
#include "youwonwindow.h"
#include "gameoverwindow.h"

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);

    setWindowTitle("Flappy Bird");
    //Creating the game
    SpawnLevel();
    //Disabling scrollbars
    ui->graphicsView->setHorizontalScrollBarPolicy(Qt::ScrollBarAlwaysOff);
    ui->graphicsView->setVerticalScrollBarPolicy(Qt::ScrollBarAlwaysOff);



}

void MainWindow::SpawnLevel(){

    //Function that spawns game objects depeneding on the level in the switch case

    currentLevel++; //incrementing the level as its set to 0 by default
    switch(currentLevel){
    case 1:
        //Level 1
        newTimeLimit = 60;
        game = new Game(currentLevel, 3, 0, newTimeLimit, 2, 20, 20 ,this);
        break;
    case 2:
        //Level 2
        newTimeLimit = 60 - 5 * currentLevel;
        if (newTimeLimit < 30) newTimeLimit = 30;
        game = new Game(currentLevel, 3, score, newTimeLimit, 1, 50, 50, this);
        break;
    case 3:
        //Level 3
        newTimeLimit = 60 - 5 * currentLevel;
        if (newTimeLimit < 30) newTimeLimit = 30;
        game = new Game(currentLevel, 3, score, newTimeLimit, 1, 100, 100,  this);
        break;
    case 4:
        //Level 4
        newTimeLimit = 60 - 5 * currentLevel;
        if (newTimeLimit < 30) newTimeLimit = 30;
        game = new Game(currentLevel, 3, score, newTimeLimit, 1, 120, 120, this);
        break;
    case 5:
        //Level 5
        newTimeLimit = 60 - 5 * currentLevel;
        if (newTimeLimit < 30) newTimeLimit = 30;
        game = new Game(currentLevel, 3, score, newTimeLimit, 1 , 140, 140,  this);
        break;

    }

    //Setting the scene
    game->setSceneRect(0, 0, 450, 650);
    //A connect function that checks if the level is completed by a signal from the game, if it is , it calls the spawnlevel function to spawn a new level
    connect(game, &Game::LevelCompleted, this, &MainWindow::SpawnLevel);

    //A connect function that checks if the player finished all his lives and lost through a signal from the game, if that's the case then a lambda function that captures this current window is called to open the game over window and send to it this current window
    connect(game, &Game::GameOver, this,[this](){
        this->hide();
        GameOverWindow *lost = new GameOverWindow(nullptr, this, game->getScore(), game->getBestScore());
        lost->show();
    });
    ui->graphicsView->setScene(game);

    //A mechanism that checks if all leveks are completed and the player finished them all, then it displays the you won window to the player
    if(game->isLevelCompleted && currentLevel > 5){
        this->hide();
        YouWonWindow *won = new YouWonWindow(nullptr, game->getScore(), game->getBestScore());
        won->show();
    }



}
void MainWindow::resetGame(){
//A function that resets the game and resets the levels to 0
    currentLevel = 0;
    SpawnLevel();
    this->show();
}
MainWindow::~MainWindow()
{
    delete ui;
}
