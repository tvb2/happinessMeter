#ifndef STR_H
#define STR_H

#include <QDialog>
#include <QMessageBox>
#include <QCloseEvent>

namespace Ui {
class STR;
}

class STR : public QDialog
{
    Q_OBJECT

public:
    explicit STR(QWidget *parent = nullptr);
    ~STR();
    QString name =      tr("Relations ");
    QString firstGroup =tr( "Family");
    QString scndGroup = tr( "Friends");
    QString thrdGroup = tr("None");

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
    Ui::STR *ui;
    bool complete{0};
    double first{0}, second{0}, third{0};
};

#endif // STR_H
