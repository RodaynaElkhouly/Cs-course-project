#include "mainwindow.h"
#include "ui_mainwindow.h"
#include <QGraphicsPixmapItem>;

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    game = new Game(this);
    game->setSceneRect(0, 0, 461, 258);
    BackgroundPic = new QGraphicsPixmapItem(QPixmap(":/ressources/backgroundimage/2.pyramids-desert-beautiful-landscape-cartoon-260nw-1688951938.png"));
    game->addItem(BackgroundPic);
    BackgroundPic->setPos(QPointF(0,0));
    ui->graphicsView->setScene(game);
}

MainWindow::~MainWindow()
{
    delete ui;
}
