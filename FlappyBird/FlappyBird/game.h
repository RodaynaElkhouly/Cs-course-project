#ifndef GAME_H
#define GAME_H

#include <QGraphicsScene>
#include <QGraphicsPixmapItem>
#include <QTimer>
#include <QObject>
#include "bird.h"
#include "pipe.h"
#include "prize.h"

#include <QMediaPlayer>
#include <QAudioOutput>
#include <QObject>
#include <QGraphicsScene>

class Game : public QGraphicsScene
{
    Q_OBJECT
public:
    Game(int level, int h, int score, int time, int items, int w, int hh, QObject *parent = nullptr);
    ~Game();
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
    void spawnBird(int, int);
    void spawnPrizes();
    void spawnPipe();
    void handlePipeCollision();
    void handleItemCollected();
    void safelyDeleteDisplay(QGraphicsTextItem* display);
    void restartGame();
    int getBestScore() const;
    int getScore() const;
    bool isLevelCompleted;


protected:
    QGraphicsPixmapItem *startImage = nullptr;
    QGraphicsPixmapItem *gameOverImage = nullptr;
    QGraphicsPixmapItem *BackgroundPic = nullptr;
    QGraphicsPixmapItem *YouWon = nullptr;
    QGraphicsTextItem *scoreText = nullptr;
    QGraphicsTextItem *healthDisplay = nullptr;
    QGraphicsTextItem *timerDisplay = nullptr;
    QGraphicsTextItem *itemDisplay = nullptr;
    QGraphicsTextItem *levelDisplay = nullptr;
    Bird * birdItem = nullptr;
    QTimer *gameTimer = nullptr;
    QTimer *pipeTimer = nullptr;
    QTimer *prizeTimer = nullptr;
    int wBird;
    int hBird;
    int Score;
    int Health;
    int remainingTime;
    int itemsToCollect;
    int BestScore;
    int currentLevel;
    int levelTime;
    bool isGameOn = false;
    bool isGameOver = false;
    void setUpTimers();
    bool isItemCollected();
    QString formatTime(int);
    void cleanPipes();
    void cleanPrizes();
    bool restart = false;
    int itemsCount = 3;
    QMediaPlayer *PipeCollisionSound = nullptr;
    QAudioOutput *PipeCollisionAudio = nullptr;
    QMediaPlayer *FlappingSound = nullptr;
    QAudioOutput *FlappinAudio = nullptr;
    QMediaPlayer *PointSound = nullptr;
    QAudioOutput *PointAudio= nullptr;
    QMediaPlayer *BackgroundSound = nullptr;
    QAudioOutput *BackgroundAudio = nullptr;


signals:
    void LevelCompleted();
    void GameOver();

};

#endif // GAME_H
