#include "numtransdlg.h"
#include <QLineEdit>
#include <QLabel>
#include <QPushButton>
#include <QGridLayout>
#include <QVBoxLayout>
#include <QHBoxLayout>
NumTransDlg::NumTransDlg(QWidget *parent)
    : QDialog(parent)
{
    QVBoxLayout* mainLayout = new QVBoxLayout(this);
    QGridLayout* editLayout = new QGridLayout;
    QHBoxLayout* buttonLayout = new QHBoxLayout;
    mainLayout->addLayout(editLayout);
    mainLayout->addStretch();
    mainLayout->addLayout(buttonLayout);
    QLabel* decLabel = new QLabel("十進位");
    QLabel* hexLabel = new QLabel("十六進位");
    QLabel* binLabel = new QLabel("二進位");
    decEdit = new QLineEdit;
    hexEdit = new QLineEdit;
    binEdit = new QLineEdit;
    editLayout->addWidget(decLabel,0,0);
    editLayout->addWidget(decEdit,0,1);
    editLayout->addWidget(hexLabel,1,0);
    editLayout->addWidget(hexEdit,1,1);
    editLayout->addWidget(binLabel,2,0);
    editLayout->addWidget(binEdit,2,1);
    exitButton = new QPushButton("結束");
    buttonLayout->addStretch();
    buttonLayout->addWidget(exitButton);
    connect(exitButton, SIGNAL(clicked()), this, SLOT(accept()));//當dialog物件中的accept()被呼叫後，dialog物件便會結束
    connect(decEdit,SIGNAL(textChanged(QString)),
            this,SLOT(decChanged(QString)));
    connect(hexEdit,SIGNAL(textChanged(QString)),
            this,SLOT(hexChanged(QString)));
    connect(binEdit,SIGNAL(textChanged(QString)),
            this,SLOT(binChanged(QString)));



}

NumTransDlg::~NumTransDlg() = default;

void NumTransDlg::decChanged(QString newValue)
{
    bool ok; //紀錄轉換是否成功?
    int num = newValue.toInt(&ok,10);
    if(ok)
    {
        hexEdit->setText(QString::number(num,16)); //<---是字串
        binEdit->setText(QString::number(num,2));
    }else
    {
        hexEdit->setText("???"); //<---是字串
        binEdit->setText("???");
    }
    qDebug() << decEdit->text();
    qDebug() << exitButton->text();

}
void NumTransDlg::hexChanged(QString newValue)
{
    bool ok; //紀錄轉換是否成功?
    int num = newValue.toInt(&ok,16);
    if(ok)
    {
        decEdit->setText(QString::number(num,10)); //<---是字串
        binEdit->setText(QString::number(num,2));
    }else
    {
        decEdit->setText("???"); //<---是字串
        binEdit->setText("???");
    }

}
void NumTransDlg::binChanged(QString newValue)
{
    bool ok; //紀錄轉換是否成功?
    int num = newValue.toInt(&ok,2);
    if(ok)
    {
        hexEdit->setText(QString::number(num,16)); //<---是字串
        decEdit->setText(QString::number(num,10));
    }else
    {
        hexEdit->setText("???"); //<---是字串
        decEdit->setText("???");
    }

}
