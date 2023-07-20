#ifndef PROFESSIONAL_H
#define PROFESSIONAL_H
#include "segment.h"
#include <QDebug>
#include <QObject>


class Professional : public Segment
{
    Q_OBJECT
public:
    explicit Professional(Segment *parent = nullptr);
public slots:
    virtual void setRate() override;
    virtual std::string evaluate() override;
    void setOccupation(double _val);
    void setPeople(double _val);
    void setMoney(double _val);
    void enoughCash(int flag);
    double getRate(){return this->rate;}

private:
    double rate{0}, occupation{0}, people{0}, money{0};
    bool enoughMoney{0};
    double epsilon = 0.01;

};

#endif // PROFESSIONAL_H
