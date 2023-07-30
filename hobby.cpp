#include "hobby.h"

Hobby::Hobby(Segment *parent): Segment(parent)
{
    result.emplace("excelent",
                   tr("Overall is excellent!"));
    result.emplace("norm",
                   tr("Overall is good!"));
    result.emplace("bad",
                   tr("Overall is bad!"));
}
QString Hobby::evaluate(){
    QString resume = "\n" + name;
    //overall
//0..0.5
    if (rate >= 0 && rate < 0.5){
        resume += result["bad"] + "\n";
        return resume;
    }
//0.5 .. 0.83
    if (rate >=0.5 && rate < 0.83){
        resume += result["norm"] + "\n";
        return resume;
    }
//0.83 and up
    if (rate >= 0.83){
        resume += result["excelent"] + "\n";
        return resume;
    }
    return resume;
}
