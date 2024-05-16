#ifndef PIPE_H
#define PIPE_H

#include <QObject>
#include <QGraphicsItemGroup>
#include <QGraphicsPixmapItem>
#include <QPropertyAnimation>

class Pipe : public QObject, public QGraphicsItemGroup
{
    Q_OBJECT
    Q_PROPERTY(qreal x READ x WRITE setX)
public:
    explicit Pipe();
    ~Pipe();
    qreal x() const;
    void setX(qreal newX);
    void stopPipe();

private:
    bool isPass;
    bool isCollide;
    bool detectCollision();
    int yPosition;
    void RemovePipe();
    QGraphicsPixmapItem *Pipes = nullptr;
    QPropertyAnimation *PipeAnimation = nullptr;
    qreal m_x;

signals:

    void BirdCollisionWithPipe();


public slots:
};

#endif // PIPE_H
