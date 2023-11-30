//
//#include <QLabel>
//#include <QMimeData>
//#include <QListWidget>
//#include <QListWidgetItem>
//#include "Events.h"
//
//Events::Events() {
//
//}
//
//CustomListWidget::CustomListWidget(QWidget *widget) : QListWidget(widget) {
//    setAcceptDrops(true);
//}
//
//void CustomListWidget::dropEvent(QDropEvent *event) {
//    if (event->source() == this) return;
//
//    const QMimeData *mimeData = event->mimeData();
//    if (mimeData->hasUrls()) {
//        QList<QUrl> urls = mimeData->urls();
//                foreach (const QUrl &url, urls) {
//                if (url.isLocalFile()) {
//                    QString filePath = url.toLocalFile();
//                    QImage image(filePath);
//                    if (!image.isNull()) {
//                        QListWidgetItem *item = new QListWidgetItem;
//                        item->setIcon(QIcon(QPixmap::fromImage(image)));
//
//                        emit item_drop(item);
//                        event->acceptProposedAction();
//                    }
//                }
//            }
//    }
//}
//
//void CustomListWidget::dragLeaveEvent(QDragLeaveEvent *event) {
//    event->ignore();
//}
//
//void CustomListWidget::dragEnterEvent(QDragEnterEvent *event) {
//    const QMimeData *mimeData = event->mimeData();
//    if (mimeData->hasUrls()) {
//        event->acceptProposedAction();
//    }
//}
//
//void CustomListWidget::dragMoveEvent(QDragMoveEvent *event) {
//    event->acceptProposedAction();
//    event->accept();
//}