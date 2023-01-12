#include "qstringencode.h"

#include <QApplication>

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
    QStringEncode w;
    w.show();
    return a.exec();
}
