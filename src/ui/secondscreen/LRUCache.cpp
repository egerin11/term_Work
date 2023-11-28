#include "LRUCache.h"

void LRUCache::addItem(QListWidgetItem *item) {
    QString key = item->text();
    if (items_.contains(key)) {
        lruList_.removeAll(key);
        lruList_.append(key);
    } else {
        items_.insert(key);
        listWidget_->addItem(item);
    }

    while (items_.size() > capacity_) {
        QString oldestItem = lruList_.first();
        lruList_.removeFirst();
        items_.remove(oldestItem);
        remove_item_from_list_widget(oldestItem);
    }

    lruList_.removeAll(key);
    lruList_.append(key);
}

void LRUCache::on_item_clicked(QListWidgetItem *item) {
    QString key = item->text();
    // Move the clicked item to the most recently used position
    lruList_.removeAll(key);
    lruList_.append(key);
}

void LRUCache::remove_item_from_list_widget(const QString &key) {
    for (int i = 0; i < listWidget_->count(); ++i) {
        QListWidgetItem* item = listWidget_->item(i);
        if (item && item->text() == key) {
            delete item;
            break;
        }
    }
}
