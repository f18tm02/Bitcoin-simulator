#include "mainwindow.h"

#include <QApplication>
#include <setdialog.h>
#include <QMessageBox>
#include <core.h>
#include <player.h>
int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
    setDialog *setdia = new setDialog;
    core *simcore = new core;
    player *thePlayer = new player;
    simcore->tplayer = thePlayer;
    setdia->tcore = simcore;

    setdia->show();
    setdia->exec();

    if(!simcore->setuped)
    {
        QApplication::setQuitOnLastWindowClosed(true);
        QMessageBox::warning(NULL, "warning", "Simulation canceled.");
        return 0;
    }

    simcore->init();
    MainWindow w(nullptr, simcore);
    simcore->tmainWindow = &w;


    w.show();
    return a.exec();
}
