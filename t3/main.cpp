#include "series.hpp"
#include "documentary.hpp"
#include <vector>

int main() {

    //add media
    vector <Movie*> mediaList;
    mediaList.push_back(new Series("The Office", "Comedy", "Greg Daniels", 9, 24));
    mediaList.push_back(new Series("Sucession", "Drama", "jesse", 4, 40, 5, "one of the best shows ever"));
    mediaList.push_back(new Movie("SpiderMan", "Drama", "jesse"));
    mediaList.push_back(new Documentary("Cosmos", "documentary", "jesse", "space"));
    Series theOffice("The Office", "Comedy", "Greg Daniels", 9, 24);
    Series Friends("Friends", "Comedy", "David Crane", 10, 24);
    
    //add avaliation separately  
    mediaList.at(0)->Avaliate(3, "good");
    
    //downcast and add avaliation
    Series* series = dynamic_cast<Series*>(mediaList.at(0));
    if (series) {
        series->AvaliateEpisode(3, 22, 4, "Best Episode");
    }
    
    theOffice.AvaliateEpisode(4, 2, 2, "kind disapointing");
    //add avaliation movie

    //print all informaion
    for(int i = 0; i < mediaList.size(); i++){
        cout << "----------------------------------------" << endl;
        mediaList.at(i)->getInfo();
        cout << "----------------------------------------" << endl;
    }
    theOffice.getInfo();
    Friends.getInfo();


    // Clearing the vector
    for (Movie* movie : mediaList) {
        delete movie;
    }

    // Clearing the vector
    mediaList.clear();

    return 0;
}