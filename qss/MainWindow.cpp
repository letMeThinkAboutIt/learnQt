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
        QLabel {
            background-color:pink;
            margin:20px 40px 60px 80px;
            padding:20px 40px 60px 80px;


            border-image:url(border3.png) 2 2 2 2 strech repeat;
            border-width:20px;
            border-radius:40px;
            background-clip:margin;
            background-origin:border;

            text-align: center center;
        }


    )";

    this->setStyleSheet(strQss);
    //QCoreApplication::setAttribute(Qt::AA_UseStyleSheetPropagationInWidgetStyles, true);
}

MainWindow::~MainWindow()
{
    delete ui;
}


