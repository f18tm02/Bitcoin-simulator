#ifndef GANGSTER_H
#define GANGSTER_H
#include <investor.h>

class gangster : public investor
{
public:
    gangster();
    int target;
    int patience;//���ʹ���
    int outbreak;//�̲�סʱ�׳�
    int lastbuy;//��һ������ıҺ�
    int lastcount[5];//��һ�����ʱ������
    void update();
private:
    int growth;
};

#endif
