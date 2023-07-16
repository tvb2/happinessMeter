#include "str.h"
#include "ui_str.h"

STR::STR(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::STR)
{
    ui->setupUi(this);
}

STR::~STR()
{
    delete ui;
}
