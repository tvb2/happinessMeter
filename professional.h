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
    virtual std::string evaluate() override;
    void enoughCash(int flag);

private:
    bool enoughMoney{0};

};

#endif // PROFESSIONAL_H
