#ifndef GAME_H
#define GAME_H

#include <QGraphicsScene>
#include <QGraphicsPixmapItem>
#include <QTimer>
#include <QObject>
#include "bird.h"
#include "pipe.h"
#include "prize.h"

#include <QObject>
#include <QGraphicsScene>

class Game : public QGraphicsScene
{
    Q_OBJECT
public:
    Game(int level, int h, int score, int time, int items, QObject *parent = nullptr);
    void startGame();
    void retryLevel();
    void displayYouWon();
    void displayGameOver();
    void FreezeScene();
    void UpdateScore();
    void UpdateTime();
    void UpdateHealth();
    void setScore(int);
    bool getGameOn();
    void setGameOn(bool);
    void keyPressEvent(QKeyEvent * event) override;
    void spawnBird();
    void spawnPrizes();
    void spawnPipe();
    void handlePipeCollision();
    void handleItemCollected();
    void safelyDeleteDisplay(QGraphicsTextItem* display);
    void restartGame();


protected:
    QGraphicsPixmapItem *startImage;
    QGraphicsPixmapItem *gameOverImage;
    QGraphicsPixmapItem *BackgroundPic;
    QGraphicsPixmapItem *YouWon;
    QGraphicsTextItem *scoreText;
    QGraphicsTextItem *healthDisplay;
    QGraphicsTextItem *timerDisplay;
    QGraphicsTextItem *itemDisplay;
    QGraphicsTextItem *levelDisplay;
    Bird * birdItem;
    QTimer *gameTimer;
    QTimer *pipeTimer;
    QTimer *prizeTimer;
    int Score;
    int Health;
    int remainingTime;
    int itemsToCollect;
    int BestScore;
    int currentLevel;
    int levelTime;
    bool isLevelCompleted;
    bool isGameOn = 0;
    bool isGameOver;
    void setUpTimers();
    bool isItemCollected();
    QString formatTime(int);
    void cleanPipes();
    void cleanPrizes();
    bool restart = false;
    int itemsCount = 3;


signals:
    void LevelCompleted();

};

#endif // GAME_H
