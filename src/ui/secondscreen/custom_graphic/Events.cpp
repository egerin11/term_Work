//
// Created by egerin on 11/27/23.
//

#include "../Events.h"
#include <QDebug>
Custom_View::Custom_View(QWidget *parent):QGraphicsView(parent)
{
    setAcceptDrops(true);
    scene=new QGraphicsScene(this);
    setScene(scene);
    viewport()->installEventFilter(this);
}

void Custom_View::dropEvent(QDropEvent *event) {
    if (event->source() == this) return;
    QDropEvent *DropEvent = static_cast<QDropEvent *>(event);
    if (DropEvent->mimeData()->hasUrls()) {
        QList<QUrl> urlslist = DropEvent->mimeData()->urls();
                foreach(QUrl url, urlslist) {
                if (url.isLocalFile()) {

                    QString FilePath = url.toLocalFile();
                    qDebug()<<"file"<<FilePath;
                    QPixmap pixmap(FilePath);
                    if (pixmap.isNull() == false) {
                        if (scene->items().count() > 0)scene->clear();

                        QGraphicsPixmapItem *item = new QGraphicsPixmapItem(pixmap);

                        scene->setSceneRect(pixmap.rect());
                        setSceneRect(scene->sceneRect());
                        fitInView(scene->sceneRect(), Qt::KeepAspectRatio);
                        scene->addItem(item);
                        DropEvent->acceptProposedAction();

                    }

                }

            }

    }
}



void Custom_View::dragEnterEvent(QDragEnterEvent *event)
{
    QDragEnterEvent *DragEnterEvent=static_cast<QDragEnterEvent*>(event);
    if(DragEnterEvent->mimeData()->hasUrls()){
        DragEnterEvent->acceptProposedAction();
    }
}

void Custom_View::dragLeaveEvent(QDragLeaveEvent *event)
{
    event->accept();
}

void Custom_View::dragMoveEvent(QDragMoveEvent *event)
{

    event->accept();
    event->acceptProposedAction();
}