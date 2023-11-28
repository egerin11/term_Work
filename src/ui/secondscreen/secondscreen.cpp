
#include "secondscreen.h"
#include "ui_secondscreen.h"
#include "src_back/data_model/get_bmp_data/BMPImageProcess.h"
#include "src_back/data/header/bmp_image.h"


#include <QFileDialog>
#include <QDesktopServices>

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
    connect(ui->listWidget, &QListWidget::itemClicked, this, &SecondScreen::on_list_item_clicked);
}


SecondScreen::~SecondScreen() {
    delete ui;
}

void SecondScreen::load_image(const QString &filePath) {
    QPixmap pixmap(filePath);

    if (!pixmap.isNull()) {
        QGraphicsScene *scene = new QGraphicsScene;
        scene->clear();
        QGraphicsPixmapItem *graphicsItem = new QGraphicsPixmapItem(pixmap);

        ui->graphicsView->setScene(scene);
        scene->addItem(graphicsItem);

        ui->graphicsView->fitInView(graphicsItem->boundingRect(), Qt::KeepAspectRatio);

        qDebug() << "Opened file: " << filePath;
    }
}

void SecondScreen::on_pushButton_clicked() {
    QString filePath = QFileDialog::getOpenFileName(this, "Выберите файл", QDir::homePath(), "Все файлы (*.*)");
    if (!filePath.isEmpty()) {
        int view_width = 50;
        int view_height = 50;

        QPixmap scaled_pixmap = QPixmap(filePath).scaled(view_width, view_height);
        QImage scaled_image = scaled_pixmap.toImage();

        std::vector<std::vector<Pixel>> pixels(view_height, std::vector<Pixel>(view_width));
        for (int y = 0; y < view_height; ++y) {
            for (int x = 0; x < view_width; ++x) {
                QRgb pixelColor = scaled_image.pixel(x, y);

                Pixel pixel;
                pixel.m_red = qRed(pixelColor);
                pixel.m_green = qGreen(pixelColor);
                pixel.m_blue = qBlue(pixelColor);

                pixels[y][x] = pixel;
            }
        }

        LRUCache *lrucache = new LRUCache(ui->listWidget, 2, this);
        QListWidgetItem *item_list = new QListWidgetItem();
        item_list->setIcon(QIcon(scaled_pixmap));
        item_list->setText(QFileInfo(filePath).fileName());
        item_list->setData(Qt::UserRole, filePath);
        lrucache->addItem(item_list);

        load_image(filePath);

        BMPImage bmpImage;
        bmpImage.set_width(view_width);
        bmpImage.set_height(view_height);
        bmpImage.set_pixels(pixels);

        Image *image = dynamic_cast<Image *>(new BMPImage(bmpImage));

        Convert::grayscale(image);
        Convert::ascii(image, "test.txt");
        QString file_path = "/home/egerin/Projects/term_qt/cmake-build-debug/";
        QUrl fileUrl = QUrl::fromLocalFile(file_path + "test.txt");

        QDesktopServices::openUrl(fileUrl);
    }
}

void SecondScreen::on_list_item_clicked(QListWidgetItem *item) {
    QString filePath = item->data(Qt::UserRole).toString();
    if (!filePath.isEmpty()) {
        load_image(filePath);
    }
}

//void SecondScreen::on_pushButton_clicked() {
//    QString filePath = QFileDialog::getOpenFileName(this, "Выберите файл", QDir::homePath(), "Все файлы (*.*)");
//    if (!filePath.isEmpty()) {
//        QPixmap pixmap(filePath);
//        int view_width = 50;
//        int view_height = 50;
//        QPixmap scaled_pixmap = pixmap.scaled(view_width, view_height);
//        QImage scaled_image = scaled_pixmap.toImage();
//        std::vector<std::vector<Pixel>> pixels(view_height, std::vector<Pixel>(view_width));
//        for (int y = 0; y < view_height; ++y) {
//            for (int x = 0; x < view_width; ++x) {
//                QRgb pixelColor = scaled_image.pixel(x, y);
//
//                Pixel pixel;
//                pixel.m_red = qRed(pixelColor);
//                pixel.m_green = qGreen(pixelColor);
//                pixel.m_blue = qBlue(pixelColor);
//
//                pixels[y][x] = pixel;
//            }
//        }
//        if (!pixmap.isNull()) {
//            LRUCache *lrucache = new LRUCache(ui->listWidget, 2, this);
//            QListWidgetItem *item_list = new QListWidgetItem();
//            item_list->setIcon(QIcon(pixmap));
//            item_list->setText(QFileInfo(filePath).fileName());
//            item_list->setData(Qt::UserRole, filePath);
//            lrucache->addItem(item_list);
//
//            QGraphicsScene *scene = new QGraphicsScene;
//            scene->clear();
//            QGraphicsPixmapItem *item = new QGraphicsPixmapItem(pixmap);
//
//            ui->graphicsView->setScene(scene);
//            scene->addItem(item);
//            ui->graphicsView->fitInView(item->boundingRect(), Qt::KeepAspectRatio);
//
//            BMPImage bmpImage;
//            bmpImage.set_width(view_width);
//            bmpImage.set_height(view_height);
//            bmpImage.set_pixels(pixels);
//
//            Image *image = dynamic_cast<Image *>(new BMPImage(bmpImage));
//
//            Convert::grayscale(image);
//            Convert::ascii(image, "test.txt");
//            QString file_path = "/home/egerin/Projects/term_qt/cmake-build-debug/";
//            QUrl fileUrl = QUrl::fromLocalFile(file_path + "test.txt");
//
//            QDesktopServices::openUrl(fileUrl);
//            qDebug() << "File Name: " << QFileInfo(filePath).fileName();
//            qDebug() << "File Path: " << filePath;
//        }
//    }
//}
//
//void SecondScreen::on_list_item_clicked(QListWidgetItem *item) {
//    QString filePath = item->data(Qt::UserRole).toString();
//
//    if (!filePath.isEmpty()) {
//        QPixmap pixmap(filePath);
//
//        if (!pixmap.isNull()) {
//            QGraphicsScene *scene = new QGraphicsScene;
//            scene->clear();
//            QGraphicsPixmapItem *graphicsItem = new QGraphicsPixmapItem(pixmap);
//
//            ui->graphicsView->setScene(scene);
//            scene->addItem(graphicsItem);
//
//            ui->graphicsView->fitInView(graphicsItem->boundingRect(), Qt::KeepAspectRatio);
//
//            qDebug() << "Opened file: " << filePath;
//        }
//    }
//}

