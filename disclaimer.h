#ifndef DISCLAIMER_H
#define DISCLAIMER_H

#include <QDialog>
#include <QMessageBox>

namespace Ui {
class Disclaimer;
}

class Disclaimer : public QDialog
{
    Q_OBJECT

public:
    explicit Disclaimer(QWidget *parent = nullptr);
    ~Disclaimer();
private slots:

    //handle close event (cross)
    void closeEvent (QCloseEvent *event);
    //handle close events (escape)
    void keyPressEvent(QKeyEvent *evt);

    void on_PBGotIt_clicked();

private:
    Ui::Disclaimer *ui;
};

#endif // DISCLAIMER_H
