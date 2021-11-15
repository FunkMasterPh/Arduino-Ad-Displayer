#include <iostream>
#include <stdio.h>
#include <string.h>
#include <fcntl.h> 
#include <errno.h> 
#include <termios.h> 
#include <unistd.h> 
#include <vector>
#include <fstream>
#include "ad_class.hpp"
#include "time_distribution.hpp"
#include "ad_functions.hpp"

using namespace std;


int main(int argc, char **argv){

    if (argc < 2) {
        cout << "Not enough arguments." << endl;
        return -1;
    }
    ofstream serial_port(argv[1]);
    if(!serial_port) {
        cout << "Failed to connect to " << argv[1] << errno 
        << " - "<< strerror(errno) << endl;
        return -1; 
    }
    vector<Ad> adList;
    while(1){

        int choice;
        cout << "**************************" << endl;
        cout << "* 1) Add advertisement    " << endl;
        cout << "* 2) List advertisements  " << endl;
        cout << "* 3) Calculate time dist  " << endl;
        cout << "* 4) Display Ads          " << endl;
        cout << "**************************" << endl;

        cin >> choice;

        switch(choice){
            case 1:
                fillVector(adList);
                break;
            case 2: 
                printVector(adList);
                break;
            case 3: 
                timeDist(adList);
                break;
            case 4:
                for(int i = 0; i < adList.size(); i++){
                    ofstream serial_port(argv[1]);
                    serial_port << adList[i].getName() << "," << adList[i].getMsg() << "," << adList[i].getAdTime() << "|";
                    cout << adList[i].getName() << "," << adList[i].getMsg() << "," << adList[i].getAdTime() << "|";
                    serial_port.close();
                }   
                break;
            default:
                break;

        }
    }
    
    return 0;
}