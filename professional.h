#ifndef PROFESSIONAL_H
#define PROFESSIONAL_H
#include "segment.h"


class Professional : public Segment
{
    Q_OBJECT
public:
    Professional();
public slots:
    virtual void rateMax() override;

};

#endif // PROFESSIONAL_H
