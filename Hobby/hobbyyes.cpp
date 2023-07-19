#include "hobbyyes.h"
#include "ui_hobbyyes.h"

HobbyYes::HobbyYes(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::HobbyYes)
{
    ui->setupUi(this);
}

HobbyYes::~HobbyYes()
{
    delete ui;
}
