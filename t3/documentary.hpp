#ifndef tv_HPP
#define tv_HPP

#include "movie.hpp"
#include "avaliation.hpp"


class Documentary : public Movie
{
    private:
        string Subject;
    
    public:
        Documentary(string name, string genre, string director, string subject) : Movie(name, genre, director), Subject(subject) {};

        void getInfo(){
            //cout << "----------------------------------------" << endl;
            cout << "Subject: " << Subject << endl;
            Movie::getInfo();
            cout << endl;
            //cout << "----------------------------------------" << endl << endl;
        }       
};

#endif