/********************************************************************************
** Form generated from reading UI file 'youwonwindow.ui'
**
** Created by: Qt User Interface Compiler version 6.7.0
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_YOUWONWINDOW_H
#define UI_YOUWONWINDOW_H

#include <QtCore/QVariant>
#include <QtWidgets/QApplication>
#include <QtWidgets/QLabel>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QVBoxLayout>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_YouWonWindow
{
public:
    QWidget *Background;
    QWidget *verticalLayoutWidget;
    QVBoxLayout *ThePicLayout;
    QLabel *Won;
    QWidget *verticalLayoutWidget_2;
    QVBoxLayout *MessageLayout;
    QLabel *Score;
    QPushButton *pushButton;

    void setupUi(QWidget *YouWonWindow)
    {
        if (YouWonWindow->objectName().isEmpty())
            YouWonWindow->setObjectName("YouWonWindow");
        YouWonWindow->resize(450, 650);
        Background = new QWidget(YouWonWindow);
        Background->setObjectName("Background");
        Background->setGeometry(QRect(-10, 0, 461, 651));
        verticalLayoutWidget = new QWidget(Background);
        verticalLayoutWidget->setObjectName("verticalLayoutWidget");
        verticalLayoutWidget->setGeometry(QRect(90, 130, 291, 201));
        ThePicLayout = new QVBoxLayout(verticalLayoutWidget);
        ThePicLayout->setObjectName("ThePicLayout");
        ThePicLayout->setContentsMargins(0, 0, 0, 0);
        Won = new QLabel(verticalLayoutWidget);
        Won->setObjectName("Won");
        Won->setStyleSheet(QString::fromUtf8("color: rgb(255, 0, 0);"));

        ThePicLayout->addWidget(Won);

        verticalLayoutWidget_2 = new QWidget(Background);
        verticalLayoutWidget_2->setObjectName("verticalLayoutWidget_2");
        verticalLayoutWidget_2->setGeometry(QRect(110, 350, 251, 151));
        MessageLayout = new QVBoxLayout(verticalLayoutWidget_2);
        MessageLayout->setObjectName("MessageLayout");
        MessageLayout->setContentsMargins(0, 0, 0, 0);
        Score = new QLabel(verticalLayoutWidget_2);
        Score->setObjectName("Score");
        Score->setStyleSheet(QString::fromUtf8("color: rgb(255, 0, 0);"));

        MessageLayout->addWidget(Score);

        pushButton = new QPushButton(Background);
        pushButton->setObjectName("pushButton");
        pushButton->setGeometry(QRect(150, 520, 161, 81));
        pushButton->setStyleSheet(QString::fromUtf8("color: rgb(255, 0, 0);\n"
"font: 700 9pt \"Segoe UI\";"));

        retranslateUi(YouWonWindow);

        QMetaObject::connectSlotsByName(YouWonWindow);
    } // setupUi

    void retranslateUi(QWidget *YouWonWindow)
    {
        YouWonWindow->setWindowTitle(QCoreApplication::translate("YouWonWindow", "Form", nullptr));
        Won->setText(QCoreApplication::translate("YouWonWindow", "TextLabel", nullptr));
        Score->setText(QCoreApplication::translate("YouWonWindow", "TextLabel", nullptr));
        pushButton->setText(QCoreApplication::translate("YouWonWindow", "Exit Game", nullptr));
    } // retranslateUi

};

namespace Ui {
    class YouWonWindow: public Ui_YouWonWindow {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_YOUWONWINDOW_H
