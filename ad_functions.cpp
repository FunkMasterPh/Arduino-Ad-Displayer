#include <vector>
#include <iostream>
#include "ad_class.hpp"
#include "ad_functions.hpp"
#include "serial_port_class.hpp"
#include "time_distribution.hpp"

int fillVector(vector<Ad>& newAdList){
    string name;
    string msg;
    string paid_s;
    double paid;

    while((getchar()) != '\n');
    cout << "Enter company name: " << endl;
    getline(cin, name);
    if(name.empty())
        return 0;
    cout << "Enter message: " << endl;
    getline(cin, msg);
    if(msg.empty())
        return 0;
    if(!adLength(msg)){
        return 0;
    }
    cout << "Add money: " << endl;
    getline(cin, paid_s);
    if(paid_s.empty())
       return 0;
    try{
        paid = stod(paid_s);
    }
    catch(exception &err){
        return 0;
    }
    Ad newAd(name, msg, paid);
    newAdList.push_back(newAd);
    return 1;
}

void printVector(vector<Ad>& newAdList){
    int size = newAdList.size();
    
    for(int i = 0; i < size; i++){
        cout << "Company Name: " << newAdList[i].getName() << endl;
        cout << "Company Message: " << newAdList[i].getMsg() << endl;
        cout << "Company Offer: " << newAdList[i].getPaid() << endl;
        cout << "Company Ad Time: " << newAdList[i].getAdTime() << endl;
    }
}

bool adLength(string msg){
    return msg.length() <= 25;
}

void writeToScreen(vector<Ad>& newAdList, vector<SerialPort>& newArduinos){
    int ardSize = newArduinos.size();
    for(int i = 0; i < ardSize; i++)
        newArduinos[i].sendAd(newAdList);
}