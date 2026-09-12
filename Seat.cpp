#pragma once
#include<iostream>
using namespace std;
class seat{
    private:
    string seat_num;
    string seat_type;
    public:
    seat(string num , string type){
        this->seat_num=num;
        this->seat_type=type;
    }
    string get_seattype(){
        return seat_type;
    }
    string get_seatnum(){
        return seat_num;
    }
};