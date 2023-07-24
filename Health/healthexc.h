#ifndef HEALTHEXC_H
#define HEALTHEXC_H

#include <QDialog>

namespace Ui {
class HealthExc;
}

class HealthExc : public QDialog
{
    Q_OBJECT

public:
    explicit HealthExc(QWidget *parent = nullptr);
    ~HealthExc();
    std::string name = "Health";
    std::string firstGroup = "Health first";
    std::string scndGroup =  "Health second";
    std::string thrdGroup = "Health third";
private:
    Ui::HealthExc *ui;
};

#endif // HEALTHEXC_H
