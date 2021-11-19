#ifndef FILE_HANDLING_H
#define FILE_HANDLING_H

#include <vector>
#include "ad_class.hpp"
#include "serial_port_class.hpp"

using namespace std;

int fileParsing(int argc, char** argv, vector<Ad>& adList, vector<SerialPort>& arduinos);


#endif
