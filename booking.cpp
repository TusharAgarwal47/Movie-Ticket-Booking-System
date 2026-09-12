#pragma once
#include <iostream>
#include <vector>
#include <string>
#include "Customer.cpp"
#include "Show.cpp"
#include "showseat.cpp"

using namespace std;
class Booking
{
private:
    inline static int nextBookingId = 1001;

    string bookingId;
    customer* Customer;
    show* Show;
    vector<showseat*> seats;
    double totalAmount;
    string status;

public:
    Booking(customer &customer,show& show,vector<showseat*>& seats,double totalAmount)
    {
        this->bookingId = "BK" + to_string(nextBookingId++);
        this->Customer = &customer;
        this->Show = &show;
        this->seats = seats;
        this->totalAmount = totalAmount;
        this->status = "PENDING";
    }
    string getBookingId()
    {
        return bookingId;
    }
    customer* getCustomer()
    {
        return Customer;
    }
    show* getShow()
    {
        return Show;
    }
    vector<showseat*>& getSeats()
    {
        return seats;
    }
    double getTotalAmount()
    {
        return totalAmount;
    }
    string getStatus()
    {
        return status;
    }
    void confirmBooking()
    {
        status = "CONFIRMED";
    }
    void cancelBooking()
    {
        status = "CANCELLED";
    }
};
