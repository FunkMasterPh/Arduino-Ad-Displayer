#include <iostream>
#include <fstream>
#include <vector>
#include "preset_ads.hpp"
#include "ad_class.hpp"
#include "ad_functions.hpp"

using namespace std;

int readFromFile(vector<Ad>& newAdList, string file){
    string cmpName;
    string msg;
    string paid;
    int paidInt;
    fstream presetAds;
    presetAds.open(file, ios::in);
        if(!presetAds){
            presetAds.close();
            return -1;
        }
    while(!presetAds.eof()){
        getline(presetAds, cmpName);
        if(!cmpName.empty())
            getline(presetAds, msg);
        else{
            presetAds.close(); 
            return -1;
        }
        if(!msg.empty())
            getline(presetAds, paid);
        else{
            presetAds.close();
            return -1;
        }
        if(!paid.empty()){
            if(!(paidInt = stoi(paid))){
                presetAds.close();
                return -1;
            }
        }
        else{
            presetAds.close();
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

