#include "bill.h"
#include "ui_bill.h"
#include "investor.h"
#include "core.h"

bill::bill(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::bill)
{
    ui->setupUi(this);
//    self = this;
}

bill::~bill()
{
    delete ui;
}
void bill::setBill(QString str1, QString str2, QString str3, int tp, bool buyOrSell, investor *per)
{
    ui->label->setText(str1);
    ui->label_3->setText(str2 + "C");
    number = str2.toInt();
    ui->label_2->setText(str3 + "$");
    price = str3.toInt();
    person = per;
    type = tp;
    bos = buyOrSell;
}
void bill::setNum(int num)
{
    ui->label_3->setText(QString::number(num) + "C");
}
bool bill::billDone(int num)
{
    if(person != NULL)
    {
        if(bos)
        {
            person->property -= num * price;
        }
        else
        {
            person->property += num * price;
        }

    }
    tcore->bitcoinList[type]+=num;
    if(num == number)
    {

        return true;
    }
    number -= num;

    return false;
}
