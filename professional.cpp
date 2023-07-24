#include "professional.h"

Professional::Professional(Segment *parent): Segment(parent)
{

}

std::string Professional::evaluate(){
    std::string resume = "\n" + name;
//overall
//0..0.5
    if (rate >=0 && rate < 0.5){
        resume.append("\n\tOverall is bad.\n\t");
    //0 .. 0.16 (0 - 0 - 0)
        if (rate < 0.16){
            resume.append("\tYou should consider completely changing your occupation.\n");
            if (this->enoughMoney)
                resume.append("\tYour money may not be with you forever too...\n");
        }
    //0.16 .. 0.33 (0 - 0.5 - 0)
        if (rate >= 0.16 && rate < 0.33){
            resume.append("\tYou should consider completely changing your occupation\n");
            if (abs(third - 0.5) < epsilon){
                if (this->enoughMoney)
                    resume.append("\tThere are things that matter not less than money too...\n");
            }
            else{
                if (this->enoughMoney)
                    resume.append("\tAlso because money may not be with you forever too...\n");
            }
        }
    //0.33 .. 0.5 (0 - 0.5 - 0.5 OR 1 - 0 - 0)
        if (rate >= 0.33 && rate < 0.5){
            resume.append("\tYou should consider completely changing your occupation.\n");
            if (third > 0.49){
                if (this->enoughMoney)
                    resume.append("\tThere are things that matter not less than money too...\n");
                else
                    resume.append("\tYou need to learn to spend less, save more\n");
            }
            else{
                if (this->enoughMoney)
                    resume.append("\tBecause money may not be with you forever too...\n");
            }
        }
    }
//0.5 .. 0.83
    if (rate >=0.5 && rate < 0.83){
        resume.append("\n\tOverall is good.\n\t");
    //0.5 .. 0.66 (0.5 – 0.5 – 0.5 OR 1 – 0.5 – 0)
        if (rate < 0.6){
            if (first == 0 || second == 0 || third == 0){
                if (first == 0)
                    resume.append("\tBut boring work will not make you happy. Can you change your attitude or slightly vary the tasks you do? Otherwise change your job\n");
                if (second == 0)
                    resume.append("\tBut where is the problem? In people around or in yourself? If you can't change either, you better change your job..\n");
                if (third == 0){
                    resume.append("\tBut money matters in this life, for sure. It is important to receive fair compensation for your work\n");
                    if (this->enoughMoney)
                        resume.append("\tAlso because money may not be with you forever too...\n");
                }
                else
                    if (!this->enoughMoney)
                    resume.append("\tYou need to learn to spend less, save more\n");
            }
            else
                if (!this->enoughMoney)
                    resume.append("\tYou need to learn to spend less, save more\n");
        }
    //0.66 .. 0.83 (0.5 – 0.5 – 1 OR 1 – 1 – 0)
        if (rate >= 0.6 && rate < 0.83){
            if (first == 0 || second == 0 || third == 0){
                if (first == 0)
                    resume.append("\tBut boring work will not make you happy. Can you change your attitude or slightly vary the tasks you do? Otherwise change your job\n");
                if (second == 0)
                    resume.append("\tBut where is the problem? In people around or in yourself? If you can't change either, you better change your job..\n");
                if (third == 0){
                    resume.append("\tBut money matters in this life, for sure. It is important to receive fair compensation for your work\n");
                    if (this->enoughMoney)
                        resume.append("\tAlso because money may not be with you forever too...\n");
                }
            }
            else{
                if (!this->enoughMoney)
                    resume.append("\tYou need to learn to spend less, save more\n");
            }
        }
    }
//0.83 and up
    if (rate >= 0.83){
        resume.append("\n\tOverall is excellent!\n\t");
        if (!this->enoughMoney)
            resume.append("\tYou need to learn to spend less, save more\n");
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
