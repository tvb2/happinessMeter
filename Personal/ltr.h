#ifndef LTR_H
#define LTR_H

#include <QDialog>
#include <QMessageBox>
#include <QCloseEvent>

namespace Ui {
class LTR;
}

class LTR : public QDialog
{
    Q_OBJECT

public:
    explicit LTR(QWidget *parent = nullptr);
    ~LTR();
    std::string name = "Relations ";
    std::string firstGroup = "Family";
    std::string scndGroup =  "Friends";
    std::string thrdGroup = "Partner";
signals:
    void sendFirst(double fst);
    void sendSecond(double scnd);
    void sendThird(double thrd);

private slots:

    //option selected in the first group
    void frstSet();

    //option selected in the second group
    void scndSet();

    //option selected in the third group
    void thrdSet();

    //handle close event (cross)
    void closeEvent (QCloseEvent *event);

    //handle close events (escape)
    void keyPressEvent(QKeyEvent *evt);

    //handle OK button pressed
    void finalize();

private:
    Ui::LTR *ui;
    bool complete{0};
    double first{0}, second{0}, third{0};
};

#endif // LTR_H
