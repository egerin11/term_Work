//
// Created by egerin on 11/27/23.
//

#ifndef TERM_QT_EVENTS_H
#define TERM_QT_EVENTS_H

#include<QGraphicsView>
#include<QListWidget>
#include<QDragEnterEvent>
#include<QDragLeaveEvent>
#include<QDragMoveEvent>
#include<QDropEvent>
#include<QMimeData>
#include<QString>
#include<QGraphicsItem>
class events
{
public:
    events();
};


class Custom_View:public QGraphicsView{
Q_OBJECT
public:
    explicit Custom_View(QWidget *parent=nullptr);
protected:
    void dropEvent(QDropEvent *event) override;
    void dragEnterEvent(QDragEnterEvent* event) override ;
    void dragLeaveEvent(QDragLeaveEvent *event) override;
    void dragMoveEvent(QDragMoveEvent * event) override;
protected:
    QGraphicsScene *scene;
};

#endif //TERM_QT_EVENTS_H
