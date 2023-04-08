#include "MainWindow.h"
#include "ui_MainWindow.h"
#include "nameSpaceBtn.h"

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);

    ui->pushButton->setObjectName("btn1");
    ui->pushButton_2->setObjectName("btn2");
    ui->pushButton_3->setObjectName("btn3");
//testNsQss--nameSpaceBtn
/*
hsv 色度 饱和度 亮度
色度 0 红色； 120 绿色； 240 蓝色； 范围 0-360
    可以理解成一个圆环，3个点将圆环均分成3分，点与点之间的颜色用插值算出来。
饱和度 颜色与白色的混合，色度为0就是白色
    还是圆环，圆心为色度0，圆周为色度255，一条半径上颜色越来越偏白
    饱和度接近0，颜色几乎是灰
亮度 亮度为0，任何颜色都为黑色

*/
    QString strQss = R"(

        QPushButton#btn1{
            background:qlineargradient(x1:0, y1:0, x2:0.5, y2:0.5,
                stop: 0 #ff0000,
                stop: 0.5 #00ff00,
                stop: 1 #0000ff);
        }
        QPushButton#btn2{
            background:qradialgradient(cx:0, cy:0, radius:0.5, fx:0.25, fy:0.25
                stop: 0 #ff0000,
                stop: 0.5 #00ff00,
                stop: 1 #0000ff);
        }
        QPushButton#btn3{
            background:qconicalgradient(cx:0.5, cy:0.5, angle:45,
                stop: 0 #ff0000,
                /*stop: 0.5 #00ff00,*/
                stop: 1 #0000ff);
        }
    )";

    this->setStyleSheet(strQss);
    //QCoreApplication::setAttribute(Qt::AA_UseStyleSheetPropagationInWidgetStyles, true);
}

MainWindow::~MainWindow()
{
    delete ui;
}


