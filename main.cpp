#include <iostream>
#include <stdio.h>
#include <string.h>
#include <fcntl.h> 
#include <errno.h> 
#include <termios.h> 
#include <unistd.h> 
#include <vector>
#include "ad_class.hpp"
#include "time_distribution.hpp"

using namespace std;

// int serial_port = open("/dev/cu.usbmodem1442201", O_RDWR);

void fillVector(vector<Ad>&);
void printVector(vector<Ad>&);

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

    for(int i = 0; i < size; i++){
        cout << "Company Name: " << newAdList[i].getName() << endl;
        cout << "Company Message" << newAdList[i].getMsg() << endl;
    }
}

int main(int argc, char **argv){
    int serial_port;

    if (argc < 2) {
        cout << "Not enough arguments." << endl;
        return -1;
    }
    serial_port = open(argv[1], O_RDWR);
    
    if(serial_port < 0){
        cout << "Failed to connect to " << argv[1] << errno 
        << " - "<< strerror(errno) << endl;
        return -1;
    }else{
        cout << "Success" << endl;
    }
    vector<Ad> adList;
    while(1){
        fillVector(adList);
        printVector(adList);


    }
    return 0;
}

    /* char msg[MAX_MSG], companyName[MAX_NAME];
    #define MAX_MSG 120
    #define MAX_NAME 40
    int paid;
    cout << "Enter company name: " << endl;
    cin.getline(companyName, MAX_NAME);
    cout << "Enter message: " << endl;
    cin.getline(msg, MAX_MSG);
    cout << "Add money: " << endl;
    cin >> paid;
    //Ad* newAd = new Ad(companyName, msg, paid);
    Ad petersBygg("Peters Bygg", "Anställ oss", 100);
    Ad robbans("Robbans", "Robban bra", 200);


    cout << timeDist(petersBygg, robbans) << endl; */


    //write(serial_port, newAd->getMsg(), strlen(newAd->getMsg()));