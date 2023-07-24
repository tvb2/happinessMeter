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

};

#endif // PERSONAL_H
