#ifndef HEALTH_H
#define HEALTH_H

#include "segment.h"
#include <QObject>
#include <QDebug>

class Health : public Segment
{
    Q_OBJECT
public:
    explicit Health(Segment *parent = nullptr);
    virtual std::string evaluate() override;
private:
    double rate{0}, first{0}, second{0}, third{0};
    double epsilon = 0.01;
};

#endif // HEALTH_H
