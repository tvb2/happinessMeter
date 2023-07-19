#ifndef HOBBYNO_H
#define HOBBYNO_H

#include <QDialog>

namespace Ui {
class HobbyNo;
}

class HobbyNo : public QDialog
{
    Q_OBJECT

public:
    explicit HobbyNo(QWidget *parent = nullptr);
    ~HobbyNo();

private:
    Ui::HobbyNo *ui;
};

#endif // HOBBYNO_H
