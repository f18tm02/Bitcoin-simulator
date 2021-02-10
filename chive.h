#ifndef CHIVE_H
#define CHIVE_H
#include <investor.h>

class chive : public investor
{
public:
    chive();
    void update();
    int lastbuy;
    int max1;
    int buy;
    int k;
private:
    int growth;
};

#endif
