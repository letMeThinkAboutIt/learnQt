#include "nameSpaceBtn.h"

#include <QPainter>
#include <QStyleOption>
#include <QVBoxLayout>

using namespace testNsQss;

nameSpaceBtn::nameSpaceBtn(QString txt, QWidget * parent):QPushButton(txt, parent)
{

}

void nameSpaceBtn::paintEvent(QPaintEvent * event) {
#if 1
    QStyleOption op;
    op.init(this);
    QPainter p(this);
    style()->drawPrimitive(QStyle::PE_Widget, &op, &p, this);

#else
    QPushButton::paintEvent(event);
#endif
}
