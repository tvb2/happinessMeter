#ifndef HOBBYWORK_H
#define HOBBYWORK_H

#include <QDialog>

namespace Ui {
class HobbyWork;
}

class HobbyWork : public QDialog
{
    Q_OBJECT

public:
    explicit HobbyWork(QWidget *parent = nullptr);
    ~HobbyWork();

private:
    Ui::HobbyWork *ui;
};

#endif // HOBBYWORK_H
