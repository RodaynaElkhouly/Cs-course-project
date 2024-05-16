#include "gameoverwindow.h"
#include "ui_gameoverwindow.h"
#include "mainwindow.h"

GameOverWindow::GameOverWindow(QWidget *parent, MainWindow *parent2, int s, int bests)
    : QWidget(parent)
    , ui(new Ui::GameOverWindow)
    , mainwindow(parent2)
{
    ui->setupUi(this);
    setWindowTitle("Game Over!");
    //Setting up the ui elements of the window
    ui->Background->setStyleSheet("background-image: url(:/ressources/backgroundimage/Background.jpg); background-repeat: no repeat; background-poistion: center");
    ui->TheMessageLayout->setAlignment(Qt::AlignCenter);
    ui->ThePicLayout->setAlignment(Qt::AlignCenter);
    ui->Lost->setText("GameOver!");
    ui->Lost->setFont(QFont("Times new Roman", 16, QFont::Bold));
    QString ScoreMessage = "<p> Score: " + QString::number(s) + "<p> Best Score: " + QString::number(bests) + "<p>";
    ui->Score->setFont(QFont("Times new Roman", 16, QFont::Bold));
    ui->Score->setText(ScoreMessage);
}

GameOverWindow::~GameOverWindow()
{
    delete ui;
}

void GameOverWindow::on_pushButton_clicked()
{
    //If restart game button is clicked, the resetart game function of mainwindow will be called and this window will be closed
    if(mainwindow){
        mainwindow->resetGame();
        mainwindow->show();

    }
    this->hide();
}

