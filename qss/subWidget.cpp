#include "subWidget.h"
#include "ui_subWidget.h"

subWidget::subWidget(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::subWidget)
{
    ui->setupUi(this);
}

subWidget::~subWidget()
{
    delete ui;
}
