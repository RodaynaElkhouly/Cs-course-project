#include "mainwindow.h"
#include "ui_mainwindow.h"
#include <QTimer>
#include <QGraphicsPixmapItem>
MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    //Creating the game
    SpawnLevel();
    //Disabling scrollbars
    ui->graphicsView->setHorizontalScrollBarPolicy(Qt::ScrollBarAlwaysOff);
    ui->graphicsView->setVerticalScrollBarPolicy(Qt::ScrollBarAlwaysOff);



}

void MainWindow::SpawnLevel(){




    currentLevel++;
    switch(currentLevel){
    case 1:
        newTimeLimit = 60;
        game = new Game(currentLevel, 3, 0, newTimeLimit, 2, 20, 20 ,this);
        score = game->getBestScore();

        break;
    case 2:
        newTimeLimit = 60 - 5 * currentLevel;
        if (newTimeLimit < 30) newTimeLimit = 30;
        game = new Game(currentLevel, 3, score, newTimeLimit, 4, 50, 50, this);
        break;
    case 3:
        newTimeLimit = 60 - 5 * currentLevel;
        if (newTimeLimit < 30) newTimeLimit = 30;
        game = new Game(currentLevel, 3, score, newTimeLimit, 6, 100, 100,  this);
        score = game->getBestScore();

        break;
    case 4:
        newTimeLimit = 60 - 5 * currentLevel;
        if (newTimeLimit < 30) newTimeLimit = 30;
        game = new Game(currentLevel, 3, score, newTimeLimit, 8, 120, 120, this);
        break;
    case 5:
        newTimeLimit = 60 - 5 * currentLevel;
        if (newTimeLimit < 30) newTimeLimit = 30;
        game = new Game(currentLevel, 3, score, newTimeLimit, 10 , 140, 140,  this);
        break;

    }


    game->setSceneRect(0, 0, 450, 650);
    connect(game, &Game::LevelCompleted, this, &MainWindow::SpawnLevel);
    connect(game, &Game::GameOver, this, &MainWindow::resetGame);
    ui->graphicsView->setScene(game);

    if(game->isLevelCompleted && currentLevel > 5){
        QTimer::singleShot(1000, game, &Game::displayYouWon);
    }



}
void MainWindow::resetGame(){

    currentLevel = 0;
    SpawnLevel();
}
MainWindow::~MainWindow()
{
    delete ui;
}
