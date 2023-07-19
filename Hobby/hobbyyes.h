#ifndef HOBBYYES_H
#define HOBBYYES_H

#include <QDialog>

namespace Ui {
class HobbyYes;
}

class HobbyYes : public QDialog
{
    Q_OBJECT

public:
    explicit HobbyYes(QWidget *parent = nullptr);
    ~HobbyYes();

private:
    Ui::HobbyYes *ui;
};

#endif // HOBBYYES_H
