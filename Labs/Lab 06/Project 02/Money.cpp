/* Money.cpp - Represents money using separate variables for dollars and cents
 * Author: Chris Merrill
 * Altered by: AJ McDaniel
 * Module: 6
 * Project: 2
 * Description:
 *   Uses two variables, one (long long) representing dollars and a
 *      second (an int) representing cents.  The cents should always be
 *      between 0 and 99.
 */

#include <string>
#include <iostream>
using namespace std;

class Money {
private:
    long long dollars = 0;
    int cents = 0;                  // should be between 0 and 99

public:
    // constructor takes a String representing dollars and cents and
    // divides into a "dollars" and "cents" variables
    Money(string amount) {
        int index = amount.find(".");
        if (index == -1) {                   // no decimal point
            dollars = stol(amount);
            cents = 0;
        } else {
            if (index == 0) {                 // no dollars
                amount = "0" + amount;
                index++;
            }
            dollars = stol(amount.substr(0, index));
            cents = stoi(amount.substr(index + 1, amount.length()));
        }
        cout << "In the constructor of $" << amount << endl;
    }

    // Copy constructor (prints a message)
    Money(const Money &amount) {
        dollars = amount.dollars;
        cents = amount.cents;
        cout << "In the " << amount << " copy constructor" << endl;
    }

    // Move constructor (prints a message)
    Money(Money &&amount) {
        dollars = amount.dollars;
        cents = amount.cents;
        cout << "In the " << amount << " move constructor" << endl;
    }

    // Assignment operator
    Money operator=(const Money &amount) {
        dollars = amount.dollars;
        cents = amount.cents;
        cout << "In the " << amount << " assignment operator" << endl;
        return *this;
    }

    // Returns the money amount as a string
    string getAmount() const {
        string zero = (cents <= 9 ? "0" : "");
        return to_string(dollars) + "." + zero + to_string(cents);
    }

    // Addition operator
    Money operator+(const Money &right) const {
        long long totalDollars = dollars + right.dollars;
        int totalCents = cents + right.cents;
        
        if (totalCents > 99) {
            totalDollars += 1;
            totalCents -= 100;
        }
        
        return Money(to_string(totalDollars) + "." + to_string(totalCents));
    }

    // Greater than or equal operator
    bool operator>=(const Money &right) const {
        long long leftTotal = dollars * 100 + cents;
        long long rightTotal = right.dollars * 100 + right.cents;
        return leftTotal >= rightTotal;
    }

    // Friend function for stream output
    friend ostream& operator<<(ostream &out, const Money &amount) {
        out << "$" << amount.dollars << "." 
            << (amount.cents <= 9 ? "0" : "") << amount.cents;
        return out;
    }
};

// Function prototype for testing move constructor
Money testMove(Money);

int main() {
    // Create Money objects
    Money m1("4.90");
    Money m2("1.27");
    Money m3("5.24");
    Money m4("0.99");

    // Add first and second Money objects
    Money sum1 = m1 + m2;
    cout << m1 << " + " << m2 << " = " << sum1 << endl;

    // Add third and fourth Money objects
    Money sum2 = m3 + m4;
    cout << m3 << " + " << m4 << " = " << sum2 << endl;

    // Compare the two sums
    if (sum1 >= sum2) {
        cout << "Larger amount: " << sum1 << endl;
    } else {
        cout << "Larger amount: " << sum2 << endl;
    }

    // Reassign first Money object and recalculate sum
    m1 = Money("5.00");
    sum1 = m1 + m2;
    cout << m1 << " + " << m2 << " = " << sum1 << endl;

    // Compare the sums again
    if (sum1 >= sum2) {
        cout << "Larger amount: " << sum1 << endl;
    } else {
        cout << "Larger amount: " << sum2 << endl;
    }

    // Test move constructor
    Money returned = testMove(Money("8.36"));
    cout << "Returned: " << returned << endl;

    return 0;
}

// Function to test move constructor
Money testMove(Money in) {
    return in;
}

