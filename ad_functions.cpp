#include <vector>
#include <iostream>
#include "ad_class.hpp"
#include "ad_functions.hpp"

void fillVector(vector<Ad>& newAdList){
    string name;
    string msg;
    int paid;

    while((getchar()) != '\n');
    cout << "Enter company name: " << endl;
    getline(cin, name);
    cout << "Enter message: " << endl;
    getline(cin, msg);
    //while((getchar()) != '\n');
    cout << "Add money: " << endl;
    cin >> paid;
    //while((getchar()) != '\n');

    Ad newAd(name, msg, paid);
    newAdList.push_back(newAd);

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