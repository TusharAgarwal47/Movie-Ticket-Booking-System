#pragma once
#include<string>
#include <iostream>
using namespace std;
class movie{
    private:
        string movie_name;
        string language;
        string duration;
    public:
    movie(string name , string language , string duration){
        this->movie_name=name;
        this->language=language;
        this->duration=duration;
    }
    void display(int srno){
        cout<<"["<<srno<<"] "<<movie_name<<"\t"<<language<<"\t"<<duration;
    }
    string getmovie_name(){
        return movie_name;
    }
    string getmovie_language(){
        return language;
    }
    string getmovie_duration(){
        return duration;
    }
};