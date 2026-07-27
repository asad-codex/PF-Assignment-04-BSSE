#include <iostream>
#include <fstream>
#include <string>
#include <sstream>

using namespace std;

int main() {
    string deleteRollNo;
    cout << "Enter Roll No of the student to delete: ";
    cin >> deleteRollNo;

    // 13. Open the original file for reading and create a temporary file (temp.txt) for writing
    ifstream inFile("students.txt");
    ofstream tempFile("temp.txt");

    if (!inFile) {
        cout << "Error: Could not open 'students.txt' for reading!" << endl;
        return 1;
    }

    if (!tempFile) {
        cout << "Error: Could not create temporary file!" << endl;
        inFile.close();
        return 1;
    }

    string line;
    bool found = false;

    // 14. Copy every record to the temporary file except the one matching the given Roll No
    while (getline(inFile, line)) {
        if (line.empty()) continue;

        stringstream ss(line);
        string rollNo, name, marks, pipe;

        getline(ss, rollNo, '|');
        
        // Trim spaces around extracted rollNo
        rollNo.erase(0, rollNo.find_first_not_of(" \t"));
        rollNo.erase(rollNo.find_last_not_of(" \t") + 1);

        // Check if this record matches the roll number to be deleted
        if (rollNo == deleteRollNo) {
            found = true; // Skip writing this line to temp file
        } else {
            tempFile << line << endl; // Copy other records to temp file
        }
    }

    // 15. Close both files
    inFile.close();
    tempFile.close();

    // 15. Delete the original file using remove(), and rename temporary file using rename()
    if (found) {
        if (remove("students.txt") != 0) {
            cout << "Error: Could not delete the original file." << endl;
            return 1;
        }
        if (rename("temp.txt", "students.txt") != 0) {
            cout << "Error: Could not rename the temporary file." << endl;
            return 1;
        }
        // 16. Display a confirmation message that the record was deleted
        cout << "\nSuccess: Student record with Roll No '" << deleteRollNo << "' deleted successfully!" << endl;
    } else {
        // If not found, remove the temporary file since no changes were made
        remove("temp.txt");
        // 16. Display a message that the record was not found
        cout << "\nError: Roll No '" << deleteRollNo << "' does not exist in the file." << endl;
    }

    return 0;
}
