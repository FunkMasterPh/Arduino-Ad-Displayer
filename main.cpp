#include <iostream>
#include <string>
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
#include "file_handling.hpp"

using namespace std;

int main(int argc, char **argv){
    
    vector<Ad> adList;
    vector<SerialPort> arduinos;

    if (argc < 2) {
        cout << "Not enough arguments." << endl;
        return -1;
    }

    fileParsing(argc, argv, adList, arduinos);

    while(1){
        int choice;
        cout << "**************************" << endl;
        cout << "* 1) Add advertisement    " << endl;
        cout << "* 2) List advertisements  " << endl;
        cout << "* 3) Calculate time dist  " << endl;
        cout << "* 4) Display Ads          " << endl;
        cout << "* 5) Quit                 " << endl;
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
                writeToScreen(adList, arduinos);
                break; 
            case 5:
                exit(1);
            default:
                cout << "Invalid input." << endl;
                break;

        }
    } 
    return 0;
}