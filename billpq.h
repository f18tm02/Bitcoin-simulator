#ifndef BILLPQ_H
#define BILLPQ_H
class bill;
class node
{
public:
    bill *tbill;
};

class billpq
{
public:
    billpq();
    bill *top();
    void push(bill *obj);
    void pop();
    void swap(int a, int b);
    void del(int i);
    bool empty();
    int tail;
    node *heap[1000005];
};

#endif // BILLPQ_H
