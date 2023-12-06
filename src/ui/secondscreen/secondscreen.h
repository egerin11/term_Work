//
// Created by egerin on 11/27/23.
//

#ifndef TERM_QT_SECONDSCREEN_H
#define TERM_QT_SECONDSCREEN_H

#include <QWidget>
#include<QStackedWidget>
#include <QGraphicsScene>
#include <QGraphicsPixmapItem>
#include <QFileDialog>
#include <QDir>
#include <QDebug>
#include <QListWidget>
QT_BEGIN_NAMESPACE
namespace Ui { class SecondScreen; }
QT_END_NAMESPACE

class SecondScreen : public QWidget {
Q_OBJECT

public:
    explicit SecondScreen(QWidget *parent = nullptr);

    ~SecondScreen() override;
public slots:
    void remove_item(const QString& text);
private slots:

    void on_list_item_clicked(QListWidgetItem *item);
    void on_pushButton_clicked();
    void on_pushButton_2_clicked();

private:
    bool is_image(const QString &filePath);
    void load_image(const QString &file_path);
    Ui::SecondScreen *ui;
    QGraphicsScene *scene;

};


#endif //TERM_QT_SECONDSCREEN_H
