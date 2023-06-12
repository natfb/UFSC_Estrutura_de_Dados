#ifndef SERIES_HPP
#define SERIES_HPP

#include "movie.hpp"
#include "avaliation.hpp"

using namespace std;

class Series : public Movie
{
    private:
        string type = "Series";
        int seasons;
        int episodes;
        AvaliationEp *AvaliationEpisode = NULL;    

    public:
        int c = 0;

        Series(string name, string genre, string director, int seasons, int episodes) : Movie(name, genre, director), seasons(seasons), episodes(episodes){};
        
        Series(string name, string genre, string director, int seasons, int episodes, int star, string comments) : 
        Movie(name, genre, director, star, comments), seasons(seasons), episodes(episodes){};
        
        void AvaliateEpisode(int s, int ep, int stars, string comment) {
            AvaliationEp* episodeAvaliation = new AvaliationEp(s, ep, stars, comment);
            
            if (AvaliationEpisode == nullptr) {
                AvaliationEpisode = new AvaliationEp[sizeof(AvaliationEp)];
            }
            AvaliationEpisode[c] = *episodeAvaliation;
            c++;
        }

        void getInfo() {
            
            cout << "Seasons: " << seasons << " ||| ";
            cout << "Episodes: " << episodes << endl;
            Movie::getInfo();
            cout << endl;
            cout << "Avaliation Episode of Single Episodes: " << endl;
            for(int i = 0; i < c; i++){
                AvaliationEpisode[i].getInfo();
            }
            if (c == 0) {
                cout << "No avaliations yet." << endl;
            }
            cout << endl;
            
        }

        ~Series() {
            delete AvaliationEpisode;
        }	
};

#endif