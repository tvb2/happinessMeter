#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include <QMessageBox>
#include <QCheckBox>
#include <string>

#include "Professional/busy.h"

#include "Personal/ltr.h"
#include "Personal/str.h"
#include "Personal/ztr.h"

#include "professional.h"
#include "personal.h"

QT_BEGIN_NAMESPACE
namespace Ui { class MainWindow; }
QT_END_NAMESPACE

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    MainWindow(QWidget *parent = nullptr);
    ~MainWindow();

private slots:

    void on_RBOverallHappy_clicked();
    void on_RBOverallNotHappy_clicked();

    void on_RBPersonalLTR_clicked();
    void on_RBPersonalSometimes_clicked();
    void on_RBPersonalhate_clicked();

    void on_RBProfessionalBusy_clicked();
    void on_RBProfessionalNotBusy_clicked();

    void on_RBHaveHobby_clicked();
    void on_RBNoHobby_clicked();
    void on_RBHobbyIsWork_clicked();
    void on_RBHobbyIsShit_clicked();

    void on_PBTell_clicked();

    void on_CBEnoughMoney_stateChanged(int arg1);

private:
    Ui::MainWindow *ui;
    Professional *professional;
    Personal *personal;
};
#endif // MAINWINDOW_H
