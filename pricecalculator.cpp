#pragma once
#include "showseat.cpp"
class pricecalculator{
    public:
    double calculatetotal(vector<showseat*> &seat){
        double total=0;
        for(showseat* & ShowSeat : seat){
            string type=ShowSeat->getSeat()->get_seattype();
            if(type=="SILVER"){
                total+=150;
            }
            else if (type=="GOLD"){
                total+=250;
            }
            else if(type=="PLATINUM"){
                total+=400;
            }
        }
        return total;

    }
};