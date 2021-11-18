#include <iostream>
#include <fstream>
#include <vector>
#include "preset_ads.hpp"
#include "ad_class.hpp"
#include "ad_functions.hpp"

using namespace std;

int readFromFile(vector<Ad>& newAdList){
    string cmpName;
    string msg;
    string paid;
    int paidInt;
    fstream presetAds;
    presetAds.open("preset_ads.txt", ios::in);
        if(!presetAds){
            return -1;
        }
    while(!presetAds.eof()){
        getline(presetAds, cmpName);
        if(!cmpName.empty())
            getline(presetAds, msg);
        else 
            return -1;
        if(!msg.empty())
            getline(presetAds, paid);
        else
            return -1;
        if(!paid.empty()){
            if(!(paidInt = stoi(paid)))
                return -1;
            }
        else{
            cout << "check" << endl;
            return -1;
        }
        if(adLength(msg)){
            Ad newAd(cmpName, msg, paidInt);
            newAdList.push_back(newAd);
        }else{
            cout << "Skipped entry due to messeage exceeding maximum length." << endl;
        }
    }
    presetAds.close();
    return 1;
}

