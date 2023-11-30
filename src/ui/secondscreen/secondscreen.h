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
#include "LRUCache.h"
#include "Events.h"
QT_BEGIN_NAMESPACE
namespace Ui { class SecondScreen; }
QT_END_NAMESPACE

class SecondScreen : public QWidget {
Q_OBJECT

public:
    explicit SecondScreen(QWidget *parent = nullptr);

    ~SecondScreen() override;

private slots:

    void on_list_item_clicked(QListWidgetItem *item);

    void on_pushButton_clicked();

private:
    void load_image(const QString &filePath);
    Ui::SecondScreen *ui;
    QGraphicsScene *scene;
    LRUCache *lrucache;
    CustomGraphicsView *customGraphicsView;
};


#endif //TERM_QT_SECONDSCREEN_H
