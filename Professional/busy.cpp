#include "busy.h"
#include "ui_busy.h"

Busy::Busy(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::Busy)
{
    ui->setupUi(this);


//initially widgets are not visible

//Occupationwidgets

//People widgets
    ui->GBPeople->setEnabled(false);

//Money widgets
    ui->GBMoney->setEnabled(false);

//buttons
    ui->PBOK->setEnabled(false);

}

Busy::~Busy()
{
    delete ui;
}
/*
void Busy::on_RBOccupationFun_clicked()
{
    if (!ui->GBPeople->isEnabled())
        ui->GBPeople->setEnabled(true);
}
void Busy::on_RBRBOccupationNorm_clicked()
{
    if (!ui->GBPeople->isEnabled())
        ui->GBPeople->setEnabled(true);
}
void Busy::on_RBOccupationDull_clicked()
{
    if (!ui->GBPeople->isEnabled())
        ui->GBPeople->setEnabled(true);
}


void Busy::on_RBPeopleGreat_clicked()
{
    if (!    ui->GBMoney->isEnabled())
            ui->GBMoney->setEnabled(true);
}
void Busy::on_RBPeopleNorm_clicked()
{
    if (!    ui->GBMoney->isEnabled())
            ui->GBMoney->setEnabled(true);
}
void Busy::on_RBPeopleUgly_clicked()
{
    if (!    ui->GBMoney->isEnabled())
            ui->GBMoney->setEnabled(true);
}


void Busy::on_radioButton_3_clicked()
{
    if (!ui->PBOK->isEnabled())
            ui->PBOK->setEnabled(true);
}
void Busy::on_radioButton_4_clicked()
{
    if (!ui->PBOK->isEnabled())
            ui->PBOK->setEnabled(true);
}
void Busy::on_radioButton_5_clicked()
{
    if (!ui->PBOK->isEnabled())
            ui->PBOK->setEnabled(true);
}
void Busy::on_PBOK_clicked()
*/

void Busy::closeEvent (QCloseEvent *event)
{
    QMessageBox::StandardButton resBtn = QMessageBox::question(this, "Professional Life",
                                                               tr("Please select at least one option in each group\n"),
                                                               QMessageBox::Ok | QMessageBox::NoButton, QMessageBox::Ok);
//  (here check if at least one option was selected in each group and if so, accept, otherwise)
    if (false)
            event->accept();
    else
            event->ignore();
}
