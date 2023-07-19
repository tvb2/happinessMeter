#ifndef BUSY_H
#define BUSY_H

#include <QDialog>
#include <QCloseEvent>
#include <QKeyEvent>
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

public:

signals:

    private slots:
    void visPeople();
    void visMoney();
    void visPBOK();
    void closeEvent (QCloseEvent *event);
    void keyPressEvent(QKeyEvent *evt);
    void finalize();
private:
    Ui::Busy *ui;
    bool complete{0};
};

#endif // BUSY_H
