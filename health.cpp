#include "health.h"

Health::Health(Segment *parent)
    : Segment{parent}
{

}
std::string Health::evaluate(){
    std::string resume = "\n" + name;
//overall
//0..0.5
    if (rate >= 0 && rate < 0.5){
        resume.append("\n\tOverall is bad.\n\t");
    }
//0.5 .. 0.83
    if (rate >=0.5 && rate < 0.83){
        resume.append("\n\tOverall is good.\n\t");
    }
//0.83 and up
    if (rate >= 0.83){
        resume.append("\n\tOverall is excellent!\n\t");
    }
    return resume;
}
