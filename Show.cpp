#pragma once
#include "Movie.cpp"
#include "Seat.cpp"
#include "Screen.cpp"
#include "showseat.cpp"
using namespace std;
class show{
    private:
    movie *Movie;
    screen *Screen;
    string time;
    vector<showseat> showSeat;

    public:
    show(movie &Movie , screen &Screen , string time){
        this->Movie=&Movie;
        this->Screen=&Screen;
        this->time=time;
    }
    void create_show(){
        for(seat &seat: Screen->get_seat()){
            showseat ShowCase(seat);
            showSeat.push_back(ShowCase);
        }
    }
    movie *get_movie(){
        return Movie;
    }
    screen *get_Screen(){
        return Screen;
    }
    string get_time(){
        return time;
    }
     vector<showseat> &get_showSeat(){
        return showSeat;
     }
};