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

private slots:
    void SpawnLevel();
    void resetGame();

private:
    int currentLevel = 0;
    int newTimeLimit;
    int score;
    Ui::MainWindow *ui;
    Game *game;
    QGraphicsPixmapItem *BackgroundPic;
    QGraphicsPixmapItem *groundPic;
};
#endif // MAINWINDOW_H
