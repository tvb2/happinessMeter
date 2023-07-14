#ifndef PROFESSIONALLIFE_H
#define PROFESSIONALLIFE_H

#include <QDialog>
#include <QCloseEvent>
#include <QMessageBox>

namespace Ui {
class ProfessionalLife;
}

class ProfessionalLife : public QDialog
{
    Q_OBJECT

public:
    explicit ProfessionalLife(QWidget *parent = nullptr);
    ~ProfessionalLife();

private slots:
    void on_RBOccupationFun_clicked();

    void on_RBRBOccupationNorm_clicked();

    void on_RBOccupationDull_clicked();

    void on_RBPeopleGreat_clicked();

    void on_RBPeopleNorm_clicked();

    void on_RBPeopleUgly_clicked();

    void on_radioButton_3_clicked();

    void on_radioButton_4_clicked();

    void on_radioButton_5_clicked();

    void on_PBOK_clicked();

    void closeEvent (QCloseEvent *event);

private:
    Ui::ProfessionalLife *ui;
};

#endif // PROFESSIONALLIFE_H
