QT       += core gui
QT       += charts

greaterThan(QT_MAJOR_VERSION, 4): QT += widgets

CONFIG += c++11

# You can make your code fail to compile if it uses deprecated APIs.
# In order to do so, uncomment the following line.
#DEFINES += QT_DISABLE_DEPRECATED_BEFORE=0x060000    # disables all the APIs deprecated before Qt 6.0.0

SOURCES +=  \
    bill.cpp \
    billpq.cpp \
    bitcoin.cpp \
    chive.cpp \
    coinchart.cpp \
    company.cpp \
    core.cpp \
    gangster.cpp \
    investor.cpp \
    main.cpp \
    mainwindow.cpp \
    miner.cpp \
    mob.cpp \
    player.cpp \
    setdialog.cpp

HEADERS +=  \
    bill.h \
    billpq.h \
    bitcoin.h \
    chive.h \
    coinchart.h \
    company.h \
    core.h \
    gangster.h \
    investor.h \
    mainwindow.h \
    miner.h \
    mob.h \
    player.h \
    setdialog.h

FORMS += \
    bill.ui \
    mainwindow.ui \
    setdialog.ui

# Default rules for deployment.
qnx: target.path = /tmp/$${TARGET}/bin
else: unix:!android: target.path = /opt/$${TARGET}/bin
!isEmpty(target.path): INSTALLS += target
