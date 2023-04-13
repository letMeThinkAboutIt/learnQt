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
    ui->plainTextEdit_5->setObjectName("e5");
    ui->plainTextEdit_6->setObjectName("e6");
    ui->plainTextEdit_7->setObjectName("e7");
    ui->plainTextEdit_8->setObjectName("e8");

//testNsQss--nameSpaceBtn
/*

background-clip 表示显示的区域
background-origin 表示background-image显示的区域

background-color不受上面2个配置id影响，会填充整个margin
*/
    QString strQss = R"(
        QPlainTextEdit#e1 {
            background-color:blue;
            /*background-image:url(desktop.png);*/
            margin:30px;
            border:10px double red;
            padding:30px;
            background-origin:margin;
            background-clip:margin;
        }
        QPlainTextEdit#e2 {
            background-color:blue;
            /*background-image:url(desktop.png);*/
            margin:30px;
            border:10px double red;
            padding:30px;
            background-origin:border;
            background-clip:margin;
        }
        QPlainTextEdit#e3 {
            background-color:blue;
            background-image:url(desktop.png);
            margin:30px;
            border:10px double red;
            padding:30px;
            background-origin:margin;
            background-clip:margin;
        }
        QPlainTextEdit#e4 {
            background-color:blue;
            background-image:url(desktop.png);
            margin:30px;
            border:10px double red;
            padding:30px;
            background-origin:border;
            background-clip:margin;
        }
    )";

    this->setStyleSheet(strQss);
    //QCoreApplication::setAttribute(Qt::AA_UseStyleSheetPropagationInWidgetStyles, true);
}

MainWindow::~MainWindow()
{
    delete ui;
}


