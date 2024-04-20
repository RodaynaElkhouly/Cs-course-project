#include "mainwindow.h"
#include "ui_mainwindow.h"
#include <QGraphicsPixmapItem>;

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    game = new Game(this);
    game->setSceneRect(0, 0, 450, 650);
    BackgroundPic = new QGraphicsPixmapItem(QPixmap(":/ressources/backgroundimage/DesertPic-transformed (1).png"));
    game->addItem(BackgroundPic);
    BackgroundPic->setPos(QPointF(0,0));
    groundPic = new QGraphicsPixmapItem(QPixmap(":/ressources/grounds/ground(1).png").scaledToWidth(450));
    game->addItem(groundPic);
    groundPic->setPos(QPointF(0,570));
    ui->graphicsView->setHorizontalScrollBarPolicy(Qt::ScrollBarAlwaysOff);
    ui->graphicsView->setVerticalScrollBarPolicy(Qt::ScrollBarAlwaysOff);
    ui->graphicsView->setScene(game);
}

MainWindow::~MainWindow()
{
    delete ui;
}
