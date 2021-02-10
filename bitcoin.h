#ifndef BITCOIN_H
#define BITCOIN_H
#include <QString>
#include <QColor>
#include <queue>
#include <ctime>
#include <random>
#include <bill.h>
using namespace std;
class billpq;
class bitcoin
{
public:
    bitcoin();
    QString coinName;
    QColor color;
    long long currentPrice, i, total;

    int dealTotal;
    queue<int> lastDeal;
    queue<int> lastValue;
    queue<int> dealNumber;

    priority_queue<int> pLastDeal;
    priority_queue<int> pLastValue;

    billpq *buyBillList;
    billpq *sellBillList;
    void update();
private:
    void setCurrentPrice(int value)
    {
        this->currentPrice = value;
    }



};

#endif // BITCOIN_H
