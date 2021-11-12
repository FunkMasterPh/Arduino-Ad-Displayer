#ifndef TIME_DISTRIBUTION_H
#define TIME_DISTRIBUTION_H
#include "ad_class.hpp"

int timeDist(Ad& obj1, Ad& obj2){
    int totalSum;
    int cps;
    totalSum = obj1.getPaid() + obj2.getPaid();
    cps = totalSum / 60;
    
    return totalSum;
}


#endif