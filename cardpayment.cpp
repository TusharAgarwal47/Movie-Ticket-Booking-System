#pragma once
#include<iostream>
#include "payment.cpp"
using namespace std;
class cardpayment : public payment{
    public:
    bool pay(double amount) override {
        int choice;
        cout<<"Total Amount: "<<amount<<endl;
        cout<<"Proceed with Card Payment?."<<endl;
        cout<<"1. Yes"<<endl;
        cout<<"2. No"<<endl;
        cout<<"Enter Your Choice"<<endl;
        cin>>choice;

        if(choice==1){
            cout<<"Card Payment Succesfull!! "<<endl;
            return true;
        }
        else{
            cout<<"Card Payment Failed!! "<<endl;
            return false;
        }
    }
};