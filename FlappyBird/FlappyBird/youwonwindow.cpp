#include "youwonwindow.h"
#include "ui_youwonwindow.h"

YouWonWindow::YouWonWindow(QWidget *parent, int s, int bests)
    : QWidget(parent)
    , ui(new Ui::YouWonWindow)
{

    ui->setupUi(this);
    setWindowTitle("You Won!");
    ui->Background->setStyleSheet("background-image: url(:/ressources/backgroundimage/Background.jpg); background-repeat: no repeat; background-poistion: center");
    ui->MessageLayout->setAlignment(Qt::AlignCenter);
    ui->ThePicLayout->setAlignment(Qt::AlignCenter);
    ui->Won->setText("YOU WON!");
    ui->Won->setFont(QFont("Times new Roman", 16, QFont::Bold));
    QString ScoreMessage = "<p> Score: " + QString::number(s) + "<p> Best Score: " + QString::number(bests) + "<p>";
    ui->Score->setFont(QFont("Times new Roman", 16, QFont::Bold));
    ui->Score->setText(ScoreMessage);
}

YouWonWindow::~YouWonWindow()
{
    delete ui;
}

void YouWonWindow::on_pushButton_clicked()
{
    QApplication::quit();
}

