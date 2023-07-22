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
    virtual std::string evaluate() override;
    void enoughCash(int flag);

private:
    double rate{0}, first{0}, second{0}, third{0};
    bool enoughMoney{0};
    double epsilon = 0.01;

};

#endif // PROFESSIONAL_H
