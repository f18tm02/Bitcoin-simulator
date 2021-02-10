#include "billpq.h"
#include "bill.h"
billpq::billpq()
{
    tail = 0;
}
bill* billpq::top()
{
    return heap[1]->tbill;
}
void billpq::swap(int a, int b)
{
    heap[a]->tbill->posInQ = b;
    heap[b]->tbill->posInQ = a;
    node *c = heap[a];
    heap[a] = heap[b];
    heap[b] = c;
}
void billpq::push(bill *obj)
{
    heap[++tail] = new node;
    heap[tail]->tbill = obj;
    int it = tail;
    obj->posInQ = tail;
    while(it / 2 >= 1)
    {
        if(heap[it/2]->tbill < heap[it]->tbill)
        {
            swap(it, it/2);
            it /= 2;
        }
        else {
            break;
        }
    }
}
void billpq::pop()
{
    int it = 1;
    swap(1, tail);
    tail--;
    while(it * 2 <= tail)
    {
        int lc = it * 2;
        int rc = it * 2 + 1;
        if(rc <= tail && heap[lc]->tbill < heap[rc]->tbill)
        {
            lc = rc;
        }
        if(heap[it]->tbill < heap[lc]->tbill) swap(it, lc);
        it = lc;
    }
}
bool billpq::empty()
{
    return tail == 0;
}
void billpq::del(int i)
{
    int it = i;
    swap(i, tail);
    tail--;
    while(it * 2 <= tail)
    {
        int lc = it * 2;
        int rc = it * 2 + 1;
        if(rc <= tail && heap[lc]->tbill < heap[rc]->tbill)
        {
            lc = rc;
        }
        if(heap[it]->tbill < heap[lc]->tbill) swap(it, lc);
        it = lc;
    }
}
