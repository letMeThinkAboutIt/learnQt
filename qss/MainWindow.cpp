#include "MainWindow.h"
#include "ui_MainWindow.h"
#include "nameSpaceBtn.h"

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    ui->plainTextEdit->setObjectName("e1");
    ui->plainTextEdit_2->setObjectName("e2");
    ui->plainTextEdit_3->setObjectName("e3");
    ui->plainTextEdit_4->setObjectName("e4");

//testNsQss--nameSpaceBtn
/*
4个数字，代表选取多少像素作为边框的颜色。 0就会用背景色
border-width 会把选取的像素拉伸或者压缩

*/
    QString strQss = R"(
        QPlainTextEdit#e1 {
            border-image:url(border3.png) 1 1 1 1 repeat strech ;
            border-width:20px;
        }
        QPlainTextEdit#e2 {
            border-image:url(border3.png) 2 2 2 2 strech repeat  ;
            border-width:20px;
        }
        QPlainTextEdit#e3 {
            border-image:url(border3.png) 3 3 3 3 repeat repeat ;
            border-width:20px;
        }
        QPlainTextEdit#e4 {
            border-image:url(border3.png) 2 2 0 0 strech strech ;
            border-width:20px;
            background-color:pink;
        }

    )";

    this->setStyleSheet(strQss);
    //QCoreApplication::setAttribute(Qt::AA_UseStyleSheetPropagationInWidgetStyles, true);
}

MainWindow::~MainWindow()
{
    delete ui;
}


