/*
This program generates 30 random numbers between 1 and 10 and then displays them to the console in ascending order.
Author: AJ McDaniel
*/

#include <vector>
#include <cstdlib>
#include <ctime>
#include <iostream>


using namespace std;

int main(){
    //initialize int vector and random seed
    vector<int> init_vector;
    srand(time(0)); 

    //For loop for generating 30 integer values
    for(int i = 0; i < 30; i++)
    {
        //generate randum int value and modulo it to between the values of 1 and 10
        int randNum = (rand() % 10) + 1;

        //initialize iterator
        vector<int>::iterator it = init_vector.begin();

        //insertion logic for the random number so that it exists in descending order
        while(it != init_vector.end() && *it > randNum) {
            it++;
        }
        //Once the condition is met, insrt the random number into the vector at the index of our iterator
        init_vector.insert(it, randNum);
    }
    //display size of it to verify it's length of 30
    cout << "vector size: " << init_vector.size() << endl;
    
    //print the vector using pop_back function so it displays to the user in ascending order.
    while(!init_vector.empty()){
        cout << init_vector.back() << " ";
        init_vector.pop_back();
    }
    
    return 0;
}