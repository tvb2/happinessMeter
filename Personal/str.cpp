#include "str.h"
#include "ui_str.h"

STR::STR(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::STR)
{
    ui->setupUi(this);
    //initially widgets are not visible

    //First widgets
    //show Second group when either RB is selected

    //Second widgets
    ui->GBFriends->setEnabled(false);
    QObject::connect(ui->RBFamilyExc, &QRadioButton::clicked, this,  &STR::frstSet);
    QObject::connect(ui->RBFamilyNorm, &QRadioButton::clicked, this, &STR::frstSet);
    QObject::connect(ui->RBFamilyBad, &QRadioButton::clicked, this,  &STR::frstSet);

    //buttons
    ui->PBOK->setEnabled(false);
    QObject::connect(ui->RBFriendsExc, &QRadioButton::clicked, this,  &STR::scndSet);
    QObject::connect(ui->RBFriendsNorm, &QRadioButton::clicked, this, &STR::scndSet);
    QObject::connect(ui->RBFriendsBad, &QRadioButton::clicked, this,  &STR::scndSet);
    QObject::connect(ui->PBOK, &QPushButton::clicked, this, &STR::finalize);
}

STR::~STR()
{
    delete ui;
}

void STR::frstSet(){
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
void STR::scndSet(){
    //make available the next section
    if (!ui->PBOK->isEnabled())
        ui->PBOK->setEnabled(true);

    //set rating based on selection
    if (ui->RBFriendsExc->isChecked())
        this->second = 1;
    if (ui->RBFriendsNorm->isChecked())
        this->second = 0.5;
    if (ui->RBFriendsBad->isChecked())
        this->second= 0;
    //flag to report that all options have been set
    this->complete = true;
}
void STR::thrdSet(){}
void STR::closeEvent (QCloseEvent *event){
    if (!this->complete){
        QMessageBox::StandardButton resBtn = QMessageBox::question(this, tr("Personal Life"),
                                                                   tr("Please select one option in each group\n"),
                                                                   QMessageBox::Ok | QMessageBox::NoButton, QMessageBox::Ok);
        event->ignore();
    }
    else{
        this->finalize();
    }
}
void STR::keyPressEvent(QKeyEvent *evt){
    if(evt->key() == Qt::Key_Escape)
        return;
    QDialog::keyPressEvent(evt);
}
void STR::finalize(){
    emit sendFirst(this->first);
    emit sendSecond(this->second);
    emit sendThird(this->third);
    this->accept();
}
