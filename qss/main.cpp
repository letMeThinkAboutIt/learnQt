#include "MainWindow.h"

#include <QApplication>

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);

    QString strQss = R"(
        QPushButton{
            color:red;
            background-color:pink;
        }
        QPushButton:hover{
            background-color:black;
        }
    )";
    a.setStyleSheet(strQss);

    MainWindow w;
    w.show();
    return a.exec();
}
