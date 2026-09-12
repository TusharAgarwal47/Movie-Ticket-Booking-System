#pragma once
#include "Seat.cpp"
#include<iostream>
using namespace std;
class screen{
    private:
    string screen_num;
    vector<seat> seats;
    public:
    screen(string screen_num){
        this->screen_num=screen_num;
    }
    string get_Screen_Num(){
        return screen_num;
    }
    void add_seat(seat seat){
        seats.push_back(seat);
    }
    vector<seat> &get_seat(){
        return seats;
    }
};