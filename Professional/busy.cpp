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
    //show People group when either RB is selected
    QObject::connect(ui->RBOccupationFun, &QRadioButton::clicked, this, &Busy::visPeople);
    QObject::connect(ui->RBRBOccupationNorm, &QRadioButton::clicked, this, &Busy::visPeople);
    QObject::connect(ui->RBOccupationDull, &QRadioButton::clicked, this, &Busy::visPeople);

//Money widgets
    ui->GBMoney->setEnabled(false);
    QObject::connect(ui->RBPeopleGreat, &QRadioButton::clicked, this, &Busy::visMoney);
    QObject::connect(ui->RBPeopleNorm, &QRadioButton::clicked, this, &Busy::visMoney);
    QObject::connect(ui->RBPeopleUgly, &QRadioButton::clicked, this, &Busy::visMoney);

//buttons
    ui->PBOK->setEnabled(false);
    QObject::connect(ui->RBMoneyExc, &QRadioButton::clicked, this, &Busy::visPBOK);
    QObject::connect(ui->RBMoneyNorm, &QRadioButton::clicked, this, &Busy::visPBOK);
    QObject::connect(ui->RBMoneyBad, &QRadioButton::clicked, this, &Busy::visPBOK);
    QObject::connect(ui->PBOK, &QPushButton::clicked, this, &Busy::finalize);
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

void Busy::visPeople(){
    if (!ui->GBPeople->isEnabled())
        ui->GBPeople->setEnabled(true);
}
void Busy::visMoney(){
    if (!    ui->GBMoney->isEnabled())
        ui->GBMoney->setEnabled(true);
}
void Busy::visPBOK(){
    if (!ui->PBOK->isEnabled())
        ui->PBOK->setEnabled(true);
    this->complete = true;
}
void Busy::closeEvent (QCloseEvent *event)
{
    if (!this->complete){
    QMessageBox::StandardButton resBtn = QMessageBox::question(this, "Professional Life",
                                                               tr("Please select at least one option in each group\n"),
                                                               QMessageBox::Ok | QMessageBox::NoButton, QMessageBox::Ok);
        event->ignore();
    }
    else{
        event->accept();
    }
}
void Busy::keyPressEvent(QKeyEvent *evt)
{
    if(evt->key() == Qt::Key_Escape)
            return;
    QDialog::keyPressEvent(evt);
}
void Busy::finalize(){
    this->close();
}
