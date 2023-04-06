#include "MainWindow.h"
#include "ui_MainWindow.h"
#include "nameSpaceBtn.h"

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);



    QPushButton * button1 = new testNsQss::nameSpaceBtn("testbtn", nullptr);
    ui->gridLayout_2->addWidget(button1);

//testNsQss--nameSpaceBtn
    QString strQss = R"(

        testNsQss--nameSpaceBtn{
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


