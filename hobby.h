#ifndef HOBBY_H
#define HOBBY_H
#include "segment.h"
#include <QDebug>
#include <QObject>

class Hobby: public Segment
{
    Q_OBJECT
public:
    explicit Hobby(Segment *parent = nullptr);
    virtual std::string evaluate() override;

};

#endif // HOBBY_H
