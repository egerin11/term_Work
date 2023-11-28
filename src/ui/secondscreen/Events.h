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
class Events
{
public:
    Events();
};
class CustomGraphicsView:public QGraphicsView{
Q_OBJECT
signals:
    void itemDrop(QListWidgetItem*);
public:
    explicit CustomGraphicsView (QWidget *widget=nullptr);
protected:
    void dropEvent(QDropEvent *event) override;
    void dragEnterEvent(QDragEnterEvent* event) override ;
    void dragLeaveEvent(QDragLeaveEvent *event) override;
    void dragMoveEvent(QDragMoveEvent * event) override;
    using QGraphicsView::QGraphicsView;

};

#endif //TERM_QT_EVENTS_H
