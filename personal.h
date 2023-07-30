#ifndef PERSONAL_H
#define PERSONAL_H
#include "segment.h"
#include <QDebug>
#include <QObject>
#include <map>

class Personal : public Segment
{
    Q_OBJECT
public:
    explicit Personal(Segment *parent = nullptr);
public slots:
    virtual QString evaluate() override;
private:
    std::map<QString, QString> result;
};

#endif // PERSONAL_H
