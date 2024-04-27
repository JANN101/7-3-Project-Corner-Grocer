#include <iostream>
#include <fstream>
#include <string>
#include <algorithm>
#include <map> // for map
#include <cstdlib> // for system("pause") and system("cls")
#include "GroceryManager.h"

using namespace std;

string toLowercase(string str) { // Converts string to lowercase
    transform(str.begin(), str.end(), str.begin(), ::tolower);
    return str;
}

void GroceryManager::ItemSearch() {
    string wordToCount;
    cout << "Enter the item to count occurrences: ";
    cin >> wordToCount;

    // Convert wordToCount to lowercase
    wordToCount = toLowercase(wordToCount);

    ifstream inputFile("CS210_Project_Three_Input_File.txt");
    if (!inputFile) {
        cerr << "Error opening file." << endl;
    }

    string word;
    int count = 0;
    while (inputFile >> word) {
        // Convert word from file to lowercase
        string wordLowercase = toLowercase(word);
        // Check if the word matches the word to count
        if (wordLowercase == wordToCount) {
            count++;
        }
    }

    cout << "The item \"" << wordToCount << "\" occurs " << count << " times." << endl;

    inputFile.close();

    system("pause"); // Pause until the user presses any key
    system("cls");   // Clear the screen
}

void GroceryManager::CountItems() {
    ifstream inputFile("CS210_Project_Three_Input_File.txt");
    if (!inputFile) {
        cerr << "Error opening file." << endl;
        return;
    }

    map<string, int> wordCounts;
    string word;
    while (inputFile >> word) {
        wordCounts[word]++;
    }

    inputFile.close(); //Close input file

    cout << "Item Count:\n";
    for (const auto& pair : wordCounts) {
        cout << pair.first << " " << pair.second << endl;
    }

    cout << "\nPress any key to return to the main menu...";
    system("pause"); // Pause until the user presses any key
    system("cls");   // Clear the screen
}

void GroceryManager::TallyItems() {
    ifstream inputFile("CS210_Project_Three_Input_File.txt");
    if (!inputFile) {
        cerr << "Error opening file." << endl;
        return;
    }

    map<string, int> wordCounts;
    string word;
    while (inputFile >> word) {
        wordCounts[word]++;
    }

    inputFile.close(); //Close input file

    cout << "Item Tally:\n";
    for (const auto& pair : wordCounts) {
        cout << pair.first << ": ";
        for (int i = 0; i < pair.second; ++i) {
            cout << "*"; // Print * for each occurrence
        }
        cout << endl;
    }

    cout << "\nPress any key to return to the main menu...";
    system("pause");
    system("cls");
}

void GroceryManager::AutoBackup() {
    ifstream inputFile("CS210_Project_Three_Input_File.txt");
    if (!inputFile) {
        system("cls");
        cerr << "Error opening file. Cannot continue." << endl;
        return;
    }

    map<string, int> wordCounts;
    string word;
    while (inputFile >> word) {
        wordCounts[word]++;
    }

    inputFile.close(); //Close input file

    ofstream outputFile("frequency.dat"); // Output backup file for item counts
    if (!outputFile) {
        cerr << "Error creating output file." << endl;
        return;
    }

    outputFile << "GROCERY LIST AUTO BACKUP\n";
    for (const auto& pair : wordCounts) {
        outputFile << pair.first << "- " << pair.second << endl; // Write each word and its count to the file
    }

    outputFile.close();
}