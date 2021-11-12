#include <iostream>
#include <stdio.h>
#include <string.h>
#include <fcntl.h> 
#include <errno.h> 
#include <termios.h> 
#include <unistd.h> 
#include "ad_class.hpp"
#include "time_distribution.hpp"

using namespace std;

#define MAX_MSG 120
#define MAX_NAME 40

int serial_port = open("/dev/cu.usbmodem1442201", O_RDWR);
int counter = 0;


int main(){
    
    if(serial_port < 0){
        cout << "Failed" << errno << " "<< strerror(errno) << endl;
    }else{
        cout << "Success" << endl;
    }
    char msg[MAX_MSG], companyName[MAX_NAME];
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


    cout << timeDist(petersBygg, robbans) << endl;


    //write(serial_port, newAd->getMsg(), strlen(newAd->getMsg()));


    return 0;
}