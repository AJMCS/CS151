/* inventory.cpp - Manage an inventory of items
* Author: AJ McDaniel
* Module: 09
* Project: 01
* Problem statement: Create a program that manages an inventory of items stored in a binary file.
* Users can add new items and display existing items.
* 
* Algorithm:
* 1. Define a struct InventoryItem with fixed-size character arrays and numeric fields.
 * 2. Attempt to open inventory.dat in binary mode for both input and output.
 *    - If it doesn't exist, create it.
 * 3. Count the number of existing records in the file by dividing file size by struct size.
 * 4. Display a menu:
 *    - Option 1: Prompt user for item info with input validation. Append record to file.
 *    - Option 2: Ask for record number, seek to that record, read and display it.
 *    - Option 3: Exit the program.
 * 5. Ensure all numeric inputs are non-negative and handle invalid input gracefully.
 * 6. Loop until the user selects the option to quit.
 */

#include <iostream>
#include <fstream>
#include <string>
#include <iomanip>
#include <limits>

using namespace std;

// Constants for string field sizes to prevent buffer overflow
const int DESC_SIZE = 50;  // Maximum length for item description
const int DATE_SIZE = 11;  // Maximum length for date (MM/DD/YYYY format)

// Structure to store inventory information
struct InventoryItem {
    char description[DESC_SIZE];  
    int quantity;                 
    double wholesaleCost;         
    double salePrice;             
    char dateAdded[DATE_SIZE];    
};

// Function prototypes
void displayMenu();               
void addRecord(fstream&, int&);   
void displayRecord(fstream&, int); 

int main() {
    fstream inventoryFile;        
    int choice;                   
    int recordCount = 0;          

    // Open the file in binary mode for both reading and writing
    inventoryFile.open("inventory.dat", ios::in | ios::out | ios::binary);

    // If file doesn't exist, create it
    if (!inventoryFile) {
        inventoryFile.open("inventory.dat", ios::out | ios::binary);
        inventoryFile.close();
        inventoryFile.open("inventory.dat", ios::in | ios::out | ios::binary);
    } else {
        // If file exists, count existing records
        inventoryFile.seekg(0, ios::end);           // Move to end of file
        long fileSize = inventoryFile.tellg();      // Get file size
        recordCount = fileSize / sizeof(InventoryItem); // Calculate number of records
        inventoryFile.clear();                      // Clear any error flags
        inventoryFile.seekg(0, ios::beg);           // Return to beginning of file
    }

    // Main program loop
    do {
        displayMenu();
        if (!(cin >> choice)) {
            cin.clear();  // Clear error flags
            cin.ignore(numeric_limits<streamsize>::max(), '\n');  // Clear input buffer
            cout << "Invalid input. Please enter a number.\n";
            continue;
        }
        cin.ignore();

        // Process user's choice
        switch (choice) {
            case 1:
                addRecord(inventoryFile, recordCount);
                break;
            case 2:
                displayRecord(inventoryFile, recordCount);
                break;
            case 3:
                cout << "Exiting program...\n";
                break;
            default:
                cout << "Invalid choice. Please enter 1, 2, or 3.\n";
        }
    } while (choice != 3);

    inventoryFile.close();
    return 0;
}

// Displays the main menu options
void displayMenu() {
    cout << "\nInventory Management System\n";
    cout << "1. Add new record\n";
    cout << "2. Display record\n";
    cout << "3. Quit\n";
    cout << "Enter your choice: ";
}

// Adds a new record to the inventory file
void addRecord(fstream& file, int& recordCount) {
    InventoryItem item;
    
    // Get item description
    cout << "\nEnter item description (max " << DESC_SIZE - 1 << " characters): ";
    cin.getline(item.description, DESC_SIZE);
    
    // Get and validate quantity
    do {
        cout << "Enter quantity on hand: ";
        cin >> item.quantity;
        if (item.quantity < 0) {
            cout << "Quantity cannot be negative. Please try again.\n";
        }
    } while (item.quantity < 0);
    cin.ignore();
    
    // Get and validate wholesale cost
    do {
        cout << "Enter wholesale cost: $";
        cin >> item.wholesaleCost;
        if (item.wholesaleCost < 0) {
            cout << "Cost cannot be negative. Please try again.\n";
        }
    } while (item.wholesaleCost < 0);
    cin.ignore();
    
    // Get and validate sale price
    do {
        cout << "Enter sale price: $";
        cin >> item.salePrice;
        if (item.salePrice < 0) {
            cout << "Price cannot be negative. Please try again.\n";
        }
    } while (item.salePrice < 0);
    cin.ignore();
    
    // Get date added
    cout << "Enter date added (MM/DD/YYYY): ";
    cin.getline(item.dateAdded, DATE_SIZE);
    
    // Write the record to the end of the file
    file.seekp(0L, ios::end);
    file.write(reinterpret_cast<char*>(&item), sizeof(item));
    
    recordCount++;  // Increment the record counter
    cout << "Record #" << recordCount << " added successfully!\n";
}

// Displays a specific record from the inventory file
void displayRecord(fstream& file, int recordCount) {
    // Check if any records exist
    if (recordCount == 0) {
        cout << "\nNo records exist yet. Please add records first.\n";
        return;
    }
    
    int recordNumber;
    InventoryItem item;
    
    // Get and validate record number
    do {
        cout << "\nEnter record number to display (1-" << recordCount << "): ";
        cin >> recordNumber;
        if (recordNumber <= 0 || recordNumber > recordCount) {
            cout << "Invalid record number. Please enter a number between 1 and " << recordCount << ".\n";
        }
    } while (recordNumber <= 0 || recordNumber > recordCount);
    cin.ignore();
    
    // Calculate and move to the record position
    long position = (recordNumber - 1) * sizeof(item);
    file.seekg(position, ios::beg);
    
    // Read the record
    file.read(reinterpret_cast<char*>(&item), sizeof(item));
    file.clear();  // Clear any error flags
    
    // Display the record if found
    if (file) {
        cout << "\nRecord #" << recordNumber << ":\n";
        cout << "Description: " << item.description << endl;
        cout << "Quantity: " << item.quantity << endl;
        cout << fixed << setprecision(2);
        cout << "Wholesale Cost: $" << item.wholesaleCost << endl;
        cout << "Sale Price: $" << item.salePrice << endl;
        cout << "Date Added: " << item.dateAdded << endl;
    } else {
        cout << "Error reading record.\n";
    }
} 