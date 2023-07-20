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
    virtual void setRate(double _val) override;
    double getRate(){return this->rate;}

private:
    double rate{0};

};

#endif // PROFESSIONAL_H
