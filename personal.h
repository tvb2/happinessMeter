#ifndef PERSONAL_H
#define PERSONAL_H
#include "segment.h"
#include <QDebug>
#include <QObject>


class Personal : public Segment
{
    Q_OBJECT
public:
    explicit Personal(Segment *parent = nullptr);
public slots:
    virtual std::string evaluate() override;

private:
    double rate{0}, first{0}, second{0}, third{0};
    double epsilon = 0.01;

};

#endif // PERSONAL_H
