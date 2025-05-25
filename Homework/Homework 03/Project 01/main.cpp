/* Name.cpp - description
* Author: AJ McDaniel
* Module: 3
* Project 01: Dynamnic Allocation of an Array
* Problem statement: Write a program which 
* dynamically allocates an array large enough 
* to hold a user-defined number of quiz or test scores.
* 
*
* Algorithm: 
* 1. Prompt the user to enter the number of students. Reject any non-positive input.
 * 2. Dynamically allocate an array of `Student` objects based on the number entered.
 * 3. For each student:
 *    a. Prompt for their name.
 *    b. Prompt for their score, validating that it is not negative.
 *    c. Store the name and score using setters on the object.
 * 4. Pass the array to a function that sorts the students by score using a basic bubble sort.
 * 5. Pass the array to another function to calculate and return the average score.
 * 6. Display the sorted student list with names and scores, and then print the average.
 * 7. Use the `delete` operator to deallocate the memory used for the student array.
*/

#include <iostream>
#include <string>
#include <iomanip>
using namespace std;

class Student {
private:
    string name;
    int score;

public:
    // Constructors
    Student() : name(""), score(0) {}
    Student(string n, int s) : name(n), score(s) {}

    // Getters
    string getName() const { return name; }
    int getScore() const { return score; }

    // Setters
    void setName(string n) { name = n; }
    void setScore(int s) { score = s; }
};

// Function to calculate average score
double calculateAverage(Student* students, int size) {
    double sum = 0;
    for (int i = 0; i < size; i++) {
        sum += students[i].getScore();
    }
    return sum / size;
}

// Function to sort students by score (ascending)
void sortStudents(Student* students, int size) {
    for (int i = 0; i < size - 1; i++) {
        for (int j = 0; j < size - i - 1; j++) {
            if (students[j].getScore() > students[j + 1].getScore()) {
                // Swap students
                Student temp = students[j];
                students[j] = students[j + 1];
                students[j + 1] = temp;
            }
        }
    }
}

int main() {
    int numStudents;
    
    // Get number of students
    cout << "Enter the number of students: ";
    cin >> numStudents;
    
    // Input validation for number of students
    while (numStudents <= 0) {
        cout << "Please enter a positive number of students: ";
        cin >> numStudents;
    }
    
    // Dynamically allocate array of Student objects
    Student* students = new Student[numStudents];
    
    // Get student information
    for (int i = 0; i < numStudents; i++) {
        string name;
        int score;
        
        cout << "\nEnter name for student " << (i + 1) << ": ";
        cin.ignore(); // Clear input buffer
        getline(cin, name);
        
        cout << "Enter score for " << name << ": ";
        cin >> score;
        
        // Input validation for score
        while (score < 0) {
            cout << "Score cannot be negative. Please enter a valid score: ";
            cin >> score;
        }
        
        students[i].setName(name);
        students[i].setScore(score);
    }
    
    // Sort students by score
    sortStudents(students, numStudents);
    
    // Calculate average
    double average = calculateAverage(students, numStudents);
    
    // Display results
    cout << "\nSorted Scores:" << endl;
    cout << setw(20) << left << "Name" << "Score" << endl;
    cout << string(30, '-') << endl;
    
    for (int i = 0; i < numStudents; i++) {
        cout << setw(20) << left << students[i].getName() 
             << students[i].getScore() << endl;
    }
    
    cout << string(30, '-') << endl;
    cout << fixed << setprecision(2);
    cout << "Average Score: " << average << endl;
    
    // Deallocate memory
    delete[] students;
    
    return 0;
} 