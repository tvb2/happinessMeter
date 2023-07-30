#include "professional.h"

Professional::Professional(Segment *parent): Segment(parent)
{
    result.emplace("excelent",
                   tr("Overall is excellent!"));
    result.emplace("norm",
                   tr("Overall is good!"));
    result.emplace("bad",
                   tr("Overall is bad!"));
    result.emplace("changeOccupation",
                   tr("You should consider completely changing your occupation."));
    result.emplace("moneyNotForever",
                   tr("Your money may not be with you forever too..."));
    result.emplace("notOnlyMoney",
                   tr("There are things that matter not less than money too..."));
    result.emplace("learnToSave",
                   tr("You need to learn to spend less, save more"));
    result.emplace("boringWork",
                   tr("But boring work will not make you happy. Can you change your attitude or slightly vary the tasks you do? Otherwise change your job"));
    result.emplace("badPeople",
                   tr("But where is the problem? In people around or in yourself? If you can't change either, you better change your job.."));
    result.emplace("fairPay",
                   tr("But money matters in this life, for sure. It is important to receive fair compensation for your work"));
}

QString Professional::evaluate(){
    QString resume = name + "\n";
//overall
//0..0.5
    if (rate >=0 && rate < 0.5){
        resume += result["bad"] + "\n";
    //0 .. 0.16 (0 - 0 - 0)
        if (rate < 0.16){
            resume.append("\tYou should consider completely changing your occupation.\n");
            if (this->enoughMoney)
                resume += result["moneyNotForever"] + "\n";
        }
    //0.16 .. 0.33 (0 - 0.5 - 0)
        if (rate >= 0.16 && rate < 0.33){
                resume += result["changeOccupation"] + "\n";
            if (abs(third - 0.5) < epsilon){
                if (this->enoughMoney)
                    resume += result["notOnlyMoney"] + "\n";
            }
            else{
                if (this->enoughMoney)
                    resume += result["moneyNotForever"] + "\n";
            }
        }
    //0.33 .. 0.5 (0 - 0.5 - 0.5 OR 1 - 0 - 0)
        if (rate >= 0.33 && rate < 0.5){
            resume += result["changeOccupation"] + "\n";
            if (third > 0.49){
                if (this->enoughMoney)
                    resume += result["notOnlyMoney"] + "\n";
                else
                        resume += result["learnToSave"] + "\n";
            }
            else{
                if (this->enoughMoney)
                    resume += result["moneyNotForever"] + "\n";
            }
        }
    }
//0.5 .. 0.83
    if (rate >=0.5 && rate < 0.83){
        resume += result["norm"] + "\n";
    //0.5 .. 0.66 (0.5 – 0.5 – 0.5 OR 1 – 0.5 – 0)
        if (rate < 0.6){
            if (first == 0 || second == 0 || third == 0){
                if (first == 0)
                    resume += result["boringWork"] + "\n";
                if (second == 0)
                    resume += result["badPeople"] + "\n";
                if (third == 0){
                    resume += result["fairPay"] + "\n";
                    if (this->enoughMoney)
                        resume += result["moneyNotForever"] + "\n";
                }
                else
                    if (!this->enoughMoney)
                        resume += result["learnToSave"] + "\n";
            }
            else
                if (!this->enoughMoney)
                    resume += result["learnToSave"] + "\n";
        }
    //0.66 .. 0.83 (0.5 – 0.5 – 1 OR 1 – 1 – 0)
        if (rate >= 0.6 && rate < 0.83){
            if (first == 0 || second == 0 || third == 0){
                if (first == 0)
                        resume += result["boringWork"] + "\n";
                if (second == 0)
                        resume += result["badPeople"] + "\n";
                if (third == 0){
                        resume += result["fairPay"] + "\n";
                    if (this->enoughMoney)
                        resume += result["moneyNotForever"] + "\n";
                }
            }
            else{
                if (!this->enoughMoney)
                        resume += result["learnToSave"] + "\n";
            }
        }
    }
//0.83 and up
    if (rate >= 0.83){
        resume += result["excelent"] + "\n";
        if (!this->enoughMoney)
            resume += result["learnToSave"] + "\n";
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

void Professional::testEval(double f, double s, double th, QString result){
    this->setFirst(f); this->setSecond(s);  this->setThird(th);
    QVERIFY(this->evaluate() == result);
}
