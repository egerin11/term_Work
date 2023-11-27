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
#include <QtWidgets/QSpacerItem>
#include <QtWidgets/QTextBrowser>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_SecondScreen
{
public:
    QGridLayout *gridLayout;
    QGraphicsView *graphicsView;
    QTextBrowser *textBrowser;
    QSpacerItem *verticalSpacer;
    QSpacerItem *horizontalSpacer;
    QSpacerItem *horizontalSpacer_2;

    void setupUi(QWidget *SecondScreen)
    {
        if (SecondScreen->objectName().isEmpty())
            SecondScreen->setObjectName(QString::fromUtf8("SecondScreen"));
        SecondScreen->resize(1278, 793);
        gridLayout = new QGridLayout(SecondScreen);
        gridLayout->setObjectName(QString::fromUtf8("gridLayout"));
        graphicsView = new QGraphicsView(SecondScreen);
        graphicsView->setObjectName(QString::fromUtf8("graphicsView"));
        graphicsView->setMinimumSize(QSize(600, 600));

        gridLayout->addWidget(graphicsView, 1, 1, 1, 1);

        textBrowser = new QTextBrowser(SecondScreen);
        textBrowser->setObjectName(QString::fromUtf8("textBrowser"));
        textBrowser->setMinimumSize(QSize(600, 600));

        gridLayout->addWidget(textBrowser, 1, 2, 1, 1);

        verticalSpacer = new QSpacerItem(100, 10, QSizePolicy::Minimum, QSizePolicy::Minimum);

        gridLayout->addItem(verticalSpacer, 0, 1, 1, 1);

        horizontalSpacer = new QSpacerItem(40, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        gridLayout->addItem(horizontalSpacer, 1, 3, 1, 1);

        horizontalSpacer_2 = new QSpacerItem(40, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        gridLayout->addItem(horizontalSpacer_2, 1, 0, 1, 1);


        retranslateUi(SecondScreen);

        QMetaObject::connectSlotsByName(SecondScreen);
    } // setupUi

    void retranslateUi(QWidget *SecondScreen)
    {
        SecondScreen->setWindowTitle(QCoreApplication::translate("SecondScreen", "SecondScreen", nullptr));
    } // retranslateUi

};

namespace Ui {
    class SecondScreen: public Ui_SecondScreen {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_SECONDSCREEN_H
