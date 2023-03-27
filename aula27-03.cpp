#include <iostream>
#include <fstream>

using namespace std;

bool Readfile(string path, string &content);

int main(){

    string filename("manuscript2.txt");

    string fileContent;

    if (Readfile(filename, fileContent)){
        cout << "file was read." << endl;
        cout << fileContent;

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
