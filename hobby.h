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
private:
    double rate{0}, first{0}, second{0}, third{0};
    double epsilon = 0.01;
};

#endif // HOBBY_H
