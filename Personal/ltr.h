#ifndef LTR_H
#define LTR_H

#include <QDialog>

namespace Ui {
class LTR;
}

class LTR : public QDialog
{
    Q_OBJECT

public:
    explicit LTR(QWidget *parent = nullptr);
    ~LTR();

private:
    Ui::LTR *ui;
};

#endif // LTR_H
