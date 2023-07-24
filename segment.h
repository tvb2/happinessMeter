#ifndef SEGMENT_H
#define SEGMENT_H

#include <QObject>
#include <string>
#include <QDebug>

class Segment: public QObject
{
    Q_OBJECT
public:
    explicit Segment(QObject *parent = nullptr);
public slots:
    virtual void setRate();
    virtual std::string evaluate() = 0;
    virtual void init(std::string _name = "Concrete class ",
                      std::string _frst = "first group name",
                      std::string _scnd = "second group name ",
                      std::string _thrd = "third group name");
    virtual void setFirst(double _val);
    virtual void setSecond(double _val);
    virtual void setThird(double _val);
protected:
    double rate{0}, first{0}, second{0}, third{0};
    double epsilon = 0.01;
    std::string name = "Concrete class ";
    std::string frst = "first group name";
    std::string scnd = "second group name ";
    std::string thrd = "third group name";
};

#endif // SEGMENT_H
