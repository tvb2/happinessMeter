#ifndef HOBBY_H
#define HOBBY_H
#include "segment.h"
#include <QDebug>
#include <QObject>
#include <map>

class Hobby: public Segment
{
    Q_OBJECT
public:
    explicit Hobby(Segment *parent = nullptr);
    virtual QString evaluate() override;
private:
    std::map<QString, QString> result;
};

#endif // HOBBY_H
