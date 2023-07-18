#include "hobbyno.h"
#include "ui_hobbyno.h"

HobbyNo::HobbyNo(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::HobbyNo)
{
    ui->setupUi(this);
}

HobbyNo::~HobbyNo()
{
    delete ui;
}
