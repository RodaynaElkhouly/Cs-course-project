#ifndef GAME_H
#define GAME_H

#include <QGraphicsScene>
#include <QGraphicsPixmapItem>
#include <QTimer>
#include <QObject>
#include "game.h"
#include "bird.h"
#include "pipe.h"
#include "ground.h"



class Game : public QGraphicsScene
{
    Q_OBJECT
public:
    Game(QObject *parent = nullptr);
    void startGame();
    void retryLevel();
    void UpdateHealth();
    void displayYouWonPanel();
    void displayGameOverPanel();
    void FreezeScene();
    void keyPressEvent(QKeyEvent *event) override;
protected:
    QGraphicsPixmapItem *startImage;
    QGraphicsPixmapItem *gameOverImage;
    Bird *bird;
    QTimer *GameTimer;
    QTimer *pipeTimer;
    QTimer *prizeTimer;
    void setUpTimers();
    void intialGameState();
    bool isItemCollected();




};

#endif // GAME_H
