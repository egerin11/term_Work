
#include "secondscreen.h"
#include "ui_secondscreen.h"
#include "src_back/data_model/get_bmp_data/BMPImageProcess.h"
#include "src_back/data/header/bmp_image.h"
#include "src_back/data/header/ppm_image.h"


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
//    customGraphicsView = new CustomGraphicsView(this);
//    connect(customGraphicsView,&CustomGraphicsView::item_drop,eve);
    ui->listWidget->setDragEnabled(true);
    ui->listWidget->setDragDropMode(QAbstractItemView::DragDrop);
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
//
//        QPixmap scaled_pixmap = QPixmap(filePath).scaled(view_width, view_height);
//        QImage scaled_image = scaled_pixmap.toImage();

        std::vector<std::vector<Pixel>> pixels;
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
//        BMPImageProcess bmpImageProcess;
//        bmpImageProcess.read_image(filePath.toStdString());
//        pixels = bmpImageProcess.get_pixels();

        lrucache = new LRUCache(ui->listWidget, 2, this);
        QListWidgetItem *item_list = new QListWidgetItem();
        item_list->setIcon(QIcon(QPixmap(filePath)));
        item_list->setText(QFileInfo(filePath).fileName());
        item_list->setData(Qt::UserRole, filePath);
        lrucache->addItem(item_list);

        load_image(filePath);

//        BMPImage bmpImage;
//        bmpImage.set_width(bmpImageProcess.get_width());
//        bmpImage.set_height(bmpImageProcess.get_height());
//        bmpImage.set_pixels(pixels);
        PPMImage ppmImage;
        ppmImage.read_image(filePath.toStdString());
        Image *image = dynamic_cast<Image *>(new PPMImage(ppmImage));

//        Image *image = dynamic_cast<Image *>(new BMPImage(bmpImage));
        pixels = Convert::resized_image(image, 50, 150);
        image->set_pixels(pixels);
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



