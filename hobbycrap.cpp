#include "hobbycrap.h"
#include "ui_hobbycrap.h"

HobbyCrap::HobbyCrap(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::HobbyCrap)
{
    ui->setupUi(this);
}

HobbyCrap::~HobbyCrap()
{
    delete ui;
}
