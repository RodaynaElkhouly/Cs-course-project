/********************************************************************************
** Form generated from reading UI file 'gameoverwindow.ui'
**
** Created by: Qt User Interface Compiler version 6.7.0
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_GAMEOVERWINDOW_H
#define UI_GAMEOVERWINDOW_H

#include <QtCore/QVariant>
#include <QtWidgets/QApplication>
#include <QtWidgets/QLabel>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QVBoxLayout>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_GameOverWindow
{
public:
    QWidget *Background;
    QWidget *verticalLayoutWidget;
    QVBoxLayout *ThePicLayout;
    QLabel *Lost;
    QWidget *verticalLayoutWidget_2;
    QVBoxLayout *TheMessageLayout;
    QLabel *Score;
    QPushButton *pushButton;

    void setupUi(QWidget *GameOverWindow)
    {
        if (GameOverWindow->objectName().isEmpty())
            GameOverWindow->setObjectName("GameOverWindow");
        GameOverWindow->resize(400, 650);
        Background = new QWidget(GameOverWindow);
        Background->setObjectName("Background");
        Background->setGeometry(QRect(0, 0, 391, 661));
        verticalLayoutWidget = new QWidget(Background);
        verticalLayoutWidget->setObjectName("verticalLayoutWidget");
        verticalLayoutWidget->setGeometry(QRect(80, 160, 231, 191));
        ThePicLayout = new QVBoxLayout(verticalLayoutWidget);
        ThePicLayout->setObjectName("ThePicLayout");
        ThePicLayout->setContentsMargins(0, 0, 0, 0);
        Lost = new QLabel(verticalLayoutWidget);
        Lost->setObjectName("Lost");
        Lost->setStyleSheet(QString::fromUtf8("color: rgb(255, 0, 0);"));

        ThePicLayout->addWidget(Lost);

        verticalLayoutWidget_2 = new QWidget(Background);
        verticalLayoutWidget_2->setObjectName("verticalLayoutWidget_2");
        verticalLayoutWidget_2->setGeometry(QRect(90, 370, 191, 111));
        TheMessageLayout = new QVBoxLayout(verticalLayoutWidget_2);
        TheMessageLayout->setObjectName("TheMessageLayout");
        TheMessageLayout->setContentsMargins(0, 0, 0, 0);
        Score = new QLabel(verticalLayoutWidget_2);
        Score->setObjectName("Score");
        Score->setStyleSheet(QString::fromUtf8("color: rgb(255, 0, 0);"));

        TheMessageLayout->addWidget(Score);

        pushButton = new QPushButton(Background);
        pushButton->setObjectName("pushButton");
        pushButton->setGeometry(QRect(100, 520, 161, 61));
        pushButton->setStyleSheet(QString::fromUtf8("color: rgb(255, 0, 0);"));

        retranslateUi(GameOverWindow);

        QMetaObject::connectSlotsByName(GameOverWindow);
    } // setupUi

    void retranslateUi(QWidget *GameOverWindow)
    {
        GameOverWindow->setWindowTitle(QCoreApplication::translate("GameOverWindow", "Form", nullptr));
        Lost->setText(QCoreApplication::translate("GameOverWindow", "TextLabel", nullptr));
        Score->setText(QCoreApplication::translate("GameOverWindow", "TextLabel", nullptr));
        pushButton->setText(QCoreApplication::translate("GameOverWindow", "Restart Game", nullptr));
    } // retranslateUi

};

namespace Ui {
    class GameOverWindow: public Ui_GameOverWindow {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_GAMEOVERWINDOW_H
