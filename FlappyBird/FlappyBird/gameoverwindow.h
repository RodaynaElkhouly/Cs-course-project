#ifndef GAMEOVERWINDOW_H
#define GAMEOVERWINDOW_H

#include "mainwindow.h"
#include <QWidget>

namespace Ui {
class GameOverWindow;
}

class GameOverWindow : public QWidget
{
    Q_OBJECT

public:
    explicit GameOverWindow(QWidget *parent, MainWindow *parent2, int s, int bests);
    ~GameOverWindow();

private slots:
    void on_pushButton_clicked();

private:
    Ui::GameOverWindow *ui;
    MainWindow *mainwindow;
};

#endif // GAMEOVERWINDOW_H
