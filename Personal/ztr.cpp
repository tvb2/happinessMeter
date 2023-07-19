#include "ztr.h"
#include "ui_ztr.h"

ZTR::ZTR(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::ZTR)
{
    ui->setupUi(this);
}

ZTR::~ZTR()
{
    delete ui;
}
