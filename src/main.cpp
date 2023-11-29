#include <QApplication>
#include <QPushButton>
#include "ui/mainwindow/mainwindow.h"

int main(int argc, char *argv[]) {
    QApplication a(argc, argv);
    MainWindow w;
    QIcon appIcon(":icon_app/image/icon2.png");
    a.setWindowIcon(appIcon);
    w.show();
    return a.exec();
}
