//
//#ifndef TERM_QT_EVENTS_H
//#define TERM_QT_EVENTS_H
//
//#include<QListWidget>
//
//
//#include <QWidget>
//
//namespace Ui {
//    class CustomWidget;
//}
//
//class CustomWidget : public QWidget {
//Q_OBJECT
//
//public:
//    explicit CustomWidget(QWidget* parent = nullptr);
//    ~CustomWidget();
//
//    void setText(const QString& text);
//    QString getText();
//
//signals:
//    void send_remove_item(const QString& text);
//
//private slots:
//    void close_button_clicked();
//
//private:
//    std::unique_ptr<Ui::CustomWidget> ui;
//};
//
//#endif //TERM_QT_EVENTS_H
