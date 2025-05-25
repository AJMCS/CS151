/* main.cpp - Simulates and analyzes a game of Nim using recursion to find a winning strategy.
* Author: AJ McDaniel
* Module: 11
* Project 04: Winning a game of Nim
* Problem statement: This program simulates the game of Nim.
* 
*
* Algorithm:
* 1. Use a recursive function canWin(n):
 *    - Base cases: return false for 1, true for 2 and 3.
 *    - Recursive case: try taking 1 or 2 sticks and force the opponent into a losing state.
 * 2. Analyze which values of n let Player 1 force a win, from n = 3 to n = 20.
 */

#include <iostream>
using namespace std;

//Prototypes
bool canWin(int n);

int main() {
    // Analyze games from 3 to 20 sticks
    cout << "Analyzing Nim games from 3 to 20 sticks:" << endl;
    cout << "n\tFirst player can force win?" << endl;
    cout << "------------------------------" << endl;
    
    for (int n = 3; n <= 20; n++) {
        bool result = canWin(n);
        cout << n << "\t" << (result ? "Yes" : "No") << endl;
    }
    
    return 0;
} 

bool canWin(int n) {
    // Base cases
    if (n == 1) return false;  // Current player loses
    if (n == 2 || n == 3) return true;  // Current player can win
    
    // Recursive case: Try both possible moves
    return !canWin(n-1) || !canWin(n-2);
}