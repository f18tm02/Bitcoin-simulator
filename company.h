#ifndef COMPANY_H
#define COMPANY_H
#include <investor.h>
class company : public investor
{
public:
    company();
    void update();
    int target;
private:
    int growth;
};

#endif
