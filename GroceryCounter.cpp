#include <iostream>
#include <fstream>
#include <string>
#include <algorithm>
#include <map> // for map
#include <cstdlib> // for system("pause") and system("cls")
#include "GroceryManager.h"

using namespace std;

int main() {
    int choice;

    GroceryManager manager; //Object manager

    do {
        manager.AutoBackup(); //Auto backup, creates new backup file
        cout << "Corner Grocery Search Menu\n";
        cout << "1. Item Search\n";
        cout << "2. Total Items (Count)\n";
        cout << "3. Total Items (Tally)\n";
        cout << "4. Quit\n";
        cout << "Enter your selection (1-4, 0 to exit): ";

        while (!(cin >> choice) || choice < 0 || choice > 4) { // Input validation
            cout << "Invalid choice. Please enter a number between 0 and 4.\n";
            cin.clear(); // Clear the error state
            cin.ignore(numeric_limits<streamsize>::max(), '\n'); // Discard invalid input
        }

        switch (choice) { //Main menu switch
        case 1:
            system("cls"); // Clear screen
            manager.ItemSearch(); //Searches for specific item in list.
            break;
        case 2:
            system("cls");
            manager.CountItems();
            break;
        case 3:
            system("cls");
            manager.TallyItems();
            break;
        case 4:
            system("cls");
            return 0;
        default:
            system("cls");
            cout << "Invalid choice. Please enter a number between 0 and 4.\n";
        }
    } while (choice != 0);

    return 0;
}
