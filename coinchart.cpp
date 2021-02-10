#include "coinchart.h"
#include "core.h"
#include "mainwindow.h"
coinchart::coinchart(QWidget *parent) : QChartView(parent)
{
            srand(time(0));
}
void coinchart::init()
{
    c = new QChart;
    long long mx = 1000;
    for(int i=1; i<=5; i++)
    {
        lineList[i] = new QLineSeries;
        lineList[i]->setColor(tcore->bitcoinList[i]->color);
        lineList[i]->setName(tcore->bitcoinList[i]->coinName);
        c->addSeries(lineList[i]);
        mx = max(mx, tcore->bitcoinList[i]->currentPrice);
        yAxis.setRange(1, mx);
    }
    yAxis.setTitleText("价格");
    c->setAxisY(&yAxis);
    c->setTitle("实时走势图");

//    line1 = new QLineSeries();

//    for(double x=0;x<10;x+=0.1)
//    {

//        line1->append(x,sin(x));

//    }

//    QChart* c = new QChart();

//    c->addSeries(line1);

//    this->setChart(c);

    QTimer *timer = new QTimer(this);
    timer->start(1000);//一秒钟
    connect(timer,SIGNAL(timeout()),this,SLOT(update()));

    this->setChart(c);
}
void coinchart::update()
{

    long long mi = 1e9;
    long long mx = 0;
    for(int k=1; k<=5; k++)
    {
        mi = min(mi, tcore->bitcoinList[k]->currentPrice);
        mx = max(mx, tcore->bitcoinList[k]->currentPrice);
        if(tcore->bitcoinList[k]->lastValue.size() > 100)
        {
            tcore->bitcoinList[k]->lastValue.pop();
            lineList[k]->clear();
            queue<int> needDraw;
            needDraw = tcore->bitcoinList[k]->lastValue;
            int i = 0;
            while (!needDraw.empty())
            {
                lineList[k]->append(++i, needDraw.front());
                c->removeSeries(lineList[k]);
                c->addSeries(lineList[k]);
                needDraw.pop();
            }
        }
        else
        {
            lineList[k]->append(tcore->bitcoinList[k]->lastValue.size(), tcore->bitcoinList[k]->currentPrice);
            c->removeSeries(lineList[k]);
            c->addSeries(lineList[k]);

        }


    }

    yAxis.setRange(mi, mx);
    tcore->update();
    QChartView::update();
}
