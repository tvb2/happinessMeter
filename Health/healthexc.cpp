#include "healthexc.h"
#include "ui_healthexc.h"

HealthExc::HealthExc(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::HealthExc)
{
    ui->setupUi(this);
}

HealthExc::~HealthExc()
{
    delete ui;
}
