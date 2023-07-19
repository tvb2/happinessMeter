#ifndef BUSY_H
#define BUSY_H

#include <QDialog>
#include <QCloseEvent>
#include <QMessageBox>

namespace Ui {
class Busy;
}

class Busy : public QDialog
{
    Q_OBJECT

public:
    explicit Busy(QWidget *parent = nullptr);
    ~Busy();

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
    Ui::Busy *ui;
};

#endif // BUSY_H
