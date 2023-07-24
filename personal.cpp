#include "personal.h"

Personal::Personal(Segment *parent): Segment(parent)
{

}

std::string Personal::evaluate(){
    std::string resume = "\n" + name;
//overall
//0..0.5
    if (rate >= 0 && rate < 0.5){
        resume.append("\n\tOverall is bad.\n\t");
        //0 .. 0.16 (0 - 0 - 0)
        if (rate < 0.16){
            resume.append(" Humans are social beasts, out of 8 billion people there must be 1 or 2 who could tolerate you for a while, at least.\n");
        }
        //0.16 .. 0.33 (0 - 0.5 - 0)
        if (rate >= 0.16 && rate < 0.33){
            if ((first - 0.5 < epsilon) || (second- 0.5 < epsilon))
                resume.append(" Humans are social beasts, out of 8 billion people there must be 1 or 2 who could tolerate you for a while, at least.\n");
            if ((third - 0.5 < epsilon))
                resume.append(" Please stop and think about it. What does your partner mean to you?.\n");

            }
        //0.33 .. 0.5 (0 - 0.5 - 0.5 OR 1 - 0 - 0)
        if (rate >= 0.33 && rate < 0.5){
                if (first == 0)
                    resume.append(" Family is not always your relatives. Learn to trust people and share their emotions.\n");
                if (second == 0)
                resume.append(" Learn to trust people and share their emotions.\n");
                if (third == 0)
                    resume.append(" It is possible to live alone. But sharing and giving is much more fun.\n");
        }
    }
//0.5 .. 0.83
    if (rate >=0.5 && rate < 0.83){
        resume.append("\n\tOverall is good.\n\t");
        //0.5 .. 0.66 (0.5 – 0.5 – 0.5 OR 1 – 0.5 – 0)
        if (rate < 0.6){
            if (first == 0 || second == 0 || third == 0){
                if (first == 0)
                    resume.append(" Family is not always your relatives. Learn to trust people and share their emotions.\n");
                if (second== 0)
                    resume.append(" Learn to trust people and share their emotions.\n");
                if (third == 0)
                    resume.append(" It is possible to live alone. But sharing and giving is much more fun.\n");
            }
            else{
                resume.append(" Try to make one step further and you'll be delighted how people will open towards you too.");
            }
        }
        //0.66 .. 0.83 (0.5 – 0.5 – 1 OR 1 – 1 – 0)
        if (rate >= 0.6 && rate < 0.83){
            if (first == 0 || second == 0 || third == 0){
                if (first == 0)
                    resume.append(" Family is not always your relatives. Learn to trust people and share their emotions.\n");
                if (second == 0)
                    resume.append(" Learn to trust people and share their emotions.\n");
                if (third == 0){
                    resume.append(" It is possible to live alone. But sharing and giving is much more fun.\n");
                }
            }
            else{
                resume.append(" Try to make one step further and you'll be delighted how people will open towards you too.");
            }
        }
    }
//0.83 and up
    if (rate >= 0.83){
        resume.append("\n\tOverall is excellent!\n\t");
    }
    return resume;
}

