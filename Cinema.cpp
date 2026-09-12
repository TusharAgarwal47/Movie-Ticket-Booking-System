#pragma once
#include "Screen.cpp"
#include<iostream>
#include<vector>
using namespace std;
class cinema{
    private:
    string cinema_name;
    vector<screen> screens;
    public:
    cinema(string name){
        this->cinema_name=name;
    }
    string get_cinema_name(){
        return cinema_name;
    }
    void add_screen(screen screen){
        screens.push_back(screen);
    }
    vector<screen> get_screen(){
        return screens;
    }
};