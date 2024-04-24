#ifndef PRIZE_H
#define PRIZE_H

#include <QObject>
#include <QGraphicsPixmapItem>
#include <QPropertyAnimation>

class Prize : public QObject , public QGraphicsPixmapItem
{
    Q_OBJECT
    Q_PROPERTY(qreal x READ x WRITE setX);
public:
    explicit Prize(QObject *parent = nullptr);
    qreal x() const;
    void setX(qreal newX);
    void stopPrize();

private:
    QGraphicsPixmapItem *Crown;
    QPropertyAnimation *crownAnimation;
    int yPos;
    const int minY = 100;
    const int maxY = 500;
    qreal m_x;

signals:
};

#endif // PRIZE_H
