#include "MainWindow.h"
#include "ui_MainWindow.h"

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);

    ui->pushButton->setProperty("testp", "true");
    ui->pushButton->setProperty("testp1", "true");
    ui->pushButton_2->setObjectName("changsha");

    this->setObjectName("qss");
}

MainWindow::~MainWindow()
{
    delete ui;
}


void MainWindow::on_newWidget_clicked()
{

}


void MainWindow::on_comboBox_currentIndexChanged(int index)
{
    QString conment;
    conment = "ID > 属性 > 伪状态 ; 多个伪状态>一个伪状态; 特殊性一样，靠后优先；"
              "ID 伪状态和属性 类型名称 a-b-c";
    switch (index) {

        case 1 :{
            QString strQss = R"(
                QPushButton{
                    color:blue;
                    background-color:pink;
                }
                QPushButton:hover{
                    background-color:black;
                }
                QPushButton[testp1="true"]{
                    color:green;
                }
                QPushButton[testp="true"]{
                    color:red;
                }

                QPushButton#changsha{
                    color:orange;
                }
                QPushButton#changsha:hover{
                    background-color:blue;
                }

            )";
            this->setStyleSheet(strQss);
            break;
        }
        case 2 :{
            //ID 伪状态和属性 类型名称
            QString strQss = R"(

                QWidget QPushButton#changsha{
                    color:blue;
                    background-color:blue;
                }
                QWidget#qss QPushButton{
                    color:blue;
                    background-color:pink;
                }
            )";
            this->setStyleSheet(strQss);
            conment.append("有父子关系的控件，ID数会累加");
            break;
        }
    }
    ui->plainTextEdit->appendPlainText(ui->comboBox->currentText());
    ui->plainTextEdit->appendPlainText(conment);
}

