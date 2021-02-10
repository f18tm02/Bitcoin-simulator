#ifndef MOB_H
#define MOB_H
#include <investor.h>

class mob: public investor
{
public:
    mob();
    void update();
    int buyNum, sellNum;
    int max2;
private:
    int growth;
};

#endif
