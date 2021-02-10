#include "core.h"
#include "investor.h"
#include "mainwindow.h"
#include "miner.h"
#include "bill.h"
#include "billpq.h"
#include "player.h"
#include "company.h"
#include "chive.h"
#include "gangster.h"
#include "mob.h"
core::core()
{
    srand(time(0));
    setuped = false;
    coin1.coinName = "BTC";
    coin1.color = Qt::black;
    coin2.coinName = "BCH";
    coin2.color = Qt::green;
    coin3.coinName = "BSV";
    coin3.color = Qt::yellow;
    coin4.coinName = "EOS";
    coin4.color = Qt::blue;
    coin5.coinName = "RomanCoin";
    coin5.color = Qt::red;
    bitcoinList[1] = &coin1;
    bitcoinList[2] = &coin2;
    bitcoinList[3] = &coin3;
    bitcoinList[4] = &coin4;
    bitcoinList[5] = &coin5;

    coreMiner = new miner(this);

}
void core::update()
{
    tmainWindow->displayPlayerProperty(tplayer->property);
    coreMiner->update();
    for(int i=1; i<=5; i++)
    {
//        bitcoinList[i]->currentPrice = bitcoinList[i]->currentPrice - (rand()%(int)(bitcoinList[i]->currentPrice*0.2)) + (rand()%(int)(bitcoinList[i]->currentPrice*0.2));
        bitcoinList[i]->update();
    }
    for(int i=1; i<=companyNum; i++)
    {
        if(companyList[i] != NULL)
        {
            companyList[i]->update();
        }
    }
    for(int i=1; i<=gangsterNum; i++)
    {
        if(gangsterList[i] != NULL)
        {
            gangsterList[i]->update();
        }
    }
    for(int i=1; i<=chiveNum; i++)
    {
        if(chiveList[i] != NULL)
        {
            chiveList[i]->update();
        }
    }
    for(int i=1; i<=mobNum; i++)
    {
        if(mobList[i] != NULL)
        {
            mobList[i]->update();
        }
    }
    tmainWindow->displayInvestorList();
}
void core::setNum(int ch, int mo, int ga, int co)
{
    chiveNum = ch, mobNum = mo, gangsterNum = ga, companyNum = co;
    total = ch + mo + ga + co;
}
void core::setCore(int ch, int mo, int ga, int co)
{
    chiveCore = ch, mobCore = mo, gangsterCore = ga, companyCore = co;
}
void core::setTradeRange(int l, int r)
{
    tradeLeft = l, tradeRight = r;
}
void core::init()
{
    for(int i=1; i<=chiveNum; i++)
    {
        chiveList[i] = new chive;
        chiveList[i]->i = i;
        chiveList[i]->tcore = this;
    }
    for(int i=1; i<=mobNum; i++)
    {
        mobList[i] = new mob;
        mobList[i]->i = i;
        mobList[i]->tcore = this;
    }
    for(int i=1; i<=gangsterNum; i++)
    {
        gangsterList[i] = new gangster;
        gangsterList[i]->i = i;
        gangsterList[i]->tcore = this;
    }
    for(int i=1; i<=companyNum; i++)
    {
        companyList[i] = new company;
        companyList[i]->i = i;
        companyList[i]->tcore = this;

    }
}
void core::addBuyBill(int type, int number, int price, investor *buyer)
{
    tmainWindow->drawBuyBill(type, number, price, buyer);
}
void core::addSellBill(int type, int number, int price, investor *seller)
{
    tmainWindow->drawSellBill(type, number, price, seller);
}
void core::buyMent(int type, int number, int money, investor *buyer, int price)
{
    buyer->property -= money;
    while (true) {
        if(bitcoinList[type]->sellBillList->empty()) break;
        bill *best = bitcoinList[type]->sellBillList->top();
        if(price < best->price)
        {
            break;
        }
        if(money < best->price)
        {
            return;
        }
        int num = best->number;
        if(best->billDone(min(number, num)))
        {
            number -= num;
            buyer->bitcoins[type] += num;
            money -= num * best->price;
            bitcoinList[type]->currentPrice = best->price;
            tmainWindow->deleteSellBill(best);/*
            bitcoinList[type]->buyBillList->pop();*/

        }
        else
        {
            money -= number*best->price;
            buyer->property += money;
            number = 0;
            return;
        }
    }
    buyer->property += money;
    addBuyBill(type, number, price, buyer);
}
void core::sellMent(int type, int number, int money, investor *seller, int price)
{
    seller->property += money;
    while (true) {
        if(bitcoinList[type]->buyBillList->empty()) break;
        bill *best = bitcoinList[type]->buyBillList->top();
        if(price > best->price)
        {
            break;
        }
        int num = best->number;
        if(best->billDone(min(number, num)))
        {
            number -= num;
            seller->bitcoins[type] -= num;
            money -= num * best->price;
            tmainWindow->deleteBuyBill(best);/*
            bitcoinList[type]->sellBillList->pop();*/
            bitcoinList[type]->currentPrice = best->price;
        }
        else
        {
            money -= number*best->price;
            number = 0;
            seller->property -= money;
            return;
        }
    }
    seller->property -= money;
    addSellBill(type, number, price, seller);
}
