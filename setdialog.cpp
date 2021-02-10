#include "setdialog.h"
#include "ui_setdialog.h"
#include "player.h"
setDialog::setDialog(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::setDialog)
{
    tcore = 0;
    ui->setupUi(this);
}

setDialog::~setDialog()
{
    delete ui;
}
void setDialog::done(int result)
{
    if(result == QDialog::Accepted)
    {
        if(tcore != 0)
        {
            tcore->setNum(ui->lineEdit_5->text().toInt(),
                          ui->lineEdit_6->text().toInt(),
                          ui->lineEdit_7->text().toInt(),
                          ui->lineEdit_8->text().toInt());
            tcore->setCore(ui->lineEdit->text().toInt(),
                           ui->lineEdit_2->text().toInt(),
                           ui->lineEdit_3->text().toInt(),
                           ui->lineEdit_4->text().toInt());
            tcore->setTradeRange(ui->lineEdit_10->text().toInt(),
                                 ui->lineEdit_9->text().toInt());
            tcore->tplayer->property = ui->lineEdit_11->text().toInt();
            tcore->setuped = true;
        }
    }
    QDialog::done(result);
}
