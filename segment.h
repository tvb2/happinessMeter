#ifndef SEGMENT_H
#define SEGMENT_H

#include <QObject>

class Segment: public QObject
{
    Q_OBJECT
public:
    explicit Segment(QObject *parent = nullptr);
public slots:
    virtual void setRate(double _val) = 0;
};

#endif // SEGMENT_H
