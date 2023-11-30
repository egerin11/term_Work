//
// Created by egerin on 11/28/23.
//

#ifndef TERM_QT_LRUCACHE_H
#define TERM_QT_LRUCACHE_H

#include <QListWidget>
#include <QMap>
#include <QSet>

class LRUCache : public QObject {
Q_OBJECT
public:
    explicit LRUCache(QListWidget *listWidget, int capacity, QObject *parent = nullptr)
            : QObject(parent), listWidget_(listWidget), capacity_(capacity) {
        connect(listWidget, &QListWidget::itemClicked, this, &LRUCache::on_item_clicked);
    }

    void addItem(QListWidgetItem* item);

private slots:
    void on_item_clicked(QListWidgetItem* item);

private:
    void remove_item_from_list_widget(const QString& key);
    QListWidget* listWidget_;
    int capacity_;
    QVector<QString> items_;  // Using QVector to maintain the order
};


#endif //TERM_QT_LRUCACHE_H
