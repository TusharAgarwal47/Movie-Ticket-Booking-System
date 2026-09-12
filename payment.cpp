#pragma once
class payment{
    public:
    virtual bool pay(double amount)=0;
    virtual ~payment(){}
};