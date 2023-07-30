#ifndef PROFESSIONAL_H
#define PROFESSIONAL_H
#include "segment.h"
#include <QDebug>
#include <QObject>
#include <QTest>
#include <map>

class Professional : public Segment
{
    Q_OBJECT
public:
    explicit Professional(Segment *parent = nullptr);
public slots:
    virtual QString evaluate() override;
    void enoughCash(int flag);

private:
    bool enoughMoney{0};
    std::map<QString, QString> result;
private slots:
    void testEval(double f, double s, double th, QString result);
};

#endif // PROFESSIONAL_H
