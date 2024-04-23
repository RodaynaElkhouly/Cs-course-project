#ifndef GAME_H
#define GAME_H

#include <QGraphicsScene>
#include <QGraphicsPixmapItem>
#include <QTimer>
#include <QObject>
#include "bird.h"
#include "pipe.h"
#include "ground.h"
#include "prize.h"

#include <QObject>
#include <QGraphicsScene>

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
    void setScore(int);
    bool getGameOn();
    void setGameOb(bool);
    void keyPressEvent(QKeyEvent * event) override;
    void spawnBird();
protected:
    QGraphicsPixmapItem *startImage;
    QGraphicsPixmapItem *gameOverImage;
    QGraphicsPixmapItem *BackgroundPic;
    QGraphicsTextItem *scoreText;
    Bird *birdItem;
    Pipe *pipeItem;
    Prize *prizes;
    Ground *groundItem;
    QTimer *gameTimer;
    QTimer *pipeTimer;
    QTimer *prizeTimer;
    int Score;
    bool isGameOn = 0;
    bool isGameOver;
    void setUpTimers();
    void intialGameState();
    bool isItemCollected();
    void spawnPipe();
    ;




};

#endif // GAME_H
