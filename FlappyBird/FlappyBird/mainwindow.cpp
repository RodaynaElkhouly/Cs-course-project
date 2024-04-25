#include "mainwindow.h"
#include "ui_mainwindow.h"
#include <QGraphicsPixmapItem>
MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    //Creating the game
    game = new Game(this);
    game->setSceneRect(0, 0, 450, 650);

    //Disabling scrollbars
    ui->graphicsView->setHorizontalScrollBarPolicy(Qt::ScrollBarAlwaysOff);
    ui->graphicsView->setVerticalScrollBarPolicy(Qt::ScrollBarAlwaysOff);

    //Setting the scene to the view
    ui->graphicsView->setScene(game);

}

MainWindow::~MainWindow()
{
    delete ui;
}
