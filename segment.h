#ifndef SEGMENT_H
#define SEGMENT_H

#include <QObject>
#include <string>

class Segment: public QObject
{
    Q_OBJECT
public:
    explicit Segment(QObject *parent = nullptr);
public slots:
    virtual void setRate() = 0;
    virtual std::string evaluate() = 0;
};

#endif // SEGMENT_H
