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
        Ad(string _name, string _message, float _paid);

        string getMsg();

        string getName();
        
        float getPaid();

        float getAdTime();

        void setAdTime(float _time);

        ~Ad();
};

#endif