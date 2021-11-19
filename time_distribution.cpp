#include <algorithm>
#include <vector>
#include "ad_class.hpp"
#include "time_distribution.hpp"

#define TIME 60

using namespace std;

/*Function timeDist calculates cost per second by dividing the total sum of, 
  all comany offers by 60. Function then purges companies that can't afford, 
  at least 5 seconds of ad time and then recalculates cost per second. Ad 
  vector is populated with remaining companies and their calculated ad 
  time is set accordingly.*/
void timeDist(vector<Ad>& newAdList){
    int size = newAdList.size();
    float adTime;

    for(int i = 0; i < newAdList.size(); i++) {
        if(newAdList[i].getPaid() < (costPerSecond(newAdList) * 5)){
            newAdList.erase(newAdList.begin() + i);
            i--;
        }
    }

    for(int i = 0; i < size; i++){
       adTime = newAdList[i].getPaid() / costPerSecond(newAdList);
       newAdList[i].setAdTime(adTime);
    }
}

float costPerSecond(vector<Ad>& newAdList){
    float totalSum = 0;
    int size = newAdList.size();

    for(int i = 0; i < size; i++) {
        totalSum += newAdList[i].getPaid();
    }

    return totalSum / TIME;
}