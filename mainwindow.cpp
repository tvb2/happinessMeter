#include "mainwindow.h"
#include "ui_mainwindow.h"
#include "ui_notbusy.h"
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
    professional = new Professional();
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

    LTR *ltr = new LTR();
    ltr->exec();

}
void MainWindow::on_RBPersonalSometimes_clicked()
{
    if (!ui->GBProfessionalLife->isEnabled())
        ui->GBProfessionalLife->setEnabled(true);
    if (!ui->CBEnoughMoney->isEnabled())
        ui->CBEnoughMoney->setEnabled(true);

    STR *str = new STR();
    str->exec();
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
    QObject::connect(b, &Busy::emitSignal, professional, &Professional::setRate);
    b->exec();
}
void MainWindow::on_RBProfessionalNotBusy_clicked()
{
    if (!ui->GBHobby->isEnabled())
        ui->GBHobby->setEnabled(true);

    NotBusy *ntbusy = new NotBusy();
    ntbusy->exec();
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
   QMessageBox *message;
    if (ui->RBOverallHappy->isChecked()){
        message->information(this,"Your happiness meter...", "You appear to be rather happy! Congrats!");
    }
    else if (ui->RBOverallNotHappy->isChecked()){
        message->information(this,"Your happiness meter...", "You appear to be not so happy. Sorry!");
    }
}

