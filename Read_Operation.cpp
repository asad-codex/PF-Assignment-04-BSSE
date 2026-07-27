#include <iostream>
#include <fstream>
#include <string>
#include <sstream>
#include <iomanip>

using namespace std;

int main() {
    // 1. Open students.txt in input mode
    ifstream inFile("students.txt");

    // 2. Check whether the file opened successfully
    if (!inFile) {
        cout << "Error: Could not open the file for reading! Make sure 'students.txt' exists." << endl;
        return 1;
    }

    cout << "--- Students Records Table ---" << endl;
    cout << left << setw(10) << "S.No" 
         << setw(15) << "Roll No" 
         << setw(25) << "Name" 
         << setw(10) << "Marks" << endl;
    cout << string(60, '-') << endl;

    string line;
    int recordCount = 0;

    // 3. Read the file line by line
    while (getline(inFile, line)) {
        if (line.empty()) continue; // Skip empty lines if any

        stringstream ss(line);
        string rollNo, name, marks, pipe;

        // Extract Roll No, Pipe, Name (can have spaces), Pipe, Marks
        getline(ss, rollNo, '|');
        getline(ss, name, '|');
        getline(ss, marks, '|');

        // Trim spaces around extracted values
        rollNo.erase(0, rollNo.find_first_not_of(" \t"));
        rollNo.erase(rollNo.find_last_not_of(" \t") + 1);

        name.erase(0, name.find_first_not_of(" \t"));
        name.erase(name.find_last_not_of(" \t") + 1);

        marks.erase(0, marks.find_first_not_of(" \t"));
        marks.erase(marks.find_last_not_of(" \t") + 1);

        recordCount++;

        // 4. Display each record
        cout << left << setw(10) << recordCount 
             << setw(15) << rollNo 
             << setw(25) << name 
             << setw(10) << marks << endl;
    }

    // Close the file
    inFile.close();

    cout << string(60, '-') << endl;
    cout << "Total number of records found in the file: " << recordCount << endl;

    return 0;
}
