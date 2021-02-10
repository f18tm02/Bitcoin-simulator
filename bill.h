#ifndef BILL_H
#define BILL_H

#include <QWidget>
#include <QListWidget>
namespace Ui {
class bill;
}
class core;
class investor;
class bill : public QWidget
{
    Q_OBJECT

public:
    explicit bill(QWidget *parent = nullptr);
    void setBill(QString str1, QString str2, QString str3, int type, bool buyOrSell, investor *per);
    ~bill();

    long long price;
    int number;
    int type;
    int total;
    int totalOwn;
    int posInQ;

    QListWidgetItem *faItem;
    bool bos;
    investor *person;

    core *tcore;

    void setNum(int num);
//    bill *self;

    bool operator < (const bill &A) const
    {
        if(bos)
        {
            return price < A.price;
        }
        return price > A.price;
    }

    bool billDone(int num);
private:
    Ui::bill *ui;
public slots:

};

#endif // BILL_H
