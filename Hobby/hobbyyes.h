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
    QString name =       tr("Hobby");
    QString firstGroup = tr("First  Group Name");
    QString scndGroup =  tr("Second Group Name");
    QString thrdGroup =  tr("Third  Group Name");

private:
    Ui::HobbyYes *ui;
};

#endif // HOBBYYES_H
