#include <iostream>
#include <fstream>
//#include <exception>
#include <algorithm>
#include <random>
#include "serial_port_class.hpp"
#include "ad_class.hpp"

using namespace std;

SerialPort::SerialPort(string _serial_port){
    serial_port = _serial_port;
    sp.open(serial_port);
}

SerialPort::SerialPort(const SerialPort &other){
    serial_port = other.serial_port;
    sp.open(serial_port);
}

void SerialPort::sendAd(vector<Ad>& newAdList){
    int adSize = newAdList.size();
    shuffle(newAdList.begin(), newAdList.end(), default_random_engine());
    for(int i = 0; i < adSize; i++){
        sp << newAdList[i].getMsg() << "," << newAdList[i].getAdTime()<< "|";
    }
    sp.close();
}

SerialPort::~SerialPort(){
    sp.close();
}

