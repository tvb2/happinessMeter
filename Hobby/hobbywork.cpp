#include "hobbywork.h"
#include "ui_hobbywork.h"

HobbyWork::HobbyWork(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::HobbyWork)
{
    ui->setupUi(this);
}

HobbyWork::~HobbyWork()
{
    delete ui;
}
