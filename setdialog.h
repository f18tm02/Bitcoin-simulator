#ifndef SETDIALOG_H
#define SETDIALOG_H

#include <QDialog>
#include <core.h>
namespace Ui {
class setDialog;
}

class setDialog : public QDialog
{
    Q_OBJECT

public:
    explicit setDialog(QWidget *parent = nullptr);
    ~setDialog();
    core *tcore;

private:
    Ui::setDialog *ui;
public slots:
    void done(int);
};

#endif // SETDIALOG_H
