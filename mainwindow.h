#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include <cmath>
QT_BEGIN_NAMESPACE
namespace Ui { class MainWindow; }
QT_END_NAMESPACE

class core;
class bill;
class investor;
class QListWidgetItem;
class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    MainWindow(QWidget *parent = nullptr, core *tc = NULL);
    ~MainWindow();
    void drawBuyBill(int type, int number, int price, investor *buyer);
    void drawSellBill(int type, int number, int price, investor *seller);
    void deleteBuyBill(bill *ob);
    void deleteSellBill(bill *ob);
    void displayPlayerProperty(long long val);
    void displayInvestorList();


    core *tcore;

private:
    Ui::MainWindow *ui;
public slots:

    void displayDetailBuyBill(QListWidgetItem *item);
    void displayDetailSellBill(QListWidgetItem *item);
    void playerBuy();
    void playerSell();
//    void aBuyDeal();
//    void aSellDeal();
};
#endif // MAINWINDOW_H
