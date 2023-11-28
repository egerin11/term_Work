/********************************************************************************
** Form generated from reading UI file 'secondscreen.ui'
**
** Created by: Qt User Interface Compiler version 5.15.11
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_SECONDSCREEN_H
#define UI_SECONDSCREEN_H

#include <QtCore/QVariant>
#include <QtWidgets/QApplication>
#include <QtWidgets/QGraphicsView>
#include <QtWidgets/QGridLayout>
#include <QtWidgets/QListWidget>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QSpacerItem>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_SecondScreen
{
public:
    QGridLayout *gridLayout;
    QSpacerItem *horizontalSpacer;
    QSpacerItem *horizontalSpacer_2;
    QGraphicsView *graphicsView;
    QListWidget *listWidget;
    QPushButton *pushButton;

    void setupUi(QWidget *SecondScreen)
    {
        if (SecondScreen->objectName().isEmpty())
            SecondScreen->setObjectName(QString::fromUtf8("SecondScreen"));
        SecondScreen->resize(1278, 793);
        gridLayout = new QGridLayout(SecondScreen);
        gridLayout->setObjectName(QString::fromUtf8("gridLayout"));
        horizontalSpacer = new QSpacerItem(40, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        gridLayout->addItem(horizontalSpacer, 1, 4, 1, 1);

        horizontalSpacer_2 = new QSpacerItem(40, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        gridLayout->addItem(horizontalSpacer_2, 1, 0, 1, 1);

        graphicsView = new QGraphicsView(SecondScreen);
        graphicsView->setObjectName(QString::fromUtf8("graphicsView"));
        graphicsView->setMinimumSize(QSize(600, 600));

        gridLayout->addWidget(graphicsView, 1, 2, 1, 1);

        listWidget = new QListWidget(SecondScreen);
        listWidget->setObjectName(QString::fromUtf8("listWidget"));

        gridLayout->addWidget(listWidget, 1, 1, 1, 1);

        pushButton = new QPushButton(SecondScreen);
        pushButton->setObjectName(QString::fromUtf8("pushButton"));
        pushButton->setMinimumSize(QSize(600, 34));
        pushButton->setStyleSheet(QString::fromUtf8("width: 96px;\n"
"height: 32px;\n"
"flex-shrink: 0;\n"
"border-radius: 10px;\n"
"border: 1px solid #8A3E24;"));

        gridLayout->addWidget(pushButton, 0, 2, 1, 1);


        retranslateUi(SecondScreen);

        QMetaObject::connectSlotsByName(SecondScreen);
    } // setupUi

    void retranslateUi(QWidget *SecondScreen)
    {
        SecondScreen->setWindowTitle(QCoreApplication::translate("SecondScreen", "SecondScreen", nullptr));
        pushButton->setText(QCoreApplication::translate("SecondScreen", "file", nullptr));
    } // retranslateUi

};

namespace Ui {
    class SecondScreen: public Ui_SecondScreen {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_SECONDSCREEN_H
