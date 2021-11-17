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
#include "serial_port_class.hpp"

using namespace std;

int main(int argc, char **argv){
    
    vector<Ad> adList;
    vector<SerialPort> arduinos;

    if (argc < 2) {
        cout << "Not enough arguments." << endl;
        return -1;
    }
    ofstream serial_port;
    for(int i = 1; i < argc; i++) {
        serial_port.open(argv[i]);
        if(!serial_port) {
            cout << "Failed to connect to " << argv[1] << errno 
            << " - "<< strerror(errno) << endl;
            return -1; 
        }
        serial_port.close();
    }
    for(int i = 1; i < argc; i++){
        SerialPort sp(argv[i]);
        arduinos.push_back(sp);
    }
    for(int i = 0; i < arduinos.size(); i++){
        cout << arduinos[i].getPort() << endl;
    }

    while(1){
        int choice;
        cout << "**************************" << endl;
        cout << "* 1) Add advertisement    " << endl;
        cout << "* 2) Add ads from file    " << endl;
        cout << "* 3) List advertisements  " << endl;
        cout << "* 4) Calculate time dist  " << endl;
        cout << "* 5) Display Ads          " << endl;
        cout << "**************************" << endl;

        cin >> choice;

        switch(choice){
            case 1:
                fillVector(adList);
                break;
            case 2:
                readFromFile(adList);
                break;
            case 3: 
                printVector(adList);
                break;
            case 4: 
                timeDist(adList);
                break;
            case 5:{
                int ardSize = arduinos.size();
                for(int i = 0; i < ardSize; i++)
                    
                    arduinos[i].sendAd(adList);
                break;
            }     
            default:
                cout << "Invalid input." << endl;
                break;

        }
    } 
    return 0;
}