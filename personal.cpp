#include "personal.h"

Personal::Personal(Segment *parent): Segment(parent)
{
    result.emplace("excelent",
                   tr("Overall is excellent!"));
    result.emplace("norm",
                   tr("Overall is good!"));
    result.emplace("bad",
                   tr("Overall is bad!"));
    result.emplace("noPartners",
                   tr("Humans are social beasts, out of 8 billion people there must be 1 or 2 who could tolerate you for a while, at least."));
    result.emplace("whatParnterMeans",
                   tr("Please stop and think about it. What does your partner mean to you?"));
    result.emplace("familyIs",
                   tr("Family is not always your relatives. Learn to trust people and share their emotions"));
    result.emplace("trustPeople",
                   tr("Learn to trust people and share their emotions."));
    result.emplace("sharing",
                   tr("It is possible to live alone. But sharing and giving is much more fun."));
    result.emplace("stepFurther",
                   tr("Try to make one step further and you'll be delighted how people will open towards you too."));
}

QString Personal::evaluate(){
    QString resume = name + "\n";
//overall
//0..0.5
    if (rate >= 0 && rate < 0.5){
        resume += result["bad"] + "\n";
        //0 .. 0.16 (0 - 0 - 0)
        if (rate < 0.16){
            resume += result["noPartners"] + "\n";
        }
        //0.16 .. 0.33 (0 - 0.5 - 0)
        if (rate >= 0.16 && rate < 0.33){
            if ((first - 0.5 < epsilon) || (second- 0.5 < epsilon))
                resume += result["noPartners"] + "\n";
            if ((third - 0.5 < epsilon))
                resume += result["whatParnterMeans"] + "\n";
            }
        //0.33 .. 0.5 (0 - 0.5 - 0.5 OR 1 - 0 - 0)
        if (rate >= 0.33 && rate < 0.5){
                if (first == 0)
                    resume += result["familyIs"] + "\n";
                if (second == 0)
                    resume += result["trustPeople"] + "\n";
                if (third == 0)
                    resume += result["sharing"] + "\n";
        }
    }
//0.5 .. 0.83
    if (rate >=0.5 && rate < 0.83){
        resume += result["norm"] + "\n";
        //0.5 .. 0.66 (0.5 – 0.5 – 0.5 OR 1 – 0.5 – 0)
        if (rate < 0.6){
            if (first == 0 || second == 0 || third == 0){
                if (first == 0)
                        resume += result["familyIs"] + "\n";
                if (second== 0)
                        resume += result["trustPeople"] + "\n";
                if (third == 0)
                        resume += result["sharing"] + "\n";
            }
            else{
                resume += result["stepFurther"] + "\n";
            }
        }
        //0.66 .. 0.83 (0.5 – 0.5 – 1 OR 1 – 1 – 0)
        if (rate >= 0.6 && rate < 0.83){
            if (first == 0 || second == 0 || third == 0){
                if (first == 0)
                        resume += result["familyIs"] + "\n";
                if (second == 0)
                        resume += result["trustPeople"] + "\n";
                if (third == 0){
                        resume += result["sharing"] + "\n";
                }
            }
            else{
                resume += result["stepFurther"] + "\n";
            }
        }
    }
//0.83 and up
    if (rate >= 0.83){
        resume += result["excelent"] + "\n";
    }
    return resume;
}

