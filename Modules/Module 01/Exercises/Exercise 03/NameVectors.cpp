#include <iostream>
#include <iomanip>
#include <vector>

using namespace std;

int main(){
    
    vector<char> name_vector;
    string myName = "AJ McDaniel";
    
    for(int i = myName.length() - 1; i >= 0; i--){
        name_vector.push_back(myName.at(i));
    }

    cout << "My name is ";
    while(!name_vector.empty()){
        cout << name_vector.back();
        name_vector.pop_back();
    }
    cout << "." << endl;

    return 0;
}