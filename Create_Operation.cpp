#include <iostream>
#include <fstream>
#include <string>

using namespace std;

int main() {
    // 1. Declare and open the file in output mode (ios::out)
    // ios::out creates the file if it doesn't exist or overwrites it if it does.
    ofstream outFile("students.txt", ios::out);

    // Check if the file opened successfully
    if (!outFile) {
        cout << "Error: Could not open the file for writing!" << endl;
        return 1;
    }

    cout << "--- Enter Records for 5 Students ---" << endl;

    // 2. Use a loop to accept 5 student records from the user via cin
    for (int i = 1; i <= 5; i++) {
        int rollNo;
        string name;
        float marks;

        cout << "\nStudent " << i << ":" << endl;
        cout << "Enter Roll No: ";
        cin >> rollNo;
        
        // Clear input buffer before taking string input with spaces if necessary
        cin.ignore(); 

        cout << "Enter Name: ";
        getline(cin, name);

        cout << "Enter Marks: ";
        cin >> marks;

        // 3. Write each record to the file in a well-formatted layout (one record per line)
        // Using a delimiter (like a comma or tab) to separate fields makes it easier to read later.
        outFile << rollNo << " | " << name << " | " << marks << endl;
    }

    // 4. Close the file and display a confirmation message
    outFile.close();
    
    cout << "\nSuccess: Data saved successfully to 'students.txt'!" << endl;

    return 0;
}
