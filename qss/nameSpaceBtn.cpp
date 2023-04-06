#include "nameSpaceBtn.h"

#include <QVBoxLayout>

using namespace testNsQss;

nameSpaceBtn::nameSpaceBtn(QString txt, QWidget * parent):QPushButton(txt, parent)
{

}

void nameSpaceBtn::paintEvent(QPaintEvent * event) {
    QPushButton::paintEvent(event);
}
