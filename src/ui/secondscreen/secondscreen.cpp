
#include "secondscreen.h"
#include "ui_secondscreen.h"
#include <QDebug>
#include <QFileDialog>
SecondScreen::SecondScreen(QWidget *parent) :
        QWidget(parent), ui(new Ui::SecondScreen) {
    ui->setupUi(this);
    QLinearGradient gradient(0, 0, width(), height());
    gradient.setColorAt(1, QColor(255, 236, 210, 215));
    gradient.setColorAt(0, QColor(252, 182, 159, 200));
    QBrush brush(gradient);
    QPalette palette = this->palette();
    palette.setBrush(QPalette::Window, brush);
    this->setPalette(palette);
//    stackedWidget = new QStackedWidget(this);
//
//    stackedWidget->addWidget(ui->pushButton);
////
////    setCentralWidget(stackedWidget);
//    QVBoxLayout *layout = new QVBoxLayout(this);
//    layout->addWidget(stackedWidget);
//
//    // Если у вас есть дополнительные элементы интерфейса, добавьте их в макет
//    // Например:
//     layout->addWidget(ui->pushButton);
//
//    setLayout(layout);
}


SecondScreen::~SecondScreen() {
    delete ui;
}

void SecondScreen::on_pushButton_clicked() {
    QString filePath = QFileDialog::getOpenFileName(this, "Выберите файл", QDir::homePath(), "Все файлы (*.*)");
    if (!filePath.isEmpty()) {
        // Создаем QPixmap из выбранного изображения
        QPixmap pixmap(filePath);

        if (!pixmap.isNull()) {
            // Создаем новую сцену и элемент QGraphicsPixmapItem
            QGraphicsScene *scene = new QGraphicsScene; // Instantiate a new QGraphicsScene
            scene->clear();
            QGraphicsPixmapItem *item = new QGraphicsPixmapItem(pixmap);

            // Устанавливаем сцену в QGraphicsView
            ui->graphicsView->setScene(scene);

            // Добавляем элемент в сцену
            scene->addItem(item);

            // Опционально, чтобы изображение подгонялось в QGraphicsView
            ui->graphicsView->fitInView(item->boundingRect(), Qt::KeepAspectRatio);
        }

        qDebug() << "File Name: " << QFileInfo(filePath).fileName();
        qDebug() << "File Path: " << filePath;
    }
}

