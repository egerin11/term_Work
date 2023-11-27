//
// Created by egerin on 11/27/23.
//

#ifndef TERM_QT_SECONDSCREEN_H
#define TERM_QT_SECONDSCREEN_H

#include <QWidget>
#include<QStackedWidget>
#include <QGraphicsScene>
#include <QGraphicsPixmapItem>
#include <QFileDialog>
#include <QDir>
#include <QDebug>
QT_BEGIN_NAMESPACE
namespace Ui { class SecondScreen; }
QT_END_NAMESPACE

class SecondScreen : public QWidget {
Q_OBJECT

public:
    explicit SecondScreen(QWidget *parent = nullptr);

    ~SecondScreen() override;
private slots:


    void on_pushButton_clicked();
private:
    Ui::SecondScreen *ui;
    QGraphicsScene * scene;
};


#endif //TERM_QT_SECONDSCREEN_H
