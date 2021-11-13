#ifndef TIME_DISTRIBUTION_H
#define TIME_DISTRIBUTION_H
#include "ad_class.hpp"
#define TIME 60

int timeDist(vector<Ad>& newAdList){
    int totalSum;
    int cps; // cost per second
    int size = newAdList.size();
   
    for(int i = 0; i < size; i++)
        totalSum += newAdList[i].getPaid();

    cps = totalSum / TIME;
    
    return totalSum;
}


#endif