#ifndef STR_H
#define STR_H

#include <QDialog>

namespace Ui {
class STR;
}

class STR : public QDialog
{
    Q_OBJECT

public:
    explicit STR(QWidget *parent = nullptr);
    ~STR();

private:
    Ui::STR *ui;
};

#endif // STR_H
