#include <vector>
#include "ad_class.hpp"
#include "ad_functions.hpp"

void fillVector(vector<Ad>& newAdList){
    string name;
    string msg;
    int paid;

    cout << "Enter company name: " << endl;
    cin >> name;
    while((getchar()) != '\n');
    cout << "Enter message: " << endl;
    cin >> msg;
    while((getchar()) != '\n');
    cout << "Add money: " << endl;
    cin >> paid;
    while((getchar()) != '\n');

    Ad newAd(name, msg, paid);
    newAdList.push_back(newAd);

}

void printVector(vector<Ad>& newAdList){
    int size = newAdList.size();

    for(vector<Ad>::iterator it = newAdList.begin(); it != newAdList.end(); it++)
    for(int i = 0; i < size; i++){
        cout << "Company Name: " << newAdList[i].getName() << endl;
        cout << "Company Message: " << newAdList[i].getMsg() << endl;
        cout << "Company Offer: " << newAdList[i].getPaid() << endl;
        cout << "Company Ad Time: " << newAdList[i].getAdTime() << endl;
    }
}