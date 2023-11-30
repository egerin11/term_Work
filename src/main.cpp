//#include <QApplication>
//#include <QPushButton>
//#include "ui/mainwindow/mainwindow.h"
//
//int main(int argc, char *argv[]) {
//    QApplication a(argc, argv);
//    MainWindow w;
//    QIcon appIcon(":icon_app/image/icon2.png");
//    a.setWindowIcon(appIcon);
//    w.show();
//    return a.exec();
//}
#include <QApplication>
#include <QMainWindow>
#include <QListWidget>
#include <QListWidgetItem>
#include <QLabel>
#include <QPixmap>
#include <QDragEnterEvent>
#include <QDropEvent>
#include <QMimeData>

class DragAndDropExample : public QMainWindow {
public:
    DragAndDropExample() {
        listWidget = new QListWidget(this);
        listWidget->setGeometry(10, 10, 200, 300);
        listWidget->setAcceptDrops(true);
        listWidget->setDragDropMode(QAbstractItemView::DragDrop); // Add this line

        setGeometry(100, 100, 300, 400);
        setWindowTitle("Drag and Drop Example");
    }

protected:
    void dragEnterEvent(QDragEnterEvent* event) override {
        const QMimeData* mimeData = event->mimeData();

        if (mimeData->hasUrls() && mimeData->urls()[0].isLocalFile()) {
            event->acceptProposedAction();
        }
    }

    void dropEvent(QDropEvent* event) override {
        const QMimeData* mimeData = event->mimeData();

        if (mimeData->hasUrls() && mimeData->urls()[0].isLocalFile()) {
            QString filePath = mimeData->urls()[0].toLocalFile();

            QListWidgetItem* item = new QListWidgetItem(listWidget);
            QLabel* label = new QLabel(this);
            QPixmap pixmap(filePath);
            label->setPixmap(pixmap.scaled(100, 100)); // Устанавливаем размер изображения
            item->setSizeHint(label->sizeHint());
            listWidget->setItemWidget(item, label);

            event->acceptProposedAction();
        }
    }

private:
    QListWidget* listWidget;
};

int main(int argc, char *argv[]) {
    QApplication app(argc, argv);

    DragAndDropExample window;
    window.show();

    return app.exec();
}
