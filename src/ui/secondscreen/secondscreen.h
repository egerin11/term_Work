//
// Created by egerin on 11/27/23.
//

#ifndef TERM_QT_SECONDSCREEN_H
#define TERM_QT_SECONDSCREEN_H

#include <QWidget>


QT_BEGIN_NAMESPACE
namespace Ui { class SecondScreen; }
QT_END_NAMESPACE

class SecondScreen : public QWidget {
Q_OBJECT

public:
    explicit SecondScreen(QWidget *parent = nullptr);

    ~SecondScreen() override;

private:
    Ui::SecondScreen *ui;
};


#endif //TERM_QT_SECONDSCREEN_H
