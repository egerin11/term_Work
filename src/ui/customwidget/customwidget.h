

#ifndef TERM_QT_CUSTOMWIDGET_H
#define TERM_QT_CUSTOMWIDGET_H

#include <QWidget>


QT_BEGIN_NAMESPACE
namespace Ui { class CustomWidget; }
QT_END_NAMESPACE

class CustomWidget : public QWidget {
Q_OBJECT

public:
    explicit CustomWidget(QWidget* parent = nullptr);
    ~CustomWidget();

    void set_text(const QString& text);


    QString get_text();

signals:
    void sendRemoveItem(const QString& text);

private slots:
    void close_button_clicked();

private:
    Ui::CustomWidget *ui;
};


#endif //TERM_QT_CUSTOMWIDGET_H
