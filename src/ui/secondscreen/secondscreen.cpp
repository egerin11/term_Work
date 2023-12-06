
#include "secondscreen.h"
#include "ui_secondscreen.h"
#include "src_back/data_model/get_bmp_data/BMPImageProcess.h"
#include "src_back/data/header/bmp_image.h"
#include "src_back/data/header/ppm_image.h"
#include "../customwidget/customwidget.h"
#include "src_back/data/header/other_image.h"
#include <QImageReader>
#include <QFileDialog>
#include <QDesktopServices>
#include <QMessageBox>

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

    ui->listWidget->setMinimumSize(400, 600);
    ui->graphicsView->setMinimumSize(600, 600);
    connect(ui->listWidget, &QListWidget::itemClicked, this, &SecondScreen::on_list_item_clicked);
}


SecondScreen::~SecondScreen() {
    delete ui;
}

void SecondScreen::load_image(const QString &file_path) {
    QPixmap pixmap(file_path);

    if (!pixmap.isNull()) {

        scene = new QGraphicsScene;
        scene->clear();
        QGraphicsPixmapItem *graphicsItem = new QGraphicsPixmapItem(pixmap);

        ui->graphicsView->setScene(scene);
        scene->addItem(graphicsItem);

        ui->graphicsView->fitInView(graphicsItem->boundingRect(), Qt::KeepAspectRatio);

        qDebug() << "Opened file: " << file_path;
    }
}


void SecondScreen::on_pushButton_clicked() {
    QString file_path = QFileDialog::getOpenFileName(this, "Выберите файл", QDir::homePath(),
                                                     "Изображения(*.png *.jpg *.jpeg *.bmp *.gif *.ppm)");
    if (!file_path.isEmpty()) {
        QImageReader imageReader(file_path);
        imageReader.setFormat("PPM");
        QImage qImage=imageReader.read();
        if (!qImage.isNull()) {
            for (int i = 0; i < ui->listWidget->count(); ++i) {
                QListWidgetItem *existingItem = ui->listWidget->item(i);
                QString existingFilePath = existingItem->data(Qt::UserRole).toString();
                if (existingFilePath == file_path) {
                    QMessageBox::information(this, "Предупреждение", "Этот файл уже добавлен.");
                    return;
                }
            }
            CustomWidget *customWidget = new CustomWidget(this);
            customWidget->set_text(QFileInfo(file_path).fileName());

            QListWidgetItem *item_list = new QListWidgetItem();
            item_list->setSizeHint(QSize(40, 40));
            item_list->setIcon(QIcon(QPixmap(file_path)));
            item_list->setData(Qt::UserRole, file_path);
            ui->listWidget->addItem(item_list);
            ui->listWidget->setItemWidget(item_list, customWidget);

            load_image(file_path);
        } else {
            QMessageBox::warning(this, "Ошибка", "Выбранный файл не является изображением.");
        }
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
        int view_width = 100;
        int view_height = 100;
        Image *image;
        QString file_path = selected_item->data(Qt::UserRole).toString();

        std::vector<std::vector<Pixel>> pixels;

        if (!is_image(file_path)) {
            OtherImage otherImage;
            pixels=otherImage.read(file_path);
            otherImage.set_pixels(pixels);
            image = dynamic_cast<Image *>(new OtherImage(otherImage));

        } else if (file_path.toLower().endsWith(".bmp")) {
            BMPImageProcess bmpImageProcess;
            bmpImageProcess.read_image(file_path.toStdString());
            pixels = bmpImageProcess.get_pixels();
            BMPImage bmpImage;
            bmpImage.set_width(bmpImageProcess.get_width());
            bmpImage.set_height(bmpImageProcess.get_height());
            bmpImage.set_pixels(pixels);
            image = dynamic_cast<Image *>(new BMPImage(bmpImage));

        } else {
            PPMImage ppmImage;
            ppmImage.read_image(file_path.toStdString());
            image = dynamic_cast<Image *>(new PPMImage(ppmImage));
        }
        pixels = Convert::resized_image(image, view_height, view_width);
        image->set_pixels(pixels);
        Convert::grayscale(image);
        Convert::ascii(image, "test.txt");
        QString txt_file_path = "/home/egerin/Projects/term_qt/cmake-build-debug/";
        QUrl fileUrl = QUrl::fromLocalFile(txt_file_path + "test.txt");

        QDesktopServices::openUrl(fileUrl);
        delete image;

    }
}

void SecondScreen::remove_item(const QString &text) {
    for (int i = 0; i < ui->listWidget->count(); ++i) {
        auto item = ui->listWidget->item(i);
        auto itemWidget = qobject_cast<CustomWidget *>(ui->listWidget->itemWidget(item));
        if (itemWidget && itemWidget->get_text() == text) {
            delete itemWidget;
            delete ui->listWidget->takeItem(i);
            break;
        }
    }
    for (QGraphicsItem *scene_item: ui->graphicsView->scene()->items()) {
        if (scene_item->data(0).toString() == text && scene_item->isVisible()) {
            ui->graphicsView->scene()->removeItem(scene_item);
            break;
        }
    }
    ui->graphicsView->scene()->clear();
}


bool SecondScreen::is_image(const QString &file_path) {
    return file_path.toLower().endsWith(".bmp") ||
           file_path.toLower().endsWith(".ppm");

}



