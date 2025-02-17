#include <vector>
#include <cstdlib>
#include <ctime>
#include <iostream>


using namespace std;

int main(){
    vector<int> init_vector;

    srand(time(NULL)); 

    for(int i = 0; i < 30; i++)
    {
        int randNum = rand() % (RAND_MAX + 1);
        int randNum = (randNum % 10) + 1;

        if(init_vector.empty()){
            init_vector.push_back(randNum);
        }
        else if (randNum > init_vector.at(i)) {
            init_vector.insert(init_vector.begin() + i-1, randNum);
        }
        else{
            init_vector.insert(init_vector.end(), randNum);
        }
    }

    while(!init_vector.empty()){
        cout << init_vector.back();
        init_vector.pop_back();
    }

}