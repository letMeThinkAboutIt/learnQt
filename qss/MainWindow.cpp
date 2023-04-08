#include "MainWindow.h"
#include "ui_MainWindow.h"
#include "nameSpaceBtn.h"

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);



    QPushButton * button1 = new testNsQss::nameSpaceBtn("testbtn", nullptr);
    button1->setObjectName("localbtn");
    ui->gridLayout_2->addWidget(button1);

//testNsQss--nameSpaceBtn
/*
padding:50px 50px 50px 50px;
margin:50px 50px 50px 50px;
background-clip:margin;
color:red;
background-color: pink;
*/
    QString strQss = R"(

        QPushButton{
            border-style:outset;
            border-width:10px;
            border-color:red;
            padding:50px 50px 50px 50px;
            margin:50px 50px 50px 50px;
            background-clip:margin;
            color:red;
            background-color: pink;
        }
        QPushButton#localbtn{
            border-style:outset;
            border-width:10px;
            border-color:red;
            padding:-50px 50px -50px 50px;
            margin:50px 50px 50px 50px;
            background-clip:margin;
            color:red;
            background-color: pink;
        }
    )";

    this->setStyleSheet(strQss);
    //QCoreApplication::setAttribute(Qt::AA_UseStyleSheetPropagationInWidgetStyles, true);
}

MainWindow::~MainWindow()
{
    delete ui;
}


