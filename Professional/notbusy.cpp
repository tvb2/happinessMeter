#include "notbusy.h"
#include "ui_notbusy.h"

NotBusy::NotBusy(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::NotBusy)
{
    ui->setupUi(this);
}

NotBusy::~NotBusy()
{
    delete ui;
}
