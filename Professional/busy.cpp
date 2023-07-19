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
    QObject::connect(ui->RBOccupationFun, &QRadioButton::clicked, this, &Busy::occupationSet);
    QObject::connect(ui->RBOccupationNorm, &QRadioButton::clicked, this, &Busy::occupationSet);
    QObject::connect(ui->RBOccupationDull, &QRadioButton::clicked, this, &Busy::occupationSet);

//Money widgets
    ui->GBMoney->setEnabled(false);
    QObject::connect(ui->RBPeopleGreat, &QRadioButton::clicked, this, &Busy::peopleSet);
    QObject::connect(ui->RBPeopleNorm, &QRadioButton::clicked, this, &Busy::peopleSet);
    QObject::connect(ui->RBPeopleUgly, &QRadioButton::clicked, this, &Busy::peopleSet);

//buttons
    ui->PBOK->setEnabled(false);
    QObject::connect(ui->RBMoneyExc, &QRadioButton::clicked, this, &Busy::moneySet);
    QObject::connect(ui->RBMoneyNorm, &QRadioButton::clicked, this, &Busy::moneySet);
    QObject::connect(ui->RBMoneyBad, &QRadioButton::clicked, this, &Busy::moneySet);
    QObject::connect(ui->PBOK, &QPushButton::clicked, this, &Busy::finalize);
}

Busy::~Busy(){
    delete ui;
}

void Busy::occupationSet(){
//make available the next section
    if (!ui->GBPeople->isEnabled())
        ui->GBPeople->setEnabled(true);

//set rating based on selection
    if (ui->RBOccupationFun->isChecked())
        this->occupation = 1;
    if (ui->RBOccupationNorm->isChecked())
        this->occupation = 0.5;
    if (ui->RBOccupationDull->isChecked())
        this->occupation = 0;

}
void Busy::peopleSet(){
    //make available the next section
    if (!    ui->GBMoney->isEnabled())
        ui->GBMoney->setEnabled(true);

//set rating based on selection
    if (ui->RBPeopleGreat->isChecked())
        this->people = 1;
    if (ui->RBPeopleNorm->isChecked())
        this->people= 0.5;
    if (ui->RBPeopleUgly->isChecked())
        this->people= 0;
}
void Busy::moneySet(){
//make available the next section
    if (!ui->PBOK->isEnabled())
        ui->PBOK->setEnabled(true);

//set rating based on selection
    if (ui->RBMoneyExc->isChecked())
        this->money = 1;
    if (ui->RBMoneyNorm->isChecked())
        this->money= 0.5;
    if (ui->RBMoneyBad->isChecked())
        this->money= 0;

//flag to report that all options have been set
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
        this->finalize();
    }
}
void Busy::keyPressEvent(QKeyEvent *evt)
{
    if(evt->key() == Qt::Key_Escape)
            return;
    QDialog::keyPressEvent(evt);
}
void Busy::finalize(){
    this->total = (occupation + people + money)/3;
    qDebug() << "professional rating: " << total;
    this->close();
}
