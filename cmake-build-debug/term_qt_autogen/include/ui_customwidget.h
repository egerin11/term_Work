/********************************************************************************
** Form generated from reading UI file 'customwidget.ui'
**
** Created by: Qt User Interface Compiler version 5.15.11
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_CUSTOMWIDGET_H
#define UI_CUSTOMWIDGET_H

#include <QtCore/QVariant>
#include <QtWidgets/QApplication>
#include <QtWidgets/QHBoxLayout>
#include <QtWidgets/QLabel>
#include <QtWidgets/QSpacerItem>
#include <QtWidgets/QToolButton>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_CustomWidget
{
public:
    QHBoxLayout *horizontalLayout;
    QLabel *label;
    QSpacerItem *horizontalSpacer_2;
    QToolButton *closeButton;

    void setupUi(QWidget *CustomWidget)
    {
        if (CustomWidget->objectName().isEmpty())
            CustomWidget->setObjectName(QString::fromUtf8("CustomWidget"));
        CustomWidget->resize(324, 98);
        horizontalLayout = new QHBoxLayout(CustomWidget);
        horizontalLayout->setObjectName(QString::fromUtf8("horizontalLayout"));
        label = new QLabel(CustomWidget);
        label->setObjectName(QString::fromUtf8("label"));

        horizontalLayout->addWidget(label);

        horizontalSpacer_2 = new QSpacerItem(40, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        horizontalLayout->addItem(horizontalSpacer_2);

        closeButton = new QToolButton(CustomWidget);
        closeButton->setObjectName(QString::fromUtf8("closeButton"));

        horizontalLayout->addWidget(closeButton);


        retranslateUi(CustomWidget);

        QMetaObject::connectSlotsByName(CustomWidget);
    } // setupUi

    void retranslateUi(QWidget *CustomWidget)
    {
        CustomWidget->setWindowTitle(QCoreApplication::translate("CustomWidget", "Form", nullptr));
        label->setText(QCoreApplication::translate("CustomWidget", "TextLabel", nullptr));
        closeButton->setText(QCoreApplication::translate("CustomWidget", "x", nullptr));
    } // retranslateUi

};

namespace Ui {
    class CustomWidget: public Ui_CustomWidget {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_CUSTOMWIDGET_H
