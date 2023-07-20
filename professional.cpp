#include "professional.h"

Professional::Professional(Segment *parent): Segment(parent)
{

}

void Professional::setRate(double _val){
    this->rate = _val;
    qDebug() << "value of Professional class: " << this->rate;
}
