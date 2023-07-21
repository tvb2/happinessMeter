#include "personal.h"

Personal::Personal(Segment *parent): Segment(parent)
{

}

void Personal::setRate(){
    this->rate = (this->first + this->second+ this->third)/3;
    qDebug() << "total of Professional class: " << this->rate;
}

std::string Personal::evaluate(){
    std::string resume = "Professiona life: ";
//overall
    if (this->rate >=0 && this->rate < 0.5){
        resume.append("Overall is bad. ");
    //0 .. 0.16 (0 - 0 - 0)
        if (this->rate < 0.16){
            resume.append("You should consider completely changing your occupation,");
        }
    //0.16 .. 0.33 (0 - 0.5 - 0)
        if (this->rate >= 0.16 && this->rate < 0.33){
            resume.append("You should consider completely changing your occupation,");
            }
        }
    //0.33 .. 0.5 (0 - 0.5 - 0.5 OR 1 - 0 - 0)
        if (this->rate >= 0.33 && this->rate < 0.5){
            resume.append("You should consider completely changing your occupation,");
        }
    if (this->rate >=0.5 && this->rate < 0.83){
        resume.append("Overall is good. ");
    //0.5 .. 0.66 (0.5 – 0.5 – 0.5 OR 1 – 0.5 – 0)
/*        if (this->rate < 0.6){
            if (this->first == 0 || this->second == 0 || this->third == 0){
                if (this->occupation == 0)
                    resume.append(" But boring work will not make you happy. Can you change your attitude or slightly vary the tasks you do? Otherwise change your job\n");
                if (this->people == 0)
                    resume.append(" But where is the problem? In people around or in yourself? If you can't change either, you better change your job..\n");
                if (this->money == 0){
                    resume.append(" But money matters in this life, for sure. It is important to receive fair compensation for your work");
                    if (this->enoughMoney)
                        resume.append(" also because money may not be with you forever too...\n");
                    else
                        resume.append(".\n");
                }
                else
                    if (!this->enoughMoney)
                    resume.append(" and also you need to learn to spend less, save more\n");
            }
            else
                if (!this->enoughMoney)
                    resume.append(" and also you need to learn to spend less, save more\n");
        }
  //0.66 .. 0.83 (0.5 – 0.5 – 1 OR 1 – 1 – 0)
        if (this->rate >= 0.6 && this->rate < 0.83){
            if (this->occupation == 0 || this->people == 0 || this->money == 0){
                if (this->occupation == 0)
                    resume.append(" But boring work will not make you happy. Can you change your attitude or slightly vary the tasks you do? Otherwise change your job\n");
                if (this->people == 0)
                    resume.append(" But where is the problem? In people around or in yourself? If you can't change either, you better change your job..\n");
                if (this->money == 0){
                    resume.append(" But money matters in this life, for sure. It is important to receive fair compensation for your work");
                    if (this->enoughMoney)
                        resume.append(" also because money may not be with you forever too...\n");
                    else
                        resume.append(".\n");
                }
            }
            else{
                if (!this->enoughMoney)
                    resume.append(" but also you need to learn to spend less, save more\n");
            }
        }
*/
    }
    if (this->rate >= 0.83){
        resume.append("Overall is excellent! ");
    }
    return resume;
}

void Personal::setFirst(double _val){
    this->first = _val;
    qDebug() << "personal class partner: " << this->first;
}
void Personal::setSecond(double _val){
    this->second = _val;
    qDebug() << "personal class family: " << this->second;
}
void Personal::setThird(double _val){
    this->third = _val;
    qDebug() << "personal class friends: " << this->third;
}

