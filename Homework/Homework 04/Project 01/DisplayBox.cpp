/* DisplayBox.cpp - Program to simulate placing stones in a display box and show placement statistics
* Author: AJ McDaniel
* Module: 4
* Project 01: The Display Box
* Problem statement: Create a program that simulates placing 10 stones (A-J) in a display box
* with 10 slots, tracking the number of attempts needed to find an empty slot for each stone.
*
* Algorithm:
* 1. Create Stone class to store stone letter, attempts, and original slot
* 2. Create array of unique pointers to Stone objects
* 3. For each stone (A-J):
*    a. Generate random slot numbers until finding an empty slot
*    b. Create new Stone object with letter, attempts, and slot number
*    c. Move Stone into the empty slot
* 4. Display report sorted by slot
* 5. Display report sorted by stone letter
*/
#include <iostream>
#include <iomanip>
#include <memory>
#include <ctime>

using namespace std;

class Stone
{
    private:
        //private variables
        char letter_of_stone;
        int number_of_attempts;
        int original_slot;

    public:
        //constructor
        Stone(char letter, int attempts, int slot)
        {
            letter_of_stone = letter;
            number_of_attempts = attempts;
            original_slot = slot;
        }

        //getters
        char get_letter() const
        {
            return letter_of_stone;
        }

        int get_attempts() const
        {
            return number_of_attempts;
        }

        int get_slot() const
        {
            return original_slot;
        }

        //setters
        void set_letter(char letter)
        {
            letter_of_stone = letter;
        }

        void set_attempts(int attempts)
        {
            number_of_attempts = attempts;
        }

        void set_slot(int slot)
        {
            original_slot = slot;
        }
};

int main()
{
    srand(time(NULL));
    
    // Create array of 10 unique pointers to Stone objects
    unique_ptr<Stone> slots[10];
    
    // Process each stone (A through J)
    //Works because the corresponding ASCII values are in sequentialorder
    for (char stone_letter = 'A'; stone_letter <= 'J'; stone_letter++) {
        int attempts = 0;
        bool placed = false;
        
        // Keep trying until we find an empty slot
        while (!placed) {
            attempts++;
            int index = rand() % 10;
            
            // Check if slot is available
            if (!slots[index]) {
                // Create new stone and move it into the slot
                unique_ptr<Stone> new_stone(new Stone(stone_letter, attempts, index));
                slots[index] = move(new_stone);
                placed = true;
            }
        }
    }
    
    // Print the report sorted by slot
    cout << "Report sorted by slot:" << endl;
    cout << "Slot  Stone  Attempts" << endl;
    cout << "----  -----  --------" << endl;
    
    int total_attempts = 0;
    
    // Display report sorted by slot
    for (int i = 0; i < 10; i++) {
        cout << setw(4) << i << "     " 
             << slots[i]->get_letter() << "      "
             << setw(3) << slots[i]->get_attempts() << endl;
        total_attempts += slots[i]->get_attempts();
    }
    
    cout << "\nTotal Attempts: " << total_attempts << endl << endl;
    
    // Print the report sorted by stone letter
    cout << "Report sorted by stone letter:" << endl;
    cout << "Stone  Slot  Attempts" << endl;
    cout << "-----  ----  --------" << endl;
    
    int total_attempts_letter = 0;
    
    // For each stone letter (A through J)
    for (char stone_letter = 'A'; stone_letter <= 'J'; stone_letter++) {
        // Find the stone with this letter
        for (int i = 0; i < 10; i++) {
            if (slots[i]->get_letter() == stone_letter) {
                cout << "  " << stone_letter << "     "
                     << setw(2) << slots[i]->get_slot() << "      "
                     << setw(3) << slots[i]->get_attempts() << endl;
                total_attempts_letter += slots[i]->get_attempts();
                break;
            }
        }
    }
    
    // Display total attempts
    cout << "\nTotal Attempts: " << total_attempts_letter << endl;
    
    return 0;
}