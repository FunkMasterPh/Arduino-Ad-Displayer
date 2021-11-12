#ifndef AD_CLASS_H
#define AD_CLASS_H
#include <iostream>
using namespace std;

class Ad{
    public:
        char* name;
        char* message;
        int paid;


    Ad(char* _name, char* _message, int _paid){
        name = _name;
        message = _message;
        paid = _paid;
    }
    char* getMsg(){
        return message;
    }

    char* getName(){
        return name;
    }
    
    int getPaid(){
        return paid;
    }
    ~Ad(){
        cout << "Calling destructor" << endl;
    }
};

#endif