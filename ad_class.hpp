#ifndef AD_CLASS_H
#define AD_CLASS_H

#include <iostream>

using namespace std;

class Ad{
    private:
        string name;
        string message;
        int paid;
        float adTime;

    public:
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
        float getAdTime(){
            return adTime;
        }
        void setAdTime(float _time){
            adTime = _time;
        }
        ~Ad(){
            cout << "Calling destructor" << endl;
        }
};

#endif