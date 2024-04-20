#ifndef PIPE_H
#define PIPE_H

#include <QObject>
#include <QGraphicsItemGroup>
#include <QGraphicsPixmapItem>

class Pipe : public QObject, public QGraphicsItemGroup
{
    Q_OBJECT
public:
    explicit Pipe();
private:
    bool isPass;
    QGraphicsPixmapItem *Pipes;
signals:

public slots:
};

#endif // PIPE_H
