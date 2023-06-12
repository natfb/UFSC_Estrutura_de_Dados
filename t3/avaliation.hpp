#ifndef AVALIATION_HPP
#define AVALIATION_HPP

#include <iostream>

using namespace std;

class Avaliation 
{
    protected:
        int stars = 0;
        string *comment = NULL;
        
    public:    
        Avaliation() {};
        Avaliation(int star, const string& comments) : stars(star) 
        {
            comment = new string(comments); 
        }
        
        void getInfo(){
            cout << "stars:" ;
            for(int i = 0; i < stars; i++){
                cout << "* ";
            }
            cout << "(" << stars << ")" << endl;
            cout << "Comment: " << *comment << endl;
        }

        void setInfo(int star, string comments){

            stars = star;

            if(comments.empty() ){
                comment = new string("(0) comentarios");
            }else{
                comment = new string(comments);
            }
            
        }
        ~Avaliation() {
            delete comment; 
        }
};

class AvaliationEp : public Avaliation
{
    private:
        int season;
        int episode;

     public:   
        AvaliationEp() {};
        AvaliationEp(int season, int episode, int stars, string comment) :
        season(season), episode(episode), Avaliation::Avaliation(stars, comment) {};
        
        void setInfo(int seas, int epi, int star, string comments)
        {
            season = seas;
            episode = epi;
            Avaliation::setInfo(star, comments);
        }    
        void getInfo(){
            cout << "Season: " << season << " ";
            cout << "Episode: " << episode << endl;
            Avaliation::getInfo();
        } 
};

#endif