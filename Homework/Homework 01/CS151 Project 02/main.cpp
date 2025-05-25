/*
This program creates planet objects and inserts them into a vector, then displays in order of distance to the sun.
Author: AJ McDaniel
*/
#include <iostream>
#include <iomanip>
#include <vector>
#include "Planet.h"

using namespace std;

//Call printPlanets method.
void printPlanets(const vector<Planet>& planets);


int main() {
	
    //Ordered by names 
	string planetNames[] = {"Ceres",
        "Earth","Eris","Haumea",
        "Jupiter","Makemake","Mars",
        "Mercury","Neptune","Pluto",
        "Saturn","Uranus","Venus"};
        
        //Ordered Diameters
        long long planetDiameters[] = {952,
        12756,2321,1220,
        142796,1475,6787,
        4878,48600,2302,
        120660,51118,12104};
        
        //Ordered Distances
        long long planetDistances[] = {413700000LL,
        149600000LL,10125000000LL,6452000000LL,
        778300000LL,6850000000LL,227900000LL,
        57900000LL,4497000000LL,5891000000LL,
        1427000000LL, 2831000000LL, 108200000LL};

    //Initialize vector
	vector<Planet> planets;

    //For every planet that needs to be created and inserted
	for(int i = 0; i < sizeof(planetNames) / sizeof(planetNames[0]); i++) {
		
		//Create a planet object and iterator
		vector<Planet>::iterator iter = planets.begin();
		Planet newPlanet = Planet(planetNames[i], planetDistances[i], planetDiameters[i]);
		
		//As long as you havent reached the end of the vector and distance of what is in the vector is less than the new planet created
		//keep iterating
		while(iter != planets.end() && (*iter).getDistance() < newPlanet.getDistance()){
			++iter;
		}
		//Once conditions have been met, insert the planet at that position in the vector.
		planets.insert(iter, newPlanet);
	}

    //calls the function to print the planets
    printPlanets(planets);
    return 0;
}

void printPlanets(const vector<Planet>& planets) {
    //Print the headers of each column
	cout << left << setw(12) << "Planet" 
     << right << setw(12) << "Diameter" 
     << setw(18) << "Dist. from Sun" << endl;
	cout << string(42, '-') << endl;
	
    //Initialize total variables
    long long totalDiameter = 0;
    long long totalDistance = 0;

    //Loop through the vector and display the member variables of each planet object.
	for(Planet planet : planets) {
    	cout << left << setw(12) << planet.getName()
         << right << setw(12) << planet.getDiameter()
         << setw(18) << planet.getDistance() << endl;
        
        //Add to totals
        totalDiameter += planet.getDiameter();
        totalDistance += planet.getDistance();
	}

    //Print a line to separate totals
    cout << string(42, '-') << endl;
    
    //Print totals row
    cout << left << setw(12) << "Totals:"
         << right << setw(12) << totalDiameter
         << setw(18) << totalDistance << endl;
};


