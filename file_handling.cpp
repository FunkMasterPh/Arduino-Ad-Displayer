#include <string>
#include <fstream>
#include <vector>
#include "file_handling.hpp"
#include "preset_ads.hpp"
#include "serial_port_class.hpp"

using namespace std;

int fileParsing(int argc, char** argv, vector<Ad>& adList, vector<SerialPort>& arduinos){
    for(int i = 1; i < argc; i++){
        string file = argv[i];
        ofstream serial_port;
        if(file.substr(file.find_last_of(".") + 1) == "txt")
            readFromFile(adList, file);
        else{
            serial_port.open(argv[i]);
            if(!serial_port) {
                cout << "Failed to connect to " << argv[1] << errno 
                << " - "<< strerror(errno) << endl;
                return -1; 
            }
            SerialPort sp(argv[i]);
            arduinos.push_back(sp);
        }
        serial_port.close();
    }
    return 1;
}