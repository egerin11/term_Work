

#include "customwidget.h"
#include "ui_customwidget.h"
#include "../secondscreen/secondscreen.h"
#include <QPushButton>


CustomWidget::CustomWidget(QWidget* parent)
        : QWidget(parent)
        , ui(new Ui::CustomWidget)
{
    ui->setupUi(this);
    ui->closeButton->setIcon(QIcon("icon_app/image/button_icon.png"));
    connect(this, &CustomWidget::sendRemoveItem, qobject_cast<SecondScreen*>(parent), &SecondScreen::remove_item);

    connect(ui->closeButton, &QPushButton::clicked, this, &CustomWidget::close_button_clicked);
}

CustomWidget::~CustomWidget() { }

void CustomWidget::set_text(const QString& text)
{
    ui->label->setText(text);
}

QString CustomWidget::get_text()
{
    return ui->label->text();
}

void CustomWidget::close_button_clicked()
{   qDebug()<<"click"<<ui->label->text();
    emit sendRemoveItem(ui->label->text());
}
