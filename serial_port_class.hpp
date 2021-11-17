#ifndef SERIAL_PORT_CLASS_H
#define SERIAL_PORT_CLASS_H

#include <iostream>
#include <fstream>
#include <exception>
#include <algorithm>
#include <random>

using namespace std;

class SerialPort{
    private:
    string serial_port;
    ofstream sp;

    public:
    SerialPort(string _serial_port){
        serial_port = _serial_port;
        sp.open(serial_port);
    }

    SerialPort(const SerialPort &other){
        serial_port = other.serial_port;
        sp.open(serial_port);
    }
    
    string getPort(){
        return serial_port;
    }

    void sendAd(vector<Ad>& newAdList){
        int adSize = newAdList.size();
        /* random_device rd;
        default_random_engine gen(rd); */
        shuffle(newAdList.begin(), newAdList.end(), default_random_engine());
        for(int i = 0; i < adSize; i++){
            sp << newAdList[i].getMsg() << "," << newAdList[i].getAdTime()<< "|";
        }
        sp.close();
    }

    ~SerialPort(){
        cout << "Destructor called" << endl;
    }


};








#endif