#ifndef AD_FUNCTIONS_H
#define AD_FUNCTIONS_H
#include <vector>
#include "ad_class.hpp"
#include "serial_port_class.hpp"

int fillVector(vector<Ad>& newAdList);
void printVector(vector<Ad>& newAdList);
void writeToScreen(vector<Ad>& newAdList, vector<SerialPort>& newArduinos);
bool adLength(const string msg);

#endif