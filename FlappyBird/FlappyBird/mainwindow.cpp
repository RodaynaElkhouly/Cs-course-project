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

    //Level one


    currentLevel++;
    switch(currentLevel){
    case 1:
        newTimeLimit = 60;
        game = new Game(currentLevel, 3, 0, newTimeLimit, 2, this);
        score = game->getBestScore();

        break;
    case 2:
        newTimeLimit = 60 - 5 * currentLevel;
        if (newTimeLimit < 30) newTimeLimit = 30;
        game = new Game(currentLevel, 3, score, newTimeLimit, 4, this);
        break;
    case 3:
        newTimeLimit = 60 - 5 * currentLevel;
        if (newTimeLimit < 30) newTimeLimit = 30;
        game = new Game(currentLevel, 3, score, newTimeLimit, 6, this);
        score = game->getBestScore();

        break;
    case 4:
        newTimeLimit = 60 - 5 * currentLevel;
        if (newTimeLimit < 30) newTimeLimit = 30;
        game = new Game(currentLevel, 3, score, newTimeLimit, 8, this);
        break;
    case 5:
        newTimeLimit = 60 - 5 * currentLevel;
        if (newTimeLimit < 30) newTimeLimit = 30;
        game = new Game(currentLevel, 3, score, newTimeLimit, 10, this);
        break;

    }


    game->setSceneRect(0, 0, 450, 650);
    connect(game, &Game::LevelCompleted, this, &MainWindow::SpawnLevel);
    ui->graphicsView->setScene(game);

    if(game->isLevelCompleted && currentLevel > 5){
        QTimer::singleShot(1000, game, &Game::displayYouWon);
    }



}

MainWindow::~MainWindow()
{
    delete ui;
}
