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
    qreal x() const;
    void setX(qreal newX);

private:
    bool isPass;
    bool GameOver;
    int yPosition;
    void RemovePipe();
    QGraphicsPixmapItem *Pipes;
    QPropertyAnimation *PipeAnimation;
    qreal m_x;

signals:

public slots:
};

#endif // PIPE_H
