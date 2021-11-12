#ifndef AD_CLASS_H
#define AD_CLASS_H
#include <iostream>
using namespace std;

class Ad{
    public:
        string name;
        string message;
        int paid;


    Ad(string _name, string _message, int _paid){
        name = _name;
        message = _message;
        paid = _paid;
    }
    string getMsg(){
        return message;
    }

    string getName(){
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