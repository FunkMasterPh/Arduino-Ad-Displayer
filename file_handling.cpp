#include <fstream>
#include <vector>
#include "file_handling.hpp"
#include "preset_ads.hpp"
#include "serial_port_class.hpp"

using namespace std;

int fileParsing(const int argc, char** argv, vector<Ad>& adList, 
                vector<SerialPort>& arduinos){
    for(int i = 1; i < argc; i++){
        string file = argv[i];
        ofstream serial_port;
        //Looks for file containing ad-info and reads the info 
        if(file.substr(file.find_last_of(".") + 1) == "txt")
            readFromFile(adList, file);
        /*Checks if serial port exists, if it does, 
        create an object and add it to arduinos vector*/
        else if(FILE *f = fopen(file.c_str(), "r")){
            serial_port.open(argv[i]);
            if(!serial_port){
                cout << "Failed to connect to " << argv[1] << errno 
                << " - "<< strerror(errno) << endl;
                return 0; 
            }
            SerialPort sp(argv[i]);
            arduinos.push_back(sp);
        }else{
            cout << "Unable to open file " << file << endl;
            return 0;
        }
        serial_port.close();
    }
    return 1;
}