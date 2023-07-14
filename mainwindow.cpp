#include "mainwindow.h"
#include "ui_mainwindow.h"

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
}
void MainWindow::on_RBPersonalSometimes_clicked()
{
    if (!ui->GBProfessionalLife->isEnabled())
        ui->GBProfessionalLife->setEnabled(true);
    if (!ui->CBEnoughMoney->isEnabled())
        ui->CBEnoughMoney->setEnabled(true);
}
void MainWindow::on_RBPersonalhate_clicked()
{
    if (!ui->GBProfessionalLife->isEnabled())
        ui->GBProfessionalLife->setEnabled(true);
    if (!ui->CBEnoughMoney->isEnabled())
        ui->CBEnoughMoney->setEnabled(true);
}

void MainWindow::on_RBProfessionalBusy_clicked()
{
    if (!ui->GBHobby->isEnabled())
        ui->GBHobby->setEnabled(true);

    ProfessionalLife *p = new ProfessionalLife();
    //p->show();
    p->exec();
}
void MainWindow::on_RBProfessionalNotBusy_clicked()
{
    if (!ui->GBHobby->isEnabled())
        ui->GBHobby->setEnabled(true);
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

