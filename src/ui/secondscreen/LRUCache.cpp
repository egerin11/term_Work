#include "LRUCache.h"

void LRUCache::addItem(QListWidgetItem* item) {
    QString key = item->text();
    if (items_.contains(key)) {
        items_.removeOne(key);
    } else {
        listWidget_->addItem(item);
    }
    items_.prepend(key);

    while (items_.size() > capacity_) {
        QString oldestItem = items_.last();
        items_.removeLast();
        remove_item_from_list_widget(oldestItem);
    }
}

void LRUCache::on_item_clicked(QListWidgetItem* item) {
    addItem(item);
}

void LRUCache::remove_item_from_list_widget(const QString& key) {
    for (int i = 0; i < listWidget_->count(); ++i) {
        QListWidgetItem* item = listWidget_->item(i);
        if (item && item->text() == key) {
            delete item;
            break;
        }
    }
}