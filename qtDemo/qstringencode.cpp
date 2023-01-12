#include "qstringencode.h"
#include "ui_qstringencode.h"

#include <QString>
#include <QStringLiteral>
#include <QTextCodec>
#include <QDebug>

QStringEncode::QStringEncode(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::QStringEncode)
{
    ui->setupUi(this);
}

QStringEncode::~QStringEncode()
{
    delete ui;
}

unsigned char ANSIHex[] = {0xC4, 0xE3, 0xBA, 0xC3, 0xCA, 0xC0, 0xBD, 0xE7, 0x00};
unsigned char GBKHex[] = {0xC4, 0xE3, 0xBA, 0xC3, 0xCA, 0xC0, 0xBD, 0xE7, 0x00};
unsigned char UTF8Hex[] = {0xE4, 0xBD, 0xA0, 0xE5, 0xA5, 0xBD, 0xE4, 0xB8, 0x96, 0xE7, 0x95, 0x8C, 0x00};
unsigned char UTF16Hex[] = {0xFF, 0xFE, 0x60, 0x4F, 0x7D, 0x59, 0x16, 0x4E, 0x4C, 0x75, 0x00};

void QStringEncode::on_pushButton_clicked()
{
    QString ANSIStr((char*)ANSIHex);
    QString GBKStr((char*)GBKHex);
    QString UTF8Str((char*)UTF8Hex);
    QString UTF16Str((char*)UTF16Hex);

    ui->strANSILabel->setText(ANSIStr);
    ui->strGBKLabel->setText(GBKStr);
    ui->strUTF8Label->setText(UTF8Str);
    ui->strUTF16Label->setText(UTF16Str);
}


void QStringEncode::on_pushButton_2_clicked()
{
    QString ANSIStr = QString::fromUtf16((const ushort*)ANSIHex);
    QString GBKStr = QString::fromUtf16((const ushort*)GBKHex);
    QString UTF8Str = QString::fromUtf16((const ushort*)UTF8Hex);
    QString UTF16Str = QString::fromUtf16((const ushort*)UTF16Hex);

    ui->strANSILabel->setText(ANSIStr);
    ui->strGBKLabel->setText(GBKStr);
    ui->strUTF8Label->setText(UTF8Str);
    ui->strUTF16Label->setText(UTF16Str);
}



void QStringEncode::on_pushButton_4_clicked()
{
    QString ANSIStr( QLatin1String((char*)ANSIHex) );
    QString GBKStr( QLatin1String((char*)GBKHex) );
    QString UTF8Str( QLatin1String((char*)UTF8Hex) );
    QString UTF16Str( QLatin1String((char*)UTF16Hex) );

    ui->strANSILabel->setText(ANSIStr);
    ui->strGBKLabel->setText(GBKStr);
    ui->strUTF8Label->setText(UTF8Str);
    ui->strUTF16Label->setText(UTF16Str);
}


void QStringEncode::on_pushButton_5_clicked()
{
    auto toQString = [](char * pString)->QString{
        QTextCodec *codecUTF8 = QTextCodec::codecForName("UTF-8");
        QTextCodec *codecUTF16 = QTextCodec::codecForName("UTF-16");
        QTextCodec *codecGBK = QTextCodec::codecForName("GBK");
        QTextCodec *codecANSI = QTextCodec::codecForName("ANSI");

        QString s;

        if (codecUTF8 != nullptr){
            QTextCodec::ConverterState state;
            s = codecUTF8->toUnicode(pString, strlen(pString) , &state);
            if (state.invalidChars == 0){
                return s;
            }
        }

        if (codecGBK != nullptr){
            QTextCodec::ConverterState state;
            s = codecGBK->toUnicode(pString, strlen(pString) , &state);
            if (state.invalidChars == 0){
                return s;
            }

        }

        if (codecUTF16 != nullptr){
            QTextCodec::ConverterState state;
            s = codecUTF16->toUnicode(pString, strlen(pString) , &state);
            if (state.invalidChars == 0){
                return s;
            }
        }

        if (codecANSI != nullptr){
            QTextCodec::ConverterState state;
            s = codecANSI->toUnicode(pString, strlen(pString) , &state);
            if (state.invalidChars == 0){
                return s;
            }
        }

        return nullptr;
    };

    QString ANSIStr = toQString( (char*)ANSIHex );
    QString GBKStr = toQString( (char*)GBKHex );
    QString UTF8Str = toQString( (char*)UTF8Hex );
    QString UTF16Str = toQString( (char*)UTF16Hex );

    ui->strANSILabel->setText(ANSIStr);
    ui->strGBKLabel->setText(GBKStr);
    ui->strUTF8Label->setText(UTF8Str);
    ui->strUTF16Label->setText(UTF16Str);
}
