#include "segment.h"

Segment::Segment(QObject *parent) : QObject(parent)
{

}
void Segment::init(std::string _name,
                  std::string _frst,
                  std::string _scnd,
                   std::string _thrd){
    this->name = _name;
    this->frst = _frst;
    this->scnd = _scnd;
    this->thrd = _thrd;
}
void Segment::setRate(){
    this->rate = (this->first + this->second + this->third)/3;
    qDebug() << "total of " << this->name << ": " << this->rate;
}
void Segment::setFirst(double _val){
    this->first = _val;
    qDebug() << this->name << " " << this->frst << ": " << this->first;
}
void Segment::setSecond(double _val){
    this->second = _val;
    qDebug() << this->name << " " << this->scnd << ": " << this->second;
}
void Segment::setThird(double _val){
    this->third = _val;
    qDebug() << this->name << " " << this->thrd << ": " << this->third;
}
