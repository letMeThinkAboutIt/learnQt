#include "MainWindow.h"
#include "ui_MainWindow.h"
#include "nameSpaceBtn.h"

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);

//testNsQss--nameSpaceBtn
/*

image->border-image->background-image
*/
    QString strQss = R"(
        QMainWindow {
            image:url(4c.png);
            border-image:url(border3.png) 2 2 2 2 strech repeat;
            background-image:url(back.bmp);
            border-width:20px;
        }


    )";

    this->setStyleSheet(strQss);
    //QCoreApplication::setAttribute(Qt::AA_UseStyleSheetPropagationInWidgetStyles, true);
}

MainWindow::~MainWindow()
{
    delete ui;
}


