

#include "mainwindow.h"
#include "ui_mainwindow.h"
#include <QDebug>


MainWindow::MainWindow(QWidget *parent)
        : QMainWindow(parent), ui(new Ui::MainWindow) {
    ui->setupUi(this);
    QString new_title = "ASCII-ART";
    setWindowTitle(new_title);
    QLinearGradient gradient(0, 0, width(), height());
    gradient.setColorAt(1, QColor(255, 236, 210, 215));
    gradient.setColorAt(0, QColor(252, 182, 159, 200));
    QBrush brush(gradient);
    QPalette palette = this->palette();
    palette.setBrush(QPalette::Window, brush);
    this->setPalette(palette);

    stackedWidget = new QStackedWidget(this);

    stackedWidget->addWidget(ui->centralwidget);

    secondScreen = new SecondScreen(this);
    stackedWidget->addWidget(secondScreen);

    setCentralWidget(stackedWidget);
}

void MainWindow::on_pushButton_clicked() {
    stackedWidget->setCurrentWidget(secondScreen);
}


MainWindow::~MainWindow() {
    delete ui;
}