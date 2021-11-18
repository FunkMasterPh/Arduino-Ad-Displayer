#ifndef SERIAL_PORT_CLASS_H
#define SERIAL_PORT_CLASS_H

#include <iostream>
#include "ad_class.hpp"

using namespace std;

class SerialPort{
    private:
    string serial_port;
    ofstream sp;

    public:
    SerialPort(string _serial_port);
    
    SerialPort(const SerialPort &other);

    void sendAd(vector<Ad>& newAdList);

    ~SerialPort();

};

#endif