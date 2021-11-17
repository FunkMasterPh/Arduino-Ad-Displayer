#include <iostream>
#include <stdio.h>
#include <string.h>
#include <fcntl.h> 
#include <errno.h> 
#include <termios.h> 
#include <unistd.h> 
#include <vector>
#include <fstream>
#include "preset_ads.hpp"
#include "ad_class.hpp"
#include "time_distribution.hpp"
#include "ad_functions.hpp"

using namespace std;

int main(int argc, char **argv){

    if (argc < 2) {
        cout << "Not enough arguments." << endl;
        return -1;
    }
    for(int i = 1; i < argc - 1; i++){
        ofstream serial_port(argv[i]);
        if(!serial_port) {
            cout << "Failed to connect to " << argv[i] << errno 
            << " - "<< strerror(errno) << endl;
            return -1; 
        }
    }

    vector<Ad> adList;

    while(1){
        int choice;
        cout << "**************************" << endl;
        cout << "* 1) Add advertisement    " << endl;
        cout << "* 2) Add ads from file    " << endl;
        cout << "* 3) List advertisements  " << endl;
        cout << "* 4) Calculate time dist  " << endl;
        cout << "* 5) Display Ads          " << endl;
        cout << "**************************" << endl;
        try{
            cin >> choice;
            if(choice < 1 || choice > 5){
                throw (choice);
            } 
        }
        catch(int choice){
            cout << "Not a valid choice" << endl;
        }

        switch(choice){
            case 1:
                fillVector(adList);
                break;
            case 2:
                readFromFile(adList);
            case 3: 
                printVector(adList);
                break;
            case 4: 
                timeDist(adList);
                break;
            case 5:
                for(int i = 1; i <= argc - 1; i++){
                    for(int j = 0; j < adList.size(); j++){
                        ofstream serial_port(argv[i]);
                        serial_port << adList[j].getMsg() << "," << adList[j].getAdTime() << "|";
                        cout << adList[j].getMsg() << "," << adList[j].getAdTime() << "|";
                        serial_port.close();
                        sleep(1);
                    }
                }
                break;
            default:
                break;

        }
    } 
    return 0;
}