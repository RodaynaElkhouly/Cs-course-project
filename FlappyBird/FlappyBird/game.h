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
    void displayYouWonPanel();
    void displayGameOverPanel();
    void FreezeScene();
    void UpdateScore();
    void UpdateTime();
    void UpdateHealth();
    void setScore(int);
    bool getGameOn();
    void setGameOn(bool);
    void keyPressEvent(QKeyEvent * event) override;
    void spawnBird();
    void spawnPipe();


protected:
    QGraphicsPixmapItem *startImage1;
    QGraphicsPixmapItem *startImage2;
    QGraphicsPixmapItem *gameOverImage;
    QGraphicsPixmapItem *BackgroundPic;
    QGraphicsTextItem *scoreText;
    QGraphicsTextItem *healthDisplay;
    QGraphicsTextItem *timerDisplay;
    Bird *birdItem;
    Pipe *pipeItem;
    Prize *prizes;
    QTimer *gameTimer;
    QTimer *pipeTimer;
    QTimer *prizeTimer;
    int Score;
    int Health;
    int remainingTime;
    bool isGameOn = 0;
    bool isGameOver;
    void setUpTimers();
    bool isItemCollected();
    QString formatTime(int);
    void cleanPipes();




};

#endif // GAME_H
