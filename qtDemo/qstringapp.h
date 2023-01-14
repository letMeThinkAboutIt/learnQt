#ifndef QSTRINGAPP_H
#define QSTRINGAPP_H

#include <QWidget>

namespace Ui {
class qStringApp;
}



class qStringApp : public QWidget
{
    Q_OBJECT

public:
    explicit qStringApp(QWidget *parent = nullptr);
    ~qStringApp();

    enum class numSys_e{
        bin,
        dec,
        hex,
        all
    };

private slots:
    void on_inputEdit_textChanged(const QString &arg1);

    void on_binBtn_clicked();

    void on_hexBtn_clicked();

    void on_decBtn_clicked();

    void on_allBtn_clicked();

private:
    void changeNumSystem();
    Ui::qStringApp *ui;
    numSys_e _ns;
};

#endif // QSTRINGAPP_H
