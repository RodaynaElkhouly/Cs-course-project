#ifndef YOUWONWINDOW_H
#define YOUWONWINDOW_H

#include <QWidget>
#include <QGraphicsTextItem>

namespace Ui {
class YouWonWindow;
}

class YouWonWindow : public QWidget
{
    Q_OBJECT

public:
    explicit YouWonWindow(QWidget *parent, int s , int bests);
    ~YouWonWindow();

private slots:
    void on_pushButton_clicked();

private:
    QGraphicsTextItem *scoreText;
    Ui::YouWonWindow *ui;
};

#endif // YOUWONWINDOW_H
