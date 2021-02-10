#ifndef INVESTOR_H
#define INVESTOR_H
#include <ctime>
#include <random>
class core;
class bill;
class investor
{
public:
    investor();
    ~investor();
    void update();
    const int chive = 1, mob = 2, gangster = 3, company = 4;
    long long property;
    int i;
    int type;
    long long bitcoins[15];
    bill *lastBill;

    core *tcore;
private:

};

#endif // INVESTOR_H
