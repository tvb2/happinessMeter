#ifndef HOBBYCRAP_H
#define HOBBYCRAP_H

#include <QDialog>

namespace Ui {
class HobbyCrap;
}

class HobbyCrap : public QDialog
{
    Q_OBJECT

public:
    explicit HobbyCrap(QWidget *parent = nullptr);
    ~HobbyCrap();

private:
    Ui::HobbyCrap *ui;
};

#endif // HOBBYCRAP_H
