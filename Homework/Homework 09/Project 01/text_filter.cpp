/* text_filter.cpp - Filter text to make it more readable
* Author: AJ McDaniel
* Module: 09
* Project: 01
* Problem statement: Filter text to make it more readable.
* 
* Algorthim:
* 1. Prompt the user for input and output file names.
 * 2. Open the input file for reading and the output file for writing.
 * 3. Read characters from the input file one by one, tracking:
 *    - The previous character
 *    - The current character
 *    - The next character
 * 4. Capitalize:
 *    - The first character
 *    - Any letter following a period '.'
 *    - A standalone i surrounded by whitespace or punctuation
 * 5. Use tolower() to convert other alphabetic characters.
 * 6. Write each processed character to the output file.
 * 7. Close the file streams at the end.
 */


#include <iostream>
#include <fstream>
#include <cctype>
#include <string>

using namespace std;

void processText(const string& inputFile, const string& outputFile);

int main() {
    // Declare variables
    string inputFile, outputFile;
    // Get the input and output filenames from the user
    cout << "Enter the input filename: ";
    cin >> inputFile;
    
    cout << "Enter the output filename: ";
    cin >> outputFile;
    
    // Process the text
    processText(inputFile, outputFile);
    cout << "File processed successfully. Output written to " << outputFile << endl;
    
    return 0;
} 

void processText(const string& inputFile, const string& outputFile) {
    ifstream infile(inputFile);
    ofstream outfile(outputFile);
    
    if (!infile.is_open() || !outfile.is_open()) {
        cout << "Error opening files." << endl;
        return;
    }
    
    char ch;
    char prevCh = ' ';
    char nextCh;
    bool capitalizeNext = true;  // Start with true to capitalize first character
    
    // Read first character
    infile.get(ch);
    if (!infile) return;  // Empty file
    
    // Read second character
    infile.get(nextCh);
    
    while (infile) {
        // Handle current character
        if (capitalizeNext && isalpha(ch)) {
            outfile << static_cast<char>(toupper(ch));
            capitalizeNext = false;
        } else if (ch == 'i' || ch == 'I') {
            // Check if it's a standalone 'i'
            bool isStandalone = (isspace(prevCh) || prevCh == '\n' || prevCh == '"' || prevCh == '(') && 
                              (isspace(nextCh) || nextCh == '\n' || nextCh == ',' || nextCh == '.' || 
                               nextCh == '!' || nextCh == '?' || nextCh == '"' || nextCh == ')');
            if (isStandalone) {
                outfile << 'I';
            } else {
                outfile << static_cast<char>(tolower(ch));
            }
        } else {
            outfile << static_cast<char>(tolower(ch));
        }
        
        // Update capitalizeNext flag
        if (ch == '.') {
            capitalizeNext = true;
        }
        
        // Move to next character
        prevCh = ch;
        ch = nextCh;
        infile.get(nextCh);
    }
    
    // Handle last character
    if (capitalizeNext && isalpha(ch)) {
        outfile << static_cast<char>(toupper(ch));
    } else if ((ch == 'i' || ch == 'I') && (isspace(prevCh) || prevCh == '\n' || prevCh == '"' || prevCh == '(')) {
        outfile << 'I';
    } else {
        outfile << static_cast<char>(tolower(ch));
    }
    
    // Close the input and output files
    infile.close();
    outfile.close();
}