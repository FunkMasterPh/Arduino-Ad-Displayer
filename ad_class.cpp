#include <iostream>
#include "ad_class.hpp"

using namespace std;

Ad::Ad(string _name, string _message, int _paid){
    name = _name;
    message = _message;
    paid = _paid;
}
string Ad::getMsg(){
    return message;
}

string Ad::getName(){
    return name;
}

int Ad::getPaid(){
    return paid;
}
float Ad::getAdTime(){
    return adTime;
}
void Ad::setAdTime(float _time){
    adTime = _time;
}
Ad::~Ad(){
}