#pragma once
#include<iostream>
#include "Seat.cpp"
using namespace std;
class showseat{
    private:
    string status;
    seat *Seat;
    public:
    showseat(seat &seat) {
        this->Seat=&seat;
        this->status = "AVAILABLE";
    }

    seat* getSeat() {
        return Seat;
    }

    string getStatus() {
        return status;
    }

    void book() {
        status = "BOOKED";
    }

    void release() {
        status = "AVAILABLE";
    }

    bool isAvailable() {
        return status == "AVAILABLE";
    }
};