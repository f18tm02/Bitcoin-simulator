#include "mainwindow.h"
#include "ui_mainwindow.h"
#include "bill.h"
#include "core.h"
#include "billpq.h"
#include "player.h"
#include "chive.h"
#include "company.h"
#include "gangster.h"
#include "mob.h"
#include <QMessageBox>
MainWindow::MainWindow(QWidget *parent, core *tc)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    tcore = tc;
    ui->chartview->tcore = tcore;
    ui->chartview->init();

    QObject::connect(ui->listWidget, SIGNAL(itemClicked(QListWidgetItem*)), this, SLOT(displayDetailBuyBill(QListWidgetItem*)));
    QObject::connect(ui->listWidget_2, SIGNAL(itemClicked(QListWidgetItem*)), this, SLOT(displayDetailSellBill(QListWidgetItem*)));
    QObject::connect(ui->pushButton_2, SIGNAL(clicked()), this, SLOT(playerBuy()));
    QObject::connect(ui->pushButton, SIGNAL(clicked()), this, SLOT(playerSell()));


    for(int i=1; i<=tcore->companyNum; i++)
    {
        if(tcore->companyList[i] != NULL)
        {
            QListWidgetItem *newItem = new QListWidgetItem;

            this->ui->listWidget_3->addItem(newItem);
             newItem->setText(QString::number(tcore->companyList[i]->i) + " " + tcore->investorType[tcore->companyList[i]->type-1] + "  MONEY: $" + QString::number(tcore->companyList[i]->property));
        }
    }

}
MainWindow::~MainWindow()
{
    delete ui;
}
void MainWindow::drawBuyBill(int type, int number, int price, investor *buyer)
{
    QListWidgetItem *item = new QListWidgetItem;
    ui->listWidget->addItem(item);
    item->setSizeHint(QSize(50, 50));
    bill *newbill = new bill;
    QWidget *bWidget = new QWidget;
    newbill->setParent(bWidget);
    newbill->setBill(tcore->bitcoinList[type]->coinName, QString::number(number), QString::number(price), type, true, buyer);
    newbill->faItem = item;
    tcore->bitcoinList[type]->buyBillList->push(newbill);
    ui->listWidget->setItemWidget(item, bWidget);


}
void MainWindow::drawSellBill(int type, int number, int price, investor *seller)
{
    QListWidgetItem *item = new QListWidgetItem;
    this->ui->listWidget_2->addItem(item);
    item->setSizeHint(QSize(70, 70));
    bill *newbill = new bill;


    QWidget *bWidget = new QWidget;
    newbill->setParent(bWidget);
    newbill->faItem = item;
    newbill->setBill(tcore->bitcoinList[type]->coinName, QString::number(number), QString::number(price), type, false, seller);
    tcore->bitcoinList[type]->sellBillList->push(newbill);
    this->ui->listWidget_2->setItemWidget(item, bWidget);
}
void MainWindow::displayDetailBuyBill(QListWidgetItem* item)
{
    QWidget *iw = this->ui->listWidget->itemWidget(item);
    bill *displayBill = iw->findChild<bill*>();
    if(displayBill != NULL)
    {
        ui->label_3->setText(tcore->bitcoinList[displayBill->type]->coinName);
        ui->label_4->setText("价格" + QString::number(displayBill->price));
        ui->label_2->setText("数量" + QString::number(displayBill->number));
    }



}
void MainWindow::displayDetailSellBill(QListWidgetItem *item)
{
    QWidget *iw = this->ui->listWidget_2->itemWidget(item);
    bill *displayBill = iw->findChild<bill*>();
    if(displayBill != NULL)
    {
        ui->label_6->setText(tcore->bitcoinList[displayBill->type]->coinName);
        ui->label_7->setText("价格" + QString::number(displayBill->price));
        ui->label_8->setText("数量" + QString::number(displayBill->number));
    }

}
void MainWindow::deleteBuyBill(bill *ob)
{
    tcore->bitcoinList[ob->type]->buyBillList->del(ob->posInQ);
    ui->listWidget->takeItem(ui->listWidget->currentRow());

    delete ob->faItem;
}
void MainWindow::deleteSellBill(bill *ob)
{
    tcore->bitcoinList[ob->type]->sellBillList->del(ob->posInQ);
    ui->listWidget_2->takeItem(ui->listWidget->currentRow());

    delete ob->faItem;

}
void MainWindow::displayPlayerProperty(long long val)
{
    ui->label->setText("MONEY: $" + QString::number(val));
    ui->label_12->setText(tcore->bitcoinList[1]->coinName + ":" + QString::number(tcore->tplayer->bitcoins[1]));
    ui->label_13->setText(tcore->bitcoinList[2]->coinName + ":" + QString::number(tcore->tplayer->bitcoins[2]));
    ui->label_14->setText(tcore->bitcoinList[3]->coinName + ":" + QString::number(tcore->tplayer->bitcoins[3]));
    ui->label_15->setText(tcore->bitcoinList[4]->coinName + ":" + QString::number(tcore->tplayer->bitcoins[4]));
    ui->label_16->setText(tcore->bitcoinList[5]->coinName + ":" + QString::number(tcore->tplayer->bitcoins[5]));

}
void MainWindow::playerBuy()
{

    int num = ui->lineEdit_2->text().toInt();

    QWidget *iw = this->ui->listWidget_2->itemWidget(this->ui->listWidget_2->currentItem());
    bill *displayBill = iw->findChild<bill*>();
    if(num == 0 || num > displayBill->number)
    {
        QMessageBox::warning(NULL, "warning", "数字无效");
        return;
    }
    if(displayBill != NULL)
    {
        if(displayBill->price * num > tcore->tplayer->property)
        {
            QMessageBox::warning(NULL, "warning", "你没有足够的钱");
            return;
        }
        tcore->tplayer->bitcoins[displayBill->type] += num;
        tcore->tplayer->property -= num * displayBill->price;

        if(displayBill->billDone(num))
        {
            deleteSellBill(displayBill);
        }
        else
        {
            displayBill->setNum(displayBill->number);
        }

    }
    else
    {
        QMessageBox::warning(NULL, "warning", "没有选中的卖单");
    }
}

void MainWindow::playerSell()
{
    int num = ui->lineEdit->text().toInt();

    QWidget *iw = this->ui->listWidget->itemWidget(this->ui->listWidget->currentItem());
    bill *displayBill = iw->findChild<bill*>();

    if(num == 0 || num > displayBill->number)
    {
        QMessageBox::warning(NULL, "warning", "数字无效");
        return;
    }

    if(displayBill != NULL)
    {
        if(num > tcore->tplayer->bitcoins[displayBill->type])
        {
            QMessageBox::warning(NULL, "warning", "你没有足够的" + tcore->bitcoinList[displayBill->type]->coinName);
            return;
        }
        tcore->tplayer->bitcoins[displayBill->type] -= num;
        tcore->tplayer->property += num * displayBill->price;
        if(displayBill->billDone(num))
        {
            deleteBuyBill(displayBill);
        }
        else
        {
            displayBill->setNum(displayBill->number);
        }

    }
    else
    {
        QMessageBox::warning(NULL, "warning", "没有选中的买单");
    }
}
void MainWindow::displayInvestorList()
{
    for(int i=1; i<=ui->listWidget_3->count(); i++)
    {

        if(tcore->companyList[i] != NULL)
        {
            ui->listWidget_3->item(i-1)->setText(QString::number(tcore->companyList[i]->i) + " " + tcore->investorType[tcore->companyList[i]->type-1] + "  MONEY: $" + QString::number(tcore->companyList[i]->property));
        }
    }
}
