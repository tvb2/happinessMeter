#include "mainwindow.h"
#include "ui_mainwindow.h"
#include "ui_notbusy.h"
#include "ui_busy.h"
#include "ui_ltr.h"
#include "ui_str.h"
#include "ui_ztr.h"

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);

//initially widgets are not visible

//Overall

//personal life widgets
    ui->GBPersonalLife->setEnabled(false);

//professional life widgets
    ui->GBProfessionalLife->setEnabled(false);
    ui->CBEnoughMoney->setEnabled(false);

//hobby widgets
    ui->GBHobby->setEnabled(false);

//'Tell me' button
    ui->PBTell->setEnabled(false);
    std::string temp = "temp";
    professional = new Professional();
    personal = new Personal();
}

MainWindow::~MainWindow()
{
    delete ui;
}
void MainWindow::on_RBOverallHappy_clicked()
{
    if (!ui->GBPersonalLife->isEnabled())
        ui->GBPersonalLife->setEnabled(true);

}
void MainWindow::on_RBOverallNotHappy_clicked()
{
    if (!ui->GBPersonalLife->isEnabled())
        ui->GBPersonalLife->setEnabled(true);

}

void MainWindow::on_RBPersonalLTR_clicked()
{
    if (!ui->GBProfessionalLife->isEnabled())
        ui->GBProfessionalLife->setEnabled(true);
    if (!ui->CBEnoughMoney->isEnabled())
        ui->CBEnoughMoney->setEnabled(true);

    LTR *relations = new LTR();
    //recieve values from LTR dialog into Personal class
    personal->init(relations->name, relations->firstGroup, relations->scndGroup, relations->thrdGroup);
    QObject::connect(relations, &LTR::sendFirst, personal, &Personal::setFirst);
    QObject::connect(relations, &LTR::sendSecond, personal, &Personal::setSecond);
    QObject::connect(relations, &LTR::sendThird, personal, &Personal::setThird);
    relations->exec();

}
void MainWindow::on_RBPersonalSometimes_clicked()
{
    if (!ui->GBProfessionalLife->isEnabled())
        ui->GBProfessionalLife->setEnabled(true);
    if (!ui->CBEnoughMoney->isEnabled())
        ui->CBEnoughMoney->setEnabled(true);

    STR *relations = new STR();
    //recieve values from LTR dialog into Personal class
    personal->init(relations->name, relations->firstGroup, relations->scndGroup, relations->thrdGroup);
    QObject::connect(relations, &STR::sendFirst, personal, &Personal::setFirst);
    QObject::connect(relations, &STR::sendSecond, personal, &Personal::setSecond);
    QObject::connect(relations, &STR::sendThird, personal, &Personal::setThird);
    relations->exec();
}
void MainWindow::on_RBPersonalhate_clicked()
{
    if (!ui->GBProfessionalLife->isEnabled())
        ui->GBProfessionalLife->setEnabled(true);
    if (!ui->CBEnoughMoney->isEnabled())
        ui->CBEnoughMoney->setEnabled(true);

    ZTR *ztr = new ZTR();
    ztr->exec();
}

void MainWindow::on_RBProfessionalBusy_clicked()
{
    if (!ui->GBHobby->isEnabled())
        ui->GBHobby->setEnabled(true);

    Busy *b = new Busy();
//recieve values from Busy dialog into Professional class
    professional->init(b->name, b->firstGroup, b->scndGroup, b->thrdGroup);
    QObject::connect(b, &Busy::sendOccupation, professional, &Professional::setFirst);
    QObject::connect(b, &Busy::sendPeople, professional, &Professional::setSecond);
    QObject::connect(b, &Busy::sendMoney, professional, &Professional::setThird);
    b->exec();
}
void MainWindow::on_RBProfessionalNotBusy_clicked()
{
    if (!ui->GBHobby->isEnabled())
        ui->GBHobby->setEnabled(true);
    
    professional->setFirst(0.5);
    professional->setSecond(0.5);
    professional->setThird(0.5);
}

void MainWindow::on_RBHaveHobby_clicked(){
    if (!ui->PBTell->isEnabled())
        ui->PBTell->setEnabled(true);
}
void MainWindow::on_RBNoHobby_clicked()
{
    if (!ui->PBTell->isEnabled())
        ui->PBTell->setEnabled(true);
}
void MainWindow::on_RBHobbyIsWork_clicked()
{
    if (!ui->PBTell->isEnabled())
        ui->PBTell->setEnabled(true);
}
void MainWindow::on_RBHobbyIsShit_clicked()
{
    if (!ui->PBTell->isEnabled())
        ui->PBTell->setEnabled(true);
}

void MainWindow::on_PBTell_clicked()
{
    professional->setRate();
    personal->setRate();
   std::string persSTR, profSTR, hobbSTR, overallSTR;
   QMessageBox *message = nullptr;

   profSTR = professional->evaluate();
   persSTR = personal->evaluate();

    if (ui->RBOverallHappy->isChecked()){
        overallSTR = "You appear to be rather happy! Congrats!\n";
    }
    else if (ui->RBOverallNotHappy->isChecked()){
        overallSTR = "You appear to be not so happy. Sorry!\n";
    }
    message->information(this,"Your happiness meter...", QString::fromStdString(overallSTR + profSTR + persSTR));
}


void MainWindow::on_CBEnoughMoney_stateChanged(int arg1)
{
    professional->enoughCash(arg1);
}

