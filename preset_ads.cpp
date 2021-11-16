#include <iostream>
#include <fstream>
#include <vector>
#include "preset_ads.hpp"
#include "ad_class.hpp"

using namespace std;

void readFromFile(vector<Ad>& newAdList){
    string cmpName;
    string msg;
    string paid;
    fstream presetAds;
    presetAds.open("preset_ads.txt", ios::in);
        if(!presetAds){
            cout << "No such file." << endl;
        }
    while(!presetAds.eof()){
        getline(presetAds, cmpName);
        getline(presetAds, msg);
        getline(presetAds, paid);
        int paidInt = stoi(paid);
        Ad newAd(cmpName, msg, paidInt);
        newAdList.push_back(newAd);
    }
    presetAds.close();
}