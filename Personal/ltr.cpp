#include "ltr.h"
#include "ui_ltr.h"

LTR::LTR(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::LTR)
{
    ui->setupUi(this);
}

LTR::~LTR()
{
    delete ui;
}
