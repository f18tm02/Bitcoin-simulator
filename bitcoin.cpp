#include "bitcoin.h"
#include "bill.h"
#include "billpq.h"
bitcoin::bitcoin()
{
    srand(time(0));
    this->currentPrice = 50 + (rand()%951);
    this->total = 0;
    buyBillList = new billpq;
    sellBillList = new billpq;
    dealTotal = 0;
}
void bitcoin::update()
{
    this->lastValue.push(this->currentPrice);
}
