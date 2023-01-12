#ifndef QSTRINGENCODE_H
#define QSTRINGENCODE_H

#include <QMainWindow>
/**
 * @author lr
 * @attention
 *      弄清楚qstring字符编码和中文乱码的问题
 *      QStirng是采用UTF-16编码的。
 *      QString stores a string of 16-bit QChars, where each QChar corresponds to one UTF-16 code unit
 *
 *      1.构造QString时，默认用的是UTF-8,相当于QString::fromUtf8
 *          即按UTF8的方式解析字节流，并转换成UTF16存储
 *      2.fromlocal8bit 那就是按local的编码格式解析字节流，并转换成UTF16存储。
 *      3.如果不知道字节流的编码格式，是无法一步到位操作的。
 * @date    	01-JAN-2023
*/
QT_BEGIN_NAMESPACE
namespace Ui { class QStringEncode; }
QT_END_NAMESPACE

class QStringEncode : public QMainWindow
{
    Q_OBJECT

public:
    QStringEncode(QWidget *parent = nullptr);
    ~QStringEncode();
private slots:
    void on_pushButton_clicked();

    void on_pushButton_2_clicked();

    void on_pushButton_4_clicked();

    void on_pushButton_5_clicked();

private:
    Ui::QStringEncode *ui;
};
#endif // QSTRINGENCODE_H
