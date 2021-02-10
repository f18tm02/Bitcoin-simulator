#include "miner.h"
#include "core.h"
#include "mainwindow.h"
miner::miner(core *tc)
{
    tcore = tc;
}
void miner::update()
{

    srand(time(0));
    if(rand()%5 == 0)
    {
        int type = (rand()%5)+1, num = (rand()%10)+1;
        switch (type) {
            case 1:
                tcore->coin1.total += num;
                break;
            case 2:
                tcore->coin2.total += num;
                break;
            case 3:
                tcore->coin3.total += num;
                break;
            case 4:
                tcore->coin4.total += num;
                break;
            case 5:
                tcore->coin5.total += num;
                break;

        }
        tcore->addSellBill(type, num, tcore->bitcoinList[type]->currentPrice, NULL);
    }
}
