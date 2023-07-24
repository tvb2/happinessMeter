#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include <QMessageBox>
#include <QCheckBox>
#include <string>


#include "Personal/ltr.h"
#include "Personal/str.h"

#include "Professional/busy.h"

#include "Hobby/hobbyyes.h"

#include "Health/healthexc.h"

#include "disclaimer.h"

#include "professional.h"
#include "personal.h"
#include "hobby.h"
#include "health.h"

QT_BEGIN_NAMESPACE
namespace Ui { class MainWindow; }
QT_END_NAMESPACE

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    MainWindow(QWidget *parent = nullptr);
    ~MainWindow();
    std::string overallRate();

private slots:

    void on_RBOverallHappy_clicked();
    void on_RBOverallNotHappy_clicked();

    void on_RBPersonalLTR_clicked();
    void on_RBPersonalSometimes_clicked();

    void on_RBProfessionalBusy_clicked();
    void on_RBProfessionalNotBusy_clicked();

    void on_RBHobbyExc_clicked();
    void on_RBHobbyNorm_clicked();
    void on_RBHobbyBad_clicked();

    void on_PBTell_clicked();

    void on_CBEnoughMoney_stateChanged(int arg1);

    void on_RBHealthExc_clicked();

    void on_RBHealthNorm_clicked();

    void on_RBHealthBad_clicked();

private:
    Ui::MainWindow *ui;
    double overall{0};
    int numOfSegments = 4;
    Professional *professional;
    Personal *personal;
    Hobby *hobby;
    Health *health;
};
#endif // MAINWINDOW_H
