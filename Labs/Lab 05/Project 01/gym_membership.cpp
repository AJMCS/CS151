/* gym_membership.cpp - A program that manages gym memberships, tracks visits, and prints a summary report
* Author: AJ McDaniel
* Lab: 5
* Project 01: Gym Membership
* Problem statement: This program simulates a gym's membership tracking system> It counts total number of visits 
and number of active members, assigning unique IDs to each member, etc.
* 
*
* Algorithm:
* 1. Define constants for BASIC_RATE and PREMIUM_RATE to store the monthly cost for each membership type.
* 2. Create a structure named Member to track each member's ID, name, membership type, and visit count.
*    - Include static variables inside the struct to track the last assigned ID, total visits across all members,
*      and the number of active members.
*    - In the constructor, assign the current last_id to the new member's ID, then increment last_id.
*      Also increment active_members and initialize visits to 0.
*    - In the destructor, decrement active_members.
* 3. Define the static member variables outside the struct and initialize:
*    - last_id to 10000, active_members and total_visits to 0.
* 4. Create a function named visit that:
*    - Takes a pointer to a Member object.
*    - Increments both the individual member's visits and the overall total_visits counter.
* 5. In the main function:
*    - Create a vector to store pointers to Member objects.
*    - Use the `new` keyword to create four members and store their pointers in the vector.
*    - Remove Charlie Sheen's membership by:
*        a. Deleting his object from memory.
*        b. Erasing his pointer from the vector.
*    - For each of the remaining members:
*        a. Generate a random number between 5 and 20.
*        b. Call the visit function that many times to simulate gym visits.
* 6. Print a formatted report that displays:
*    - Each member's ID, name, visit count, membership type (Basic or Premium), and the correct monthly rate.
*    - Align numeric columns to the right and display monetary values with two decimal places.
* 7. Print a summary that shows:
*    - The total number of visits to the gym.
*    - The number of active members (should be 3 after removing one).
* 8. Finally, free all dynamically allocated memory by deleting each remaining member pointer in the vector.
*/
#include <iostream>
#include <vector>
#include <string>
#include <iomanip>
#include <cstdlib>
#include <ctime>

using namespace std;

// Constants for membership rates
const double BASIC_RATE = 42.75,
             PREMIUM_RATE = 60.00;

// Member structure definition
struct Member {
    static int total_visits,    // all visits from members
               active_members,  // total members active in gym
               last_id;        // id assigned to newest member

    int id;         
    string name;    
    char type;      // rate (B = basic, P = premium)
    int visits;     

    Member(string name, char type) {
        this->name = name;
        this->type = type;
        visits = 0;
        active_members++;
        id = last_id++;
    }

    ~Member() {
        active_members--;
    }
};

// Define static variables
int Member::total_visits = 0;
int Member::active_members = 0;
int Member::last_id = 10000;

//Prototypes
void visit(Member* member);

int main() {
    // Seed random number generator
    srand(time(0));

    // Create vector of Member pointers
    vector<Member*> members;

    // Create and add members
    members.push_back(new Member("Oprah Winfrey", 'P'));
    members.push_back(new Member("Fluffy Iglesias", 'P'));
    members.push_back(new Member("Charlie Sheen", 'B'));
    members.push_back(new Member("Leona Helmsley", 'B'));

    // Remove Charlie Sheen's membership
    delete members[2];
    members.erase(members.begin() + 2);

    // Generate random visits for remaining members
    for (Member* member : members) {
        int visits = rand() % 16 + 5;  // Random number between 5 and 20
        for (int i = 0; i < visits; i++) {
            visit(member);
        }
    }

    // Print report header
    cout << "\nGym Membership Report:\n\n\n";
    cout << setw(8) << "ID" << "  " 
         << left << setw(20) << "Name" << "  "
         << right << setw(8) << "Visits" << "  "
         << left << setw(15) << "Type" << "  "
         << right << setw(15) << "Monthly Rate" << endl;
    cout << string(75, '-') << endl;

    // Print member details
    for (Member* member : members) {
        cout << setw(8) << member->id << "  "
             << left << setw(20) << member->name << "  "
             << right << setw(8) << member->visits << "  "
             << left << setw(15) << (member->type == 'P' ? "Premium" : "Basic") << "  "
             << right << setw(15) << fixed << setprecision(2) 
             << (member->type == 'P' ? PREMIUM_RATE : BASIC_RATE) << endl;
    }

    // Print summary
    cout << "\n\nSummary:\n\n";
    cout << "Total Visits: " << Member::total_visits << endl;
    cout << "Active Members: " << Member::active_members << endl;

    // Clean up memory
    for (Member* member : members) {
        delete member;
    }

    return 0;
} 

// Function to record a visit
void visit(Member* member) {
    member->visits++;
    Member::total_visits++;
}