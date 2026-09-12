#pragma once
#include <iostream>
#include "payment.cpp"
using namespace std;
class CashPayment : public payment {
public:
    bool pay(double amount) override {
        int choice;
        cout << "Please pay Rs. " << amount << " at the counter." << endl;
        cout << "Booking will be confirmed after payment at the counter." << endl;
        cout<<"Did you pay the amount?"<<endl;
        cout<<"1. Yes"<<endl;
        cout<<"2. No"<<endl;
        cout<<"Enter Your Choice"<<endl;
        cin>>choice;

        if(choice==1){
            cout<<"Payment Succesfull!! "<<endl;
            return true;
        }
        else{
            cout<<"Payment Failed!! "<<endl;
            return false;
        }
    }
};