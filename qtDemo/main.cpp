#include <QApplication>

#define QSTRING_APP

#ifdef QSTRING_ENCODE
#include "qstringencode.h"
#elif defined QSTRING_APP
#include "qstringapp.h"
#endif

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);

#ifdef QSTRING_ENCODE
    QStringEncode w;
#elif defined QSTRING_APP
    qStringApp w;
#endif

    w.show();
    return a.exec();
}
