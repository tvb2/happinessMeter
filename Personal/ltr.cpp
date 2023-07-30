#include "ltr.h"
#include "ui_ltr.h"

LTR::LTR(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::LTR)
{
    ui->setupUi(this);
    //initially widgets are not visible

    //First widgets
    ui->GBFriends->setEnabled(false);
    //show Second group when either RB is selected
    QObject::connect(ui->RBFamilyExc,  &QRadioButton::clicked, this,  &LTR::frstSet);
    QObject::connect(ui->RBFamilyNorm, &QRadioButton::clicked, this,  &LTR::frstSet);
    QObject::connect(ui->RBFamilyBad,  &QRadioButton::clicked, this,  &LTR::frstSet);

    //Second widgets
    ui->GBPartner->setEnabled(false);
    QObject::connect(ui->RBFriendsExc,  &QRadioButton::clicked, this, &LTR::scndSet);
    QObject::connect(ui->RBFriendsNorm, &QRadioButton::clicked, this, &LTR::scndSet);
    QObject::connect(ui->RBFriendsBad,  &QRadioButton::clicked, this, &LTR::scndSet);

    //buttons
    ui->PBOK->setEnabled(false);
    QObject::connect(ui->RBPartnerExc,  &QRadioButton::clicked, this, &LTR::thrdSet);
    QObject::connect(ui->RBPartnerNorm, &QRadioButton::clicked, this, &LTR::thrdSet);
    QObject::connect(ui->RBPartnerBad,  &QRadioButton::clicked, this, &LTR::thrdSet);
    QObject::connect(ui->PBOK,          &QPushButton::clicked,  this, &LTR::finalize);
}

LTR::~LTR()
{
    delete ui;
}

void LTR::frstSet(){
    //make available the next section
    if (!ui->GBFriends->isEnabled())
        ui->GBFriends->setEnabled(true);

    //set rating based on selection
    if (ui->RBFamilyExc->isChecked())
        this->first = 1;
    if (ui->RBFamilyNorm->isChecked())
        this->first = 0.5;
    if (ui->RBFamilyBad->isChecked())
        this->first= 0;
}
void LTR::scndSet(){
    //make available the next section
    if (!ui->GBPartner->isEnabled())
        ui->GBPartner->setEnabled(true);

    //set rating based on selection
    if (ui->RBFriendsExc->isChecked())
        this->second = 1;
    if (ui->RBFriendsNorm->isChecked())
        this->second = 0.5;
    if (ui->RBFriendsBad->isChecked())
        this->second= 0;
}
void LTR::thrdSet(){
//make available the next section
    if (!ui->PBOK->isEnabled())
        ui->PBOK->setEnabled(true);

//set rating based on selection
    if (ui->RBPartnerExc->isChecked())
        this->third = 1;
    if (ui->RBPartnerNorm->isChecked())
        this->third = 0.5;
    if (ui->RBPartnerBad->isChecked())
        this->third= 0;
//flag to report that all options have been set
    this->complete = true;
}
void LTR::closeEvent (QCloseEvent *event){
    if (!this->complete){
        QMessageBox::StandardButton resBtn = QMessageBox::question(this, tr("Personal Life"),
                                                                   tr("Please select at least one option in each group\n"),
                                                                   QMessageBox::Ok | QMessageBox::NoButton, QMessageBox::Ok);
        event->ignore();
    }
    else{
        this->finalize();
    }
}
void LTR::keyPressEvent(QKeyEvent *evt){
    if(evt->key() == Qt::Key_Escape)
        return;
    QDialog::keyPressEvent(evt);
}
void LTR::finalize(){
    emit sendFirst(this->first);
    emit sendSecond(this->second);
    emit sendThird(this->third);
    this->accept();
}
