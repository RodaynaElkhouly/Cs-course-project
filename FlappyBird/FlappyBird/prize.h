#ifndef PRIZE_H
#define PRIZE_H

#include <QObject>

class Prize : public QObject
{
    Q_OBJECT
public:
    explicit Prize(QObject *parent = nullptr);

signals:
};

#endif // PRIZE_H
