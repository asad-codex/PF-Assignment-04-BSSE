#include <iostream>
#include <fstream>
#include <string>
#include <sstream>
#include <iomanip>

using namespace std;

int main() {
    // 9. Open the file in a mode that allows both reading and writing (ios::in | ios::out)
    fstream file("students.txt", ios::in | ios::out);

    if (!file) {
        cout << "Error: Could not open 'students.txt' for reading and writing!" << endl;
        return 1;
    }

    // 10. Prompt the user for the Roll No to search for and the new Marks value
    string searchRollNo;
    float newMarks;

    cout << "Enter Roll No to search and update marks: ";
    cin >> searchRollNo;
    cout << "Enter new Marks: ";
    cin >> newMarks;

    string line;
    long long pos = 0;
    bool found = false;

    // Read line by line to locate the correct record and its file position
    while (getline(file, line)) {
        long long currentLinePos = pos;
        pos = file.tellg(); // Track the file position for the next line

        if (line.empty()) continue;

        stringstream ss(line);
        string rollNo, name, marksStr, pipe;

        getline(ss, rollNo, '|');
        getline(ss, name, '|');
        getline(ss, marksStr, '|');

        // Trim leading/trailing spaces from extracted rollNo
        rollNo.erase(0, rollNo.find_first_not_of(" \t"));
        rollNo.erase(rollNo.find_last_not_of(" \t") + 1);

        // Check if this is the target student
        if (rollNo == searchRollNo) {
            found = true;

            // Format the updated record precisely to match the exact length/layout
            // Assuming format: RollNo | Name | Marks (e.g., "22 | Muhammad Asad | 95")
            // Trim name spaces if needed
            name.erase(0, name.find_first_not_of(" \t"));
            name.erase(name.find_last_not_of(" \t") + 1);

            stringstream updatedLineStream;
            updatedLineStream << rollNo << " | " << name << " | " << newMarks;
            string updatedRecord = updatedLineStream.str();

            // Pad the updated record with spaces if it's shorter than the original line to avoid corrupting file structure
            if (updatedRecord.length() < line.length()) {
                updatedRecord.append(line.length() - updatedRecord.length(), ' ');
            }

            // 11. Use seekp() to move the write pointer back to the beginning of this specific line
            file.seekp(currentLinePos, ios::beg);
            
            // Overwrite the record in the file
            file << updatedRecord;
            
            break; // Exit loop once updated
        }
    }

    // Close the file stream
    file.close();

    // 12. Display a success message or an appropriate message if not found
    if (found) {
        cout << "\nSuccess: Student record found and marks updated successfully!" << endl;
    } else {
        cout << "\nError: Roll No '" << searchRollNo << "' does not exist in the file." << endl;
    }

    return 0;
}
