#ifndef BUSY_H
#define BUSY_H

#include <QDialog>
#include <QCloseEvent>
#include <QKeyEvent>
#include <QMessageBox>
#include <QDebug>

namespace Ui {
class Busy;
}

class Busy : public QDialog
{
    Q_OBJECT

public:
    explicit Busy(QWidget *parent = nullptr);
    ~Busy();
    double getRate(){return this->total;}
signals:

private slots:

    //option selected in Occupation group
    void occupationSet();

    //option selected in People group
    void peopleSet();

    //option selected in Money group
    void moneySet();

    //handle close event (cross)
    void closeEvent (QCloseEvent *event);

    //handle close events (escape)
    void keyPressEvent(QKeyEvent *evt);

    //handle OK button pressed
    void finalize();

private:
    Ui::Busy *ui;
    bool complete{0};
    double occupation{0}, people{0}, money{0}, total{0};
};

#endif // BUSY_H
