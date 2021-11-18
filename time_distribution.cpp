#include <algorithm>
#include <vector>
#include "ad_class.hpp"
#include "time_distribution.hpp"

#define TIME 60

using namespace std;

float costPerSecond(vector<Ad>& newAdList){
    double totalSum;
    double cps; // cost per second
    int size = newAdList.size();

    cps = calcCost(newAdList);

    for(int i = 0; i < newAdList.size(); i++) {
        if(newAdList[i].getPaid() < (cps * 5)){
            newAdList.erase(newAdList.begin() + i);
            i--;
        }
    }
    int newsize = newAdList.size();

    cps = calcCost(newAdList);

    return cps;

}

void timeDist(vector<Ad>& newAdList){
    int size = newAdList.size();
    double cps = costPerSecond(newAdList);
    double adTime;

    for(int i = 0; i < size; i++){
       adTime = newAdList[i].getPaid() / cps;
       newAdList[i].setAdTime(adTime);
    }
}

float calcCost(vector<Ad>& newAdList){
    double totalSum = 0;
    int size = newAdList.size();

    for(int i = 0; i < size; i++) {
        totalSum += newAdList[i].getPaid();
    }

    return totalSum / TIME;
}