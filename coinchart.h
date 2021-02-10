#ifndef COINCHART_H
#define COINCHART_H

#include <QWidget>
#include <QTimer>
#include <QTime>
#include <QtCharts/QChartView>
#include <QtCharts/QLineSeries>
#include <QtCharts/QPieSeries>
#include <QValueAxis>
#include <cmath>
#include <algorithm>
using namespace QtCharts;
class core;
class coinchart : public QChartView
{
    Q_OBJECT
public:
    explicit coinchart(QWidget *parent = nullptr);
    core *tcore;
    void init();
private:
    QLineSeries* lineList[15];
    QChart *c;

    QValueAxis xAxis;
    QValueAxis yAxis;


signals:
public slots:
    void update();
};

#endif // COINCHART_H
