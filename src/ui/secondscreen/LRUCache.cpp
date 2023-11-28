#include "LRUCache.h"

void LRUCache::addItem(QListWidgetItem *item) {
    QString key = item->text();
    if (items_.contains(key)) {
        lruList_.removeAll(key);
        lruList_.prepend(key);
    } else {
        items_.insert(key);
        listWidget_->addItem(item);
        lruList_.prepend(key);
    }

    while (items_.size() > capacity_) {
        QString oldestItem = lruList_.last();
        lruList_.removeLast();
        items_.remove(oldestItem);
        remove_item_from_list_widget(oldestItem);
    }
}

void LRUCache::on_item_clicked(QListWidgetItem *item) {
    QString key = item->text();
    if (lruList_.contains(key)) {
        lruList_.removeAll(key);
        lruList_.prepend(key);
    }

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
