#ifndef MOVIE_HPP
#define MOVIE_HPP

#include <iostream>
#include "avaliation.hpp"

using namespace std;

class Movie
{
    private:
        string name;
        string genre;
        string director;
        Avaliation avaliationn;
    
    public:
    
    Movie(string name, string genre, string director) : name(name), genre(genre), director(director) {
        avaliationn.setInfo(0, "(0) comments");
    };
    
    Movie(string name, string genre, string director, int star, string comment) : name(name), genre(genre), director(director), avaliationn(star, comment) {};
    
    virtual void Avaliate(int stars, string comment) { 
        avaliationn.setInfo(stars, comment);  
    }

    virtual void getInfo(){
        cout << "name: " << name << endl;
        cout << "genre: " << genre << endl;
        cout << "director: " << director << endl;
        avaliationn.getInfo();
    }
};

#endif