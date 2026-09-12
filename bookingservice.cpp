#pragma once
#include <iostream>
#include <vector>
#include <string>
#include "booking.cpp"
#include "pricecalculator.cpp"
#include "payment.cpp"
#include "ticketprinter.cpp"
#include "Show.cpp"
#include "showseat.cpp"
#include "Customer.cpp"
using namespace std;
class BookingService
{
public:
    Booking* bookTicket(customer& customer,show& show,vector<showseat*>& selectedSeats,payment& payment)
    {
        for (showseat* seat : selectedSeats)
        {
            if (!seat->isAvailable())
            {
                cout << "Seat "<< seat->getSeat()->get_seatnum()<< " is already booked.\n";
                return nullptr;
            }
        }
        pricecalculator calculator;
        double totalAmount=calculator.calculatetotal(selectedSeats);
        cout << "\nTotal Amount: Rs. "<< totalAmount << endl;
        Booking* booking =new Booking(customer,show,selectedSeats,totalAmount );
        bool paymentSuccessful=payment.pay(totalAmount);
        if (!paymentSuccessful)
        {
            cout << "Payment failed.\n";
            cout << "Booking has NOT been confirmed.\n";
            delete booking;
            return nullptr;
        }
        for (showseat* seat : selectedSeats)
        {
            seat->book();
        }
        booking->confirmBooking();
        cout << "\nBooking confirmed successfully!\n";
        TicketPrinter printer;
        printer.printTicket(*booking);
        return booking;
    }
};
