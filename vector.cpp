#include <vector>
#include <iostream>

using namespace std;

int main(){

    vector <int> myVector;

    myVector.push_back(1);
    myVector.push_back(436);

    for(size_t i = 0; i < myVector.size(); i++){
        cout << myVector.at(i) << endl;
    }

    return 0;
}
