#include "professional.h"

Professional::Professional(Segment *parent): Segment(parent)
{

}

void Professional::setRate(){
    this->rate = (this->occupation + this->people + this->money)/3;
    qDebug() << "total of Professional class: " << this->rate;
}

void Professional::setOccupation(double _val){
    this->occupation = _val;
    qDebug() << "professional class occupation: " << this->occupation;
}
void Professional::setPeople(double _val){
    this->people = _val;
    qDebug() << "professional class people: " << this->people;
}
void Professional::setMoney(double _val){
    this->money = _val;
    qDebug() << "professional class money: " << this->money;
}
