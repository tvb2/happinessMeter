#include "professional.h"

Professional::Professional(Segment *parent): Segment(parent)
{

}

std::string Professional::evaluate(){
    std::string resume = "Professiona life: ";
//overall
    if (this->rate >=0 && this->rate < 0.5){
        resume.append("Overall is bad. ");
    //0 .. 0.16 (0 - 0 - 0)
        if (this->rate < 0.16){
            resume.append("You should consider completely changing your occupation,");
            if (this->enoughMoney)
                resume.append(" also because money may not be with you forever too...\n");
            else
                resume.append(" for sure\n");
        }
    //0.16 .. 0.33 (0 - 0.5 - 0)
        if (this->rate >= 0.16 && this->rate < 0.33){
            resume.append("You should consider completely changing your occupation,");
            if (abs(this->third - 0.5) < this->epsilon){
                if (this->enoughMoney)
                    resume.append(" there are things that matter not less than money too...\n");
                else
                    resume.append(" for sure\n");
            }
            else{
                if (this->enoughMoney)
                    resume.append(" also because money may not be with you forever too...\n");
                else
                    resume.append(" for sure\n");
            }
        }
    //0.33 .. 0.5 (0 - 0.5 - 0.5 OR 1 - 0 - 0)
        if (this->rate >= 0.33 && this->rate < 0.5){
            resume.append("You should consider completely changing your occupation,");
            if (this->third > 0.49){
                if (this->enoughMoney)
                    resume.append(" there are things that matter not less than money too...\n");
                else
                    resume.append(" and also you need to learn to spend less, save more\n");
            }
            else{
                if (this->enoughMoney)
                    resume.append(" also because money may not be with you forever too...\n");
                else
                    resume.append(" for sure\n");
            }
        }
    }
    if (this->rate >=0.5 && this->rate < 0.83){
        resume.append("Overall is good. ");
    //0.5 .. 0.66 (0.5 – 0.5 – 0.5 OR 1 – 0.5 – 0)
        if (this->rate < 0.6){
            if (this->first == 0 || this->second == 0 || this->third == 0){
                if (this->first == 0)
                    resume.append(" But boring work will not make you happy. Can you change your attitude or slightly vary the tasks you do? Otherwise change your job\n");
                if (this->second == 0)
                    resume.append(" But where is the problem? In people around or in yourself? If you can't change either, you better change your job..\n");
                if (this->third == 0){
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
            if (this->first == 0 || this->second == 0 || this->third == 0){
                if (this->first == 0)
                    resume.append(" But boring work will not make you happy. Can you change your attitude or slightly vary the tasks you do? Otherwise change your job\n");
                if (this->second == 0)
                    resume.append(" But where is the problem? In people around or in yourself? If you can't change either, you better change your job..\n");
                if (this->third == 0){
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
    }
    if (this->rate >= 0.83){
        resume.append("Overall is excellent! ");
        if (!this->enoughMoney)
            resume.append(" but also you need to learn to spend less, save more\n");
    }

    return resume;
}

void Professional::enoughCash(int flag){
    switch (flag){
    case 0:
        this->enoughMoney = false;
        break;
    case 1:
        this->enoughMoney = false;
        break;
    case 2:
        this->enoughMoney = true;
        break;
    }
}
