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
#include <QtWidgets/QGridLayout>
#include <QtWidgets/QHBoxLayout>
#include <QtWidgets/QListWidget>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QSpacerItem>
#include <QtWidgets/QWidget>
//#include "../../../Events.h"
#include <QGraphicsView>
QT_BEGIN_NAMESPACE

class Ui_SecondScreen
{
public:
    QGridLayout *gridLayout_2;
    QPushButton *pushButton_2;
    QHBoxLayout *horizontalLayout;
    QSpacerItem *horizontalSpacer;
    QSpacerItem *horizontalSpacer_2;
    QGraphicsView *graphicsView;
    QListWidget *listWidget;
    QPushButton *pushButton;

    void setupUi(QWidget *SecondScreen)
    {
        if (SecondScreen->objectName().isEmpty())
            SecondScreen->setObjectName(QString::fromUtf8("SecondScreen"));
        SecondScreen->resize(1318, 738);
        gridLayout_2 = new QGridLayout(SecondScreen);
        gridLayout_2->setObjectName(QString::fromUtf8("gridLayout_2"));
        pushButton_2 = new QPushButton(SecondScreen);
        pushButton_2->setObjectName(QString::fromUtf8("pushButton_2"));
        pushButton_2->setStyleSheet(QString::fromUtf8("flex-shrink: 0;\n"
"border-radius: 10px;\n"
"border: 1px solid #8A3E24;\n"
"background-color: 	#8A3E24;\n"
"color: #F6F1F1;\n"
"text-align: center;\n"
"font-family: Inter;\n"
"font-size: 20px;\n"
"font-style: normal;\n"
"font-weight: 400;\n"
"line-height: normal;"));

        gridLayout_2->addWidget(pushButton_2, 1, 2, 1, 1);

        horizontalLayout = new QHBoxLayout();
        horizontalLayout->setObjectName(QString::fromUtf8("horizontalLayout"));

        gridLayout_2->addLayout(horizontalLayout, 0, 1, 1, 1);

        horizontalSpacer = new QSpacerItem(40, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        gridLayout_2->addItem(horizontalSpacer, 3, 0, 1, 1);

        horizontalSpacer_2 = new QSpacerItem(40, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        gridLayout_2->addItem(horizontalSpacer_2, 3, 4, 1, 1);

        graphicsView = new QGraphicsView(SecondScreen);
        graphicsView->setObjectName(QString::fromUtf8("graphicsView"));
        graphicsView->setMinimumSize(QSize(600, 600));

        gridLayout_2->addWidget(graphicsView, 3, 3, 1, 1);

        listWidget = new QListWidget(SecondScreen);
        listWidget->setObjectName(QString::fromUtf8("listWidget"));
        listWidget->setMinimumSize(QSize(600, 600));
        listWidget->setDragEnabled(true);
        listWidget->setDragDropMode(QAbstractItemView::DragDrop);
        listWidget->setDefaultDropAction(Qt::MoveAction);

        gridLayout_2->addWidget(listWidget, 3, 1, 1, 2);

        pushButton = new QPushButton(SecondScreen);
        pushButton->setObjectName(QString::fromUtf8("pushButton"));
        pushButton->setStyleSheet(QString::fromUtf8("\n"
"flex-shrink: 0;\n"
"border-radius: 10px;\n"
"border: 1px solid #8A3E24;\n"
"color: #8A3E24;\n"
"text-align: center;\n"
"font-family: Inter;\n"
"font-size: 20px;\n"
"font-style: normal;\n"
"font-weight: 500;\n"
"line-height: normal;"));

        gridLayout_2->addWidget(pushButton, 1, 1, 1, 1);


        retranslateUi(SecondScreen);

        QMetaObject::connectSlotsByName(SecondScreen);
    } // setupUi

    void retranslateUi(QWidget *SecondScreen)
    {
        SecondScreen->setWindowTitle(QCoreApplication::translate("SecondScreen", "SecondScreen", nullptr));
        pushButton_2->setText(QCoreApplication::translate("SecondScreen", "edit", nullptr));
        pushButton->setText(QCoreApplication::translate("SecondScreen", "file", nullptr));
    } // retranslateUi

};

namespace Ui {
    class SecondScreen: public Ui_SecondScreen {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_SECONDSCREEN_H
