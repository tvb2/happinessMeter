#include "professionallife.h"
#include "ui_professionallife.h"

ProfessionalLife::ProfessionalLife(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::ProfessionalLife)
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

ProfessionalLife::~ProfessionalLife()
{
    delete ui;
}

void ProfessionalLife::on_RBOccupationFun_clicked()
{
    if (!ui->GBPeople->isEnabled())
        ui->GBPeople->setEnabled(true);
}
void ProfessionalLife::on_RBRBOccupationNorm_clicked()
{
    if (!ui->GBPeople->isEnabled())
        ui->GBPeople->setEnabled(true);
}
void ProfessionalLife::on_RBOccupationDull_clicked()
{
    if (!ui->GBPeople->isEnabled())
        ui->GBPeople->setEnabled(true);
}


void ProfessionalLife::on_RBPeopleGreat_clicked()
{
    if (!    ui->GBMoney->isEnabled())
            ui->GBMoney->setEnabled(true);
}
void ProfessionalLife::on_RBPeopleNorm_clicked()
{
    if (!    ui->GBMoney->isEnabled())
            ui->GBMoney->setEnabled(true);
}
void ProfessionalLife::on_RBPeopleUgly_clicked()
{
    if (!    ui->GBMoney->isEnabled())
            ui->GBMoney->setEnabled(true);
}


void ProfessionalLife::on_radioButton_3_clicked()
{
    if (!ui->PBOK->isEnabled())
            ui->PBOK->setEnabled(true);
}
void ProfessionalLife::on_radioButton_4_clicked()
{
    if (!ui->PBOK->isEnabled())
            ui->PBOK->setEnabled(true);
}
void ProfessionalLife::on_radioButton_5_clicked()
{
    if (!ui->PBOK->isEnabled())
            ui->PBOK->setEnabled(true);
}


void ProfessionalLife::on_PBOK_clicked()
{
    ProfessionalLife::~ProfessionalLife();
}

void ProfessionalLife::closeEvent (QCloseEvent *event)
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
