#pragma once
#include<iostream>
#include "payment.cpp"
using namespace std;
class upipayment : public payment{
    public:
    bool pay(double amount) override {
        int choice;
        cout<<"Total Amount: "<<amount<<endl;
        cout<<"Proceed with UPI Payment?."<<endl;
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