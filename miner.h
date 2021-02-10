#ifndef MINER_H
#define MINER_H
#include <ctime>
#include <random>
class core;
class MainWindow;
class miner
{
public:
    miner(core *tc);
    void update();
    core *tcore;
    MainWindow *tmainwindow;
};

#endif // MINER_H
