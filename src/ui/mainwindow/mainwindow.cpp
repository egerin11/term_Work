
#include "mainwindow.h"
#include "ui_mainwindow.h"


MainWindow::MainWindow(QWidget *parent)
        : QMainWindow(parent), ui(new Ui::MainWindow) {
    ui->setupUi(this);
    QLinearGradient gradient(0, 0, width(), height());
    gradient.setColorAt(1, QColor(255, 236, 210, 215));
    gradient.setColorAt(0, QColor(252, 182, 159, 200));
    QBrush brush(gradient);
    QPalette palette = this->palette();
    palette.setBrush(QPalette::Window, brush);
    this->setPalette(palette);

    stackedWidget = new QStackedWidget(this);

    stackedWidget->addWidget(ui->centralwidget);

    setCentralWidget(stackedWidget);
}

MainWindow::~MainWindow() {
    delete ui;
}




void MainWindow::on_pushButton_clicked()
{
    if (!secondScreen) {
        secondScreen = new SecondScreen(this);
        stackedWidget->addWidget(secondScreen);
    }
    stackedWidget->setCurrentWidget(secondScreen);
}

