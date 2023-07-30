#ifndef SEGMENT_H
#define SEGMENT_H

#include <QObject>
#include <QString>
#include <string>
#include <QDebug>

class Segment: public QObject
{
    Q_OBJECT
public:
    explicit Segment(QObject *parent = nullptr);
public slots:
    virtual void setRate();
    virtual QString evaluate() = 0;
    virtual void init(QString _name = "Concrete class ",
                      QString _frst = "first group name",
                      QString _scnd = "second group name ",
                      QString _thrd = "third group name");
    virtual void setFirst(double _val);
    virtual void setSecond(double _val);
    virtual void setThird(double _val);
    virtual double getRate();
protected:
    double rate{0}, first{0}, second{0}, third{0};
    double epsilon = 0.01;
    QString name = "Concrete class ";
    QString frst = "first group name";
    QString scnd = "second group name ";
    QString thrd = "third group name";
};

#endif // SEGMENT_H
