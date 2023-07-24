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
    std::string name = "Hobby";
    std::string firstGroup = "First  Group Name";
    std::string scndGroup =  "Second Group Name";
    std::string thrdGroup =  "Third  Group Name";

private:
    Ui::HobbyYes *ui;
};

#endif // HOBBYYES_H
