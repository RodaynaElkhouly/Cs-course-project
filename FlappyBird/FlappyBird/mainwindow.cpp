#include "mainwindow.h"
#include "ui_mainwindow.h"
#include "pipe.h"
#include <QGraphicsPixmapItem>
#include "bird.h"
MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    game = new Game(this);
    game->setSceneRect(0, 0, 450, 650);
    BackgroundPic = new QGraphicsPixmapItem(QPixmap(":/ressources/backgroundimage/Background.jpg"));
    game->addItem(BackgroundPic);
    BackgroundPic->setPos(QPointF(0,0));
    Bird * birdie = new Bird(QPixmap(":/ressources/bird/up.png"));
    game->addItem(birdie);


    ui->graphicsView->setHorizontalScrollBarPolicy(Qt::ScrollBarAlwaysOff);
    ui->graphicsView->setVerticalScrollBarPolicy(Qt::ScrollBarAlwaysOff);
    ui->graphicsView->setScene(game);
}

MainWindow::~MainWindow()
{
    delete ui;
}
