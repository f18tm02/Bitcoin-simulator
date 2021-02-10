#include "mob.h"
#include "core.h"
mob::mob() {
    buyNum = 0;
    sellNum = 0;
    max2 = 1;
    type = 2;
    property = rand()%100000 + 100000;
}
void mob::update() {
    for (int i = 1; i <= 5; i++) {
        //dealTotal �ܽ�����
        if (tcore->bitcoinList[i]->dealTotal > tcore->bitcoinList[max2]->dealTotal) max2 = i;
    }						//sell
    //�۸� todo

    for (int g = 1; g <= 5; g++) {
        if (this->bitcoins[g] != 0 && g != max2) {
            int price = tcore->bitcoinList[g]->currentPrice * 0.6 + (rand()% tcore->bitcoinList[g]->currentPrice * 0.4);
            tcore->sellMent(g, this->bitcoins[g], price*this->bitcoins[g], this, price);

            //������max2֮��ı�
            //���� ���� ������
        }
    }
    int price = tcore->bitcoinList[max2]->currentPrice  + (rand()% tcore->bitcoinList[max2]->currentPrice * 0.4);
    tcore->buyMent(max2, this->property / tcore->bitcoinList[max2]->currentPrice, this->property / tcore->bitcoinList[max2]->currentPrice * price, this, price);						//buy
    //
}
