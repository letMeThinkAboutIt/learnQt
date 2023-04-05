#include "MainWindow.h"
#include "ui_MainWindow.h"

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);

    ui->pushButton->setFlat(true);
    ui->pushButton_2->setObjectName("changsha");
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
    switch (index) {
        case 0 :
            break;

        case 1 :
            break;

        case 2 :{
            QString strQss = R"(
                QPushButton[flat="true"]{
                    color:orange;
                }
            )";
            this->setStyleSheet(strQss);
            break;
        }

        case 3 :
            break;

        case 4 :{

        }
        case 5 :{
            QString strQss = R"(
                QWidget>QPushButton{
                    color:red;
                }
            )";
            this->setStyleSheet(strQss);
            conment = "subWidget groupbox 都是widget的子类";
            break;
        }
        case 6 :{
            QString strQss = R"(
                .subWidget>QPushButton{
                    color:green;
                }
            )";
            this->setStyleSheet(strQss);
            conment = "subWidget 的直接子类";
            break;
        }
        case 7 :{
            QString strQss = R"(
                .subWidget QPushButton{
                    color:green;
                }
            )";
            this->setStyleSheet(strQss);
            conment = "subWidget 的直接或者间接子类";
            break;
        }
        case 8 :{
            QString strQss = R"(
                QPushButton#changsha{
                    color:blue;
                }
            )";
            this->setStyleSheet(strQss);
            break;
        }
    }
    ui->plainTextEdit->appendPlainText(ui->comboBox->currentText());
    ui->plainTextEdit->appendPlainText(conment);
}

