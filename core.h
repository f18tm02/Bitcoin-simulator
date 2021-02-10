#ifndef CORE_H
#define CORE_H
#include <ctime>
#include <random>
#include <bitcoin.h>
#include <algorithm>
#include <queue>
class investor;
class MainWindow;
class miner;
class player;
class bill;
class chive;
class mob;
class gangster;
class company;
class core
{
public:
    core();
    ~core();
    void setNum(int, int, int, int);
    void setCore(int, int, int, int);
    void setTradeRange(int, int);
    void setCoinNum(int);
    void update();
    bool setuped;

    bitcoin coin1;
    bitcoin coin2;
    bitcoin coin3;
    bitcoin coin4;
    bitcoin coin5;
    int chiveNum, mobNum, gangsterNum, companyNum;
    int chiveCore, mobCore, gangsterCore, companyCore;
    int tradeLeft, tradeRight;
    int coinNum;
    int total;

    MainWindow *tmainWindow;

    miner *coreMiner;
    player *tplayer;

    chive *chiveList[100005];
    mob *mobList[100005];
    gangster *gangsterList[100005];
    company *companyList[100005];

    bitcoin *bitcoinList[105];
    void addBuyBill(int type, int number, int price, investor *buyer);
    void addSellBill(int type, int number, int price, investor *seller);
    void buyMent(int type, int number, int money, investor *buyer, int price);
    void sellMent(int type, int number, int money, investor *buyer, int price);

    const bool buy = true, sell = false;
    QString investorType[4] = {"Chive", "Mob", "Gangster", "Company"};

//    int totalDeal;
    void init();

private:
    void simloop();



};

#endif // CORE_H
