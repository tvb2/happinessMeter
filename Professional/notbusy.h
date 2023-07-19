#ifndef NOTBUSY_H
#define NOTBUSY_H

#include <QDialog>

namespace Ui {
class NotBusy;
}

class NotBusy : public QDialog
{
    Q_OBJECT

public:
    explicit NotBusy(QWidget *parent = nullptr);
    ~NotBusy();

private:
    Ui::NotBusy *ui;
};

#endif // NOTBUSY_H
