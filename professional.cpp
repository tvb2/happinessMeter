#include "professional.h"

Professional::Professional(Segment *parent): Segment(parent)
{
    result.emplace("OAexcelent",
                   tr("Overall is excellent!"));
    result.emplace("OAnorm",
                   tr("Overall is good!"));
    result.emplace("OAbad",
                   tr("Overall is bad!"));
    result.emplace("occupationChange",
                   tr("You should consider completely changing your occupation."));
    result.emplace("moneyNotForever",
                   tr("Your money may not be with you forever too..."));
    result.emplace("moneyNotOnly",
                   tr("There are things that matter not less than money too..."));
    result.emplace("moneyLearnToSave",
                   tr("You need to learn to spend less, save more"));
    result.emplace("occupationBoring",
                   tr("Boring work will not make you happy. Can you change your attitude or slightly vary the tasks you do? Otherwise change your job"));
    result.emplace("peopleBad",
                   tr("But where is the problem? In people around or in yourself? If you can't change either, you better change your job.."));
    result.emplace("moneyFairPay",
                   tr("Money matters in this life, for sure. It is important to receive fair compensation for your work"));
}

QString Professional::evaluate(){
    QString resume = name + "\n";

//if at least one parameter is zero - that is bad
    if (first == 0 || second == 0 || third == 0){
        resume += result["OAbad"] + "\n"+
                  result["occupationChange"] + "\n";
        if (first == 0){
            resume += result["occupationBoring"] + "\n";
        }
        if (second == 0){
            resume += result["peopleBad"] + "\n";
        }
        if (third == 0){
            resume += result["moneyFairPay"] + "\n";
            if (enoughMoney){
                resume += result["moneyNotForever"] + "\n";
            }
        }
        if (third != 0){
            if (enoughMoney){
                resume += result["moneyNotOnly"] + "\n";
            }
            else{
                resume += result["moneyLearnToSave"] + "\n";

            }
        }
        return resume;
    }

//overall
//0..0.5
//0.33 .. 0.5 (0 - 0.5 - 0.5 OR 1 - 0 - 0)- taken care of when at least one is zero

//0.5 .. 0.83
    if (rate >=0.5 && rate < 0.83){
        resume += result["OAnorm"] + "\n";
    //0.5 .. 0.66 (0.5 – 0.5 – 0.5)
        if (rate < 0.6){
            if (!this->enoughMoney)
                resume += result["moneyLearnToSave"] + "\n";
        }
    //0.66 .. 0.83 (0.5 – 0.5 – 1)
        if (rate >= 0.6 && rate < 0.83){
            if (!this->enoughMoney)
                    resume += result["moneyLearnToSave"] + "\n";
        }
    }
//0.83 and up
    if (rate >= 0.83){
        resume += result["OAexcelent"] + "\n";
        if (!this->enoughMoney)
            resume += result["moneyLearnToSave"] + "\n";
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
