#ifndef GANGSTER_H
#define GANGSTER_H
#include <investor.h>

class gangster : public investor
{
public:
    gangster();
    int target;
    int patience;//忍耐次数
    int outbreak;//忍不住时抛出
    int lastbuy;//上一波买进的币号
    int lastcount[5];//上一波买进时的人数
    void update();
private:
    int growth;
};

#endif
