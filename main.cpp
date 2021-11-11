#include <iostream>
#include <stdio.h>
#include <string.h>
#include <fcntl.h> 
#include <errno.h> 
#include <termios.h> 
#include <unistd.h> 
#include "ad_class.hpp"

using namespace std;

#define MAX_MSG 120
#define MAX_NAME 40

int serial_port = open("/dev/cu.usbmodem1442301", O_RDWR);

int main(){

    if(serial_port < 0){
        cout << "Failed" << errno << " "<< strerror(errno) << endl;
    }else{
        cout << "Success" << endl;
    }
    char msg[MAX_MSG], companyName[MAX_NAME];
    cout << "Enter company name: " << endl;
    cin.getline(companyName, MAX_NAME);
    cout << "Enter message: " << endl;
    cin.getline(msg, MAX_MSG);
    Ad newAd(companyName, msg, 100);
    
    write(serial_port, newAd.getMsg(), strlen(newAd.getMsg()));




    return 0;
}