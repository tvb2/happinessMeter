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

};

#endif // HEALTH_H
