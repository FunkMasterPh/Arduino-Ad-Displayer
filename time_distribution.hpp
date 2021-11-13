#ifndef TIME_DISTRIBUTION_H
#define TIME_DISTRIBUTION_H
#include "ad_class.hpp"
#define TIME 60
#include <algorithm>


void timeDist(vector<Ad>& newAdList){
    int totalSum;
    int cps; // cost per second
    int size = newAdList.size();
   
    for(int i = 0; i < size; i++) {
        totalSum += newAdList[i].getPaid();
        cout << newAdList[i].getName() << endl;
    }
    
    cps = totalSum / TIME;

    for(int i = 0; i < size; i++) {
        if(newAdList[i].getPaid() < (cps * 5))
        newAdList.erase(newAdList.begin() + i);
    }
    int newsize = newAdList.size();
    for(int i = 0; i < newsize; i++) {
       cout << newAdList[i].getName() << endl; 
    }

}
#endif