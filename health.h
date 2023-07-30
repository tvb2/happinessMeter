#ifndef HEALTH_H
#define HEALTH_H

#include "segment.h"
#include <QObject>
#include <QDebug>
#include <map>

class Health : public Segment
{
    Q_OBJECT
public:
    explicit Health(Segment *parent = nullptr);
    virtual QString evaluate() override;
private:
    std::map<QString, QString> result;
};

#endif // HEALTH_H
