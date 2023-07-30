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
    QString name        = tr("Health");
    QString firstGroup  = tr("Health first");
    QString scndGroup   = tr("Health second");
    QString thrdGroup   = tr("Health third");
private:
    Ui::HealthExc *ui;
};

#endif // HEALTHEXC_H
