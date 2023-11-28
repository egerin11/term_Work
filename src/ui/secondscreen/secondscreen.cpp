
#include "secondscreen.h"
#include "ui_secondscreen.h"
#include "src_back/data_model/get_bmp_data/BMPImageProcess.h"
#include "src_back/data/header/bmp_image.h"


#include <QDebug>
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
        int view_width = 100;
//                ui->graphicsView->width();
        int view_height = 100;
//                ui->graphicsView->height();
        QPixmap scaled_pixmap = pixmap.scaled(view_width,view_height, Qt::KeepAspectRatio);
        QImage scaled_image = scaled_pixmap.toImage();
        std::vector<std::vector<Pixel>> pixels(view_height, std::vector<Pixel>(view_width));
        for (int y = 0; y < view_height; ++y)
        {
            for (int x = 0; x < view_width; ++x)
            {
                QRgb pixelColor = scaled_image.pixel(x, y);

                Pixel pixel;
                pixel.m_red = qRed(pixelColor);
                pixel.m_green = qGreen(pixelColor);
                pixel.m_blue = qBlue(pixelColor);

                pixels[y][x] = pixel;
            }
        }
        if (!pixmap.isNull()) {
            LRUCache* lrucache = new LRUCache(ui->listWidget, 2, this);
            QListWidgetItem *item_list = new QListWidgetItem(filePath);
            lrucache->addItem(item_list);

            // Обновляем список, чтобы элементы оставались видимыми
//            listWidget->scrollToBottom();

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

//            BMPImageProcess bmpImageProcess;
//            bmpImageProcess.read_image(filePath.toStdString());
//
//            std::vector<std::vector<Pixel>> pixels = bmpImageProcess.get_pixels();
//            int width = bmpImageProcess.get_width();
//            int height = bmpImageProcess.get_height();
//
            BMPImage bmpImage;
            bmpImage.set_width(view_width);
            bmpImage.set_height(view_height);
            bmpImage.set_pixels(pixels);

            Image *image = dynamic_cast<Image *>(new BMPImage(bmpImage));

//            std::vector<std::vector<Pixel>> pixel = Convert::resized_image(image, 50, 50);
            Convert::grayscale(image);
            Convert::ascii(image, "test.txt");
            QString file_path = "/home/egerin/Projects/term_qt/cmake-build-debug/";
            QUrl fileUrl = QUrl::fromLocalFile(file_path + "test.txt");

            // Открываем файл с использованием ассоциированного приложения
            QDesktopServices::openUrl(fileUrl);
//        ui->textBrowser->setText("Открыт файл: " + filePath);
            qDebug() << "File Name: " << QFileInfo(filePath).fileName();
            qDebug() << "File Path: " << filePath;
        }
    }
}

