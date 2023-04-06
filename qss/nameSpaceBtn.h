#ifndef NAMESPACEBTN_H
#define NAMESPACEBTN_H

#include <QGroupBox>
#include <QPushButton>

namespace testNsQss {


class nameSpaceBtn : public QPushButton
{
    Q_OBJECT
public:
    nameSpaceBtn(QString txt, QWidget * parent);
    void paintEvent(QPaintEvent *) override;
};

}
#endif // NAMESPACEBTN_H
