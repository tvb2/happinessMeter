#include "disclaimer.h"
#include "ui_disclaimer.h"

Disclaimer::Disclaimer(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::Disclaimer)
{
    ui->setupUi(this);
    ui->PTEdisclaimer->setPlainText(tr("This application is for fun only. If you decide to make decisions based on its output, you agree to do it completely at your own risk!"));
}

Disclaimer::~Disclaimer()
{
    delete ui;
}

void Disclaimer::closeEvent (QCloseEvent *event)
{
    QMessageBox::StandardButton resBtn = QMessageBox::question(this, tr("Disclaimer"),
                                                                   tr("You need to agree to the disclaimer by pressing the button\n"),
                                                                   QMessageBox::Ok | QMessageBox::NoButton, QMessageBox::NoButton);
    event->ignore();
}
void Disclaimer::keyPressEvent(QKeyEvent *evt)
{
    if(evt->key() == Qt::Key_Escape)
        return;
    QDialog::keyPressEvent(evt);
}

void Disclaimer::on_PBGotIt_clicked()
{
    this->accept();
}

