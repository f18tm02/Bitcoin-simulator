#include "company.h"
#include "core.h"
company::company() {
    srand(time(0));
    property = rand() % 1000000 + 100000;
    target = rand() % 5 + 1;
    type = 4;
    investor();
}
void company::update() {
    if (rand() % 100 == 1) {
        int num = rand()%10+1, price = tcore->bitcoinList[target]->currentPrice + 100;

        tcore->buyMent(target, num, num*price, this, price);
    }
    else if (rand() % 100 == 1) {
        int num = rand()%10+1, price = tcore->bitcoinList[target]->currentPrice + 100;
        tcore->sellMent(target, num, num*price, this, price);
    }
}
