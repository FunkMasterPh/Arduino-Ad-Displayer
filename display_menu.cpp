#include <iostream>
#include <vector>
#include "display_menu.hpp"
#include "ad_class.hpp"
#include "serial_port_class.hpp"
#include "ad_functions.hpp"
#include "time_distribution.hpp"

using namespace std;

void mainMenu(vector<Ad>& newAdList, vector<SerialPort>& newArduinos){
    while(1){
        char choice;
        cout << "**************************" << endl;
        cout << "* 1) Add Ads              " << endl;
        cout << "* 2) List Ads             " << endl;
        cout << "* 3) Display Ads          " << endl;
        cout << "* 4) Exit                 " << endl;
        cout << "**************************" << endl;

        cin >> choice;

        switch(choice){
            case '1':
                if(!fillVector(newAdList))
                    cout << "Error: Required field entered incorrectly or message exceeded 25 characters." << endl;  
                timeDist(newAdList);
                break;
            case '2': 
                printVector(newAdList);
                break;
            case '3':
                if(!newAdList.size()){
                    cout << "No messages to display." << endl;
                    break;
                }
                writeToScreen(newAdList, newArduinos);
                break; 
            case '4':
                exit(1);
                break;
            default:{
                while((getchar()) != '\n');
                cout << "Invalid input." << endl;
                break;
            }
        }
    }
}