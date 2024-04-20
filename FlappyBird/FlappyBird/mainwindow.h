#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include "game.h"
#include <QMainWindow>
#include <QGraphicsPixmapItem>

QT_BEGIN_NAMESPACE
namespace Ui {
class MainWindow;
}
QT_END_NAMESPACE

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    MainWindow(QWidget *parent = nullptr);
    ~MainWindow();

private:
    Ui::MainWindow *ui;
    Game *game;
    QGraphicsPixmapItem *BackgroundPic;
    QGraphicsPixmapItem *groundPic;
};
#endif // MAINWINDOW_H
