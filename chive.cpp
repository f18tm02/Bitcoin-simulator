#include "chive.h"
#include "core.h"
chive::chive()
{
    srand(time(0));
    property  = tcore->chiveCore*0.8 + (rand()%(int)(tcore->chiveCore*0.4+1));
    growth = 2 + (rand()%9);
    investor();
    k = rand() % 20 + 1;
    max1 = 0;
    type = 1;
}
void chive::update() {
//    double test[5] = {0};
//    int buy[5] = {0};
//    for (int g = 1; g <= 5; g++) {
//        for (int i = 100; i >= 1; i--) {
//            test[g] = (tcore->bitcoinList[g]->lastValue.back() - tcore->bitcoinList[g]->lastValue.front()) / (100.0 - i);
//            if (test[g] >= k) buy[g] = 1;
//        }
//    }
//    int maxk;
//    for (int i = 1; i <= 5; i++) {
//        if (buy[i] == 1 && maxk < test[i]) {
//            maxk = test[i];
//            max1 = i;
//        }
//    }
//    if (max1 != lastbuy) {
//        buy = tcore->bitcoinList[i]->lastValue.back() / tcore->bitcoinList[i]->lastValue.front();
//        tcore->sellMent(lastbuy, 1, tcore->bitcoinList[lastbuy]);
//        tcore->buyMent(max1, 1, tcore->bitcoinList[max1]);
//        lastbuy = max1;
//    }
}
