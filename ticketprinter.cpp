#pragma once
#include <iostream>
#include <vector>
#include <string>
#include "booking.cpp"
#include "Movie.cpp"
using namespace std;
class TicketPrinter
{
public:
    void printTicket(Booking& booking)
    {
        cout << "\n";
        cout << "========================================\n";
        cout << "              MOVIE TICKET              \n";
        cout << "========================================\n";
        cout << "Booking ID : " << booking.getBookingId() << endl;
        cout << "Customer   : "<< booking.getCustomer()->get_name() << endl;
        cout << "Movie      : "<< booking.getShow()->get_movie()->getmovie_name() << endl;
        cout << "Screen     : "<< booking.getShow()->get_Screen()->get_Screen_Num() << endl;
        cout << "Time       : -"<< booking.getShow()->get_time() << endl;
        cout << "\nSeats:\n";
        for (showseat* showSeat : booking.getSeats())
        {
            cout << "  "<< showSeat->getSeat()->get_seatnum()<< " - "<< showSeat->getSeat()->get_seattype()<< endl;
        }
        cout << "\nTotal      : Rs. "<< booking.getTotalAmount() << endl;
        cout << "Status     : "<< booking.getStatus() << endl;

        cout << "========================================\n";
        cout << "          Thank you for booking!        \n";
        cout << "========================================\n";
    }
};
