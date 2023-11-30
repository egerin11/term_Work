
#include "secondscreen.h"
#include "ui_secondscreen.h"
#include "src_back/data_model/get_bmp_data/BMPImageProcess.h"
#include "src_back/data/header/bmp_image.h"
#include "src_back/data/header/ppm_image.h"
#include "../customwidget/customwidget.h"


#include <QFileDialog>
#include <QDesktopServices>

SecondScreen::SecondScreen(QWidget *parent) :
        QWidget(parent), ui(new Ui::SecondScreen) {
    ui->setupUi(this);
    setWindowTitle("edit screen");

    QLinearGradient gradient(0, 0, width(), height());
    gradient.setColorAt(1, QColor(255, 236, 210, 215));
    gradient.setColorAt(0, QColor(252, 182, 159, 200));
    QBrush brush(gradient);
    QPalette palette = this->palette();
    palette.setBrush(QPalette::Window, brush);
    this->setPalette(palette);

    ui->listWidget->setMinimumSize(400, 600);
    ui->graphicsView->setMinimumSize(600, 600);
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

void SecondScreen::handleItemDrop(QListWidgetItem *item) {

//    QString filePath = item->data(Qt::UserRole).toString();
//
//    lrucache = new LRUCache(ui->listWidget, 2, this);
//    QListWidgetItem *item_list = new QListWidgetItem();
//    item_list->setIcon(QIcon(QPixmap(filePath)));
//    item_list->setText(QFileInfo(filePath).fileName());
//    item_list->setData(Qt::UserRole, filePath);
//    lrucache->addItem(item_list);

}

void SecondScreen::on_pushButton_clicked() {
    QString filePath = QFileDialog::getOpenFileName(this, "Выберите файл", QDir::homePath(), "Все файлы (*.*)");
    if (!filePath.isEmpty()) {
        int view_width = 50;
        int view_height = 50;
//
//        QPixmap scaled_pixmap = QPixmap(filePath).scaled(view_width, view_height);
//        QImage scaled_image = scaled_pixmap.toImage();

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

//        lrucache = new LRUCache(ui->listWidget, 2, this);
//        QListWidgetItem *item_list = new QListWidgetItem();
//        item_list->setIcon(QIcon(QPixmap(filePath)));
//        item_list->setText(QFileInfo(filePath).fileName());
//        item_list->setData(Qt::UserRole, filePath);
//        lrucache->addItem(item_list);
        CustomWidget *customWidget = new CustomWidget(this);
        customWidget->set_text(QFileInfo(filePath).fileName());
        customWidget->setWindowIcon(QIcon(":icon_app/image/button_icon.png"));
        QListWidgetItem *item_list = new QListWidgetItem();
        item_list->setIcon(QIcon(QPixmap(filePath)));
        item_list->setData(Qt::UserRole, filePath);
        ui->listWidget->addItem(item_list);
        ui->listWidget->setItemWidget(item_list, customWidget);


//        lrucache->addItem(item_list);
        load_image(filePath);
//
////        BMPImage bmpImage;
////        bmpImage.set_width(bmpImageProcess.get_width());
////        bmpImage.set_height(bmpImageProcess.get_height());
////        bmpImage.set_pixels(pixels);
//        PPMImage ppmImage;
//        ppmImage.read_image(filePath.toStdString());
//        Image *image = dynamic_cast<Image *>(new PPMImage(ppmImage));
//
////        Image *image = dynamic_cast<Image *>(new BMPImage(bmpImage));
//        pixels = Convert::resized_image(image, 50, 150);
//        image->set_pixels(pixels);
//        Convert::grayscale(image);
//        Convert::ascii(image, "test.txt");
//        QString file_path = "/home/egerin/Projects/term_qt/cmake-build-debug/";
//        QUrl fileUrl = QUrl::fromLocalFile(file_path + "test.txt");
//
//        QDesktopServices::openUrl(fileUrl);
    }
}

void SecondScreen::on_list_item_clicked(QListWidgetItem *item) {
    QString filePath = item->data(Qt::UserRole).toString();
    if (!filePath.isEmpty()) {
        load_image(filePath);
    }
}

void SecondScreen::on_pushButton_2_clicked() {
    QListWidgetItem *selected_item = ui->listWidget->currentItem();
    if (selected_item) {
        QString filePath = selected_item->data(Qt::UserRole).toString();
        PPMImage ppmImage;
        ppmImage.read_image(filePath.toStdString());
        Image *image = dynamic_cast<Image *>(new PPMImage(ppmImage));
        std::vector<std::vector<Pixel>> pixels;
        pixels = Convert::resized_image(image, 50, 150);
        image->set_pixels(pixels);
        Convert::grayscale(image);
        Convert::ascii(image, "test.txt");
        QString file_path = "/home/egerin/Projects/term_qt/cmake-build-debug/";
        QUrl fileUrl = QUrl::fromLocalFile(file_path + "test.txt");

        QDesktopServices::openUrl(fileUrl);

    }

}
void SecondScreen::remove_item(const QString& text)
{
    for (int i = 0; i < ui->listWidget->count(); ++i) {
        auto item = ui->listWidget->item(i);
        auto itemWidget = qobject_cast<CustomWidget*>(ui->listWidget->itemWidget(item));
        if (itemWidget && itemWidget->get_text() == text) {
            delete itemWidget;
            delete ui->listWidget->takeItem(i);
            break;
        }
    }
}


bool SecondScreen::is_image(const QString &filePath) {
    return filePath.toLower().endsWith(".bmp") ||
           filePath.toLower().endsWith(".ppm");

}

//void SecondScreen::on_pushButton_3_clicked() {
//    QListWidgetItem *selected_item = ui->listWidget->currentItem();
//    if (selected_item) {
//        int row = ui->listWidget->row(selected_item);
//        delete ui->listWidget->takeItem(row);
//        qDebug() << "Deleted item: " << selected_item->text();
//    }
//}



