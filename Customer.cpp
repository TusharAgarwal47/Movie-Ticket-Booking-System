#pragma once
#include<iostream>
using namespace std;
class customer{
    private:
    string name;
    string phone_num;
    public:
    customer(string num , string phone){
        this->name=num;
        this->phone_num=phone;
    }
    void display(){
        cout<<"Name:"<<name<<"\n";
        cout<<"Phone Number:"<<phone_num<<"\n";
    }
    string get_name(){
        return name;
    }
    string get_phone(){
        return phone_num;
    }
};