#include <iostream>
#include <vector>
#include <fstream>
#include "preset_ads.hpp"
#include "ad_class.hpp"
#include "time_distribution.hpp"
#include "ad_functions.hpp"
#include "serial_port_class.hpp"
#include "file_handling.hpp"
#include "display_menu.hpp"

using namespace std;

int main(int argc, char **argv){
    
    vector<Ad> adList;
    vector<SerialPort> arduinos;

    if (argc < 2) {
        cout << "Not enough arguments." << endl;
        return -1;
    }

    if(!fileParsing(argc, argv, adList, arduinos))
        return -1;
    timeDist(adList);

    mainMenu(adList, arduinos);

    return 0;
}