#include "qstringapp.h"
#include "ui_qstringapp.h"

#include <QRegExpValidator>



struct numSysInfo{
    qStringApp::numSys_e _ns;
    QString _label;
    QString _regularExpression;
    int _base;
};

static const  numSysInfo nsi[4] = {
    {qStringApp::numSys_e::bin, "input bin", "[0-1]+$", 2},
    {qStringApp::numSys_e::dec, "input dec", "[0-9]+$", 10},
    {qStringApp::numSys_e::hex, "input hex", "[a-fA-F0-9]+$", 16},
    {qStringApp::numSys_e::all, "input all", nullptr, 0}
};

qStringApp::qStringApp(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::qStringApp)
{
    ui->setupUi(this);
    this->setFixedWidth(640);
    this->setFixedHeight(360);

    this->on_decBtn_clicked();
}

qStringApp::~qStringApp()
{
    delete ui;
}

void qStringApp::on_inputEdit_textChanged(const QString &arg1)
{
    QString inputStr = arg1;
    int val = 0;
    bool ok;

    if (inputStr.indexOf(".") != -1){
        ui->binEdit->clear();
        ui->hexEdit->clear();
        ui->decEdit->setText(inputStr);
    }

    int arrayCnt = sizeof(nsi)/sizeof(numSysInfo);
    numSysInfo nsInfo;
    int i=0;

    for (i=0; i<arrayCnt; i++){
        if (nsi[i]._ns == _ns){
            break;
        }
    }
    if (i == arrayCnt){
        return;
    }
    nsInfo = nsi[i];

    val = inputStr.toInt(&ok, nsInfo._base);
    if (ok != true){
        return;
    }

    //数值转换为对应格式的字串
    ui->binEdit->setText(QString::number(val, 2));
    ui->hexEdit->setText(QString::number(val, 16));
    ui->decEdit->setText(QString::number(val));
}


void qStringApp::on_binBtn_clicked()
{
    _ns = qStringApp::numSys_e::bin;
    this->changeNumSystem();
}


void qStringApp::on_hexBtn_clicked()
{
    _ns = qStringApp::numSys_e::hex;
    this->changeNumSystem();
}


void qStringApp::on_decBtn_clicked()
{
    _ns = qStringApp::numSys_e::dec;
    this->changeNumSystem();
}


void qStringApp::on_allBtn_clicked()
{
    _ns = qStringApp::numSys_e::all;
    this->changeNumSystem();
}

void qStringApp::changeNumSystem()
{
    int arrayCnt = sizeof(nsi)/sizeof(numSysInfo);
    numSysInfo nsInfo;
    int i=0;

    for (i=0; i<arrayCnt; i++){
        if (nsi[i]._ns == _ns){
            break;
        }
    }
    if (i == arrayCnt){
        return;
    }
    nsInfo = nsi[i];

    ui->inputLabel->setText(nsInfo._label);
    ui->inputEdit->clear();
    if (nsInfo._regularExpression.isEmpty()){
        ui->inputEdit->setValidator(nullptr);
    }else if (nsInfo._ns == qStringApp::numSys_e::dec){
        ui->inputEdit->setValidator(new QDoubleValidator);
    }else{
        ui->inputEdit->setValidator(new QRegExpValidator(QRegExp(nsInfo._regularExpression)));
    }
    //设置焦点。 点击按钮后，输入栏就失去了焦点，调用这个函数获得焦点
    ui->inputEdit->setFocus();
}

