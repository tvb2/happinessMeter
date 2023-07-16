#ifndef ZTR_H
#define ZTR_H

#include <QDialog>

namespace Ui {
class ZTR;
}

class ZTR : public QDialog
{
    Q_OBJECT

public:
    explicit ZTR(QWidget *parent = nullptr);
    ~ZTR();

private:
    Ui::ZTR *ui;
};

#endif // ZTR_H
