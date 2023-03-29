#include <iostream>
#include <fstream>
#include <vector>
#include <string>
#include <utility>

using namespace std;

bool Readfile(string path, string &content);

//count frequency
bool countFreq(string content, vector<pair<int, char>> &ocurrances);

int main(){

    string filename("manuscript2.txt");

    string fileContent;


    vector< pair <int, char> > ocurrances;

    if (Readfile(filename, fileContent)){
        cout << "file was read." << endl;
        cout << fileContent;

        countFreq(fileContent, ocurrances);


    } else {
         cout << "file was not read." << endl;
    }

    return 0;
}

bool Readfile(string path, string &content){

    ifstream filereader( path.c_str() );

    if ( !filereader.is_open() )
        return false;

    string tmp;
    while (getline(filereader, tmp)){
        content += tmp;
    }

    return true;
}

// contar a frequencia de cada caracter
bool countFreq(string content, vector<pair<int, char>> &ocurrances){

    int c = 0;
    vector <int> ascii;

    for(int i = 0; i < 228; i++){
        ascii.push_back(i);
    }
    ocurrances = {};
    for (int i = 0; i < content.length(); i++){
        for(int j = 0; j < 228; j++){
            if(content[i] == ascii[j]){
                cout << "aqui";
                char ch = j;
                cout << "aqui 2" << ch << "," << j;
                ocurrances[c].first = j;
                cout << "aqui 2.5" << ch << "," << j;
                ocurrances[c].second = ch;
                cout << "aqui 3";
                c++;
            }
        }
    }
}
