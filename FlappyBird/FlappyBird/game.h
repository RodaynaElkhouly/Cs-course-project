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
#include "prize.h"



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
    void UpdateScore();
    void keyPressEvent(QKeyEvent *event) override;
    void setScore(int);
    bool getGameOn();
    void setGameOb(bool)
protected:
    QGraphicsPixmapItem *startImage;
    QGraphicsPixmapItem *gameOverImage;
    Bird *birdItem;
    Pipe *pipeItem;
    Prize *prizes;
    Ground *groundItem;
    QTimer *gameTimer;
    QTimer *pipeTimer;
    QTimer *prizeTimer;
    int Score;
    bool isGameOn;
    bool isGameOver;
    bool isGameStarted;
    void setUpTimers();
    void intialGameState();
    bool isItemCollected();




};

#endif // GAME_H
