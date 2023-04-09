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
hsv 色度 饱和度 亮度
色度 0 红色； 120 绿色； 240 蓝色； 范围 0-360
    可以理解成一个圆环，3个点将圆环均分成3分，点与点之间的颜色用插值算出来。
饱和度 颜色与白色的混合，色度为0就是白色
    还是圆环，圆心为色度0，圆周为色度255，一条半径上颜色越来越偏白
    饱和度接近0，颜色几乎是灰
亮度 亮度为0，任何颜色都为黑色

*/
    QString strQss = R"(
        QMainWindow {
            background:url(4c.png) no-repeat center ;
        }

    )";

    this->setStyleSheet(strQss);
    //QCoreApplication::setAttribute(Qt::AA_UseStyleSheetPropagationInWidgetStyles, true);
}

MainWindow::~MainWindow()
{
    delete ui;
}


