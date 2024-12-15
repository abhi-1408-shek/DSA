#include <iostream>
#include <fstream>
#include <string>
#include <iomanip>
using namespace std;

// The 'Student' class 
class Student {
private:
    int rollNo;
    string name;
    float marks;

public:
    Student() : rollNo(0), marks(0.0) {}

    // Input student details
    void inputDetails() {
        cout << "Enter Roll Number: ";
        cin >> rollNo;
        cin.ignore();
        cout << "Enter Name: ";
        getline(cin, name);
        cout << "Enter Marks: ";
        cin >> marks;
    }

    //Display student details 
    void displayDetails() const {
        cout << left << setw(10) << rollNo << setw(20) << name << setw(10) << fixed << setprecision(2) << marks << endl;
    }

    // Save student details to a file
    void saveToFile(ofstream &outfile) const {
        outfile << rollNo << "\n" << name << "\n" << marks << "\n";
    }

    // Load student details from a file
    void loadFromFile(ifstream &infile) {
        infile >> rollNo;
        infile.ignore();
        getline(infile, name);
        infile >> marks;
    }

    int getRollNo() const {
        return rollNo;
    }
};

// Function to add a new student and save details to a file
void addStudent(const string &filename) {
    ofstream outfile(filename, ios::app);
    if (!outfile) {
        cerr << "Error opening file for writing." << endl;
        return;
    }

    Student student;
    student.inputDetails();
    student.saveToFile(outfile);

    cout << "Student details added successfully." << endl;
    outfile.close();
}

// Function to display all students by reading details from a file
void displayAllStudents(const string &filename) {
    ifstream infile(filename);
    if (!infile) {
        cerr << "Error opening file for reading or file does not exist." << endl;
        return;
    }

    cout << left << setw(10) << "Roll No" << setw(20) << "Name" << setw(10) << "Marks" << endl;
    cout << string(40, '-') << endl;

    Student student;
    while (infile.peek() != EOF) {
        student.loadFromFile(infile);
        student.displayDetails();
    }

    infile.close();
}

// Function to search for a student by roll number in the file
void searchStudent(const string &filename) {
    ifstream infile(filename);
    if (!infile) {
        cerr << "Error opening file for reading or file does not exist." << endl;
        return;
    }

    int searchRollNo;
    cout << "Enter Roll Number to search: ";
    cin >> searchRollNo;

    Student student;
    bool found = false;
    while (infile.peek() != EOF) {
        student.loadFromFile(infile);
        if (student.getRollNo() == searchRollNo) {
            cout << "Student found:" << endl;
            cout << left << setw(10) << "Roll No" << setw(20) << "Name" << setw(10) << "Marks" << endl;
            cout << string(40, '-') << endl;
            student.displayDetails();
            found = true;
            break;
        }
    }

    if (!found) {
        cout << "Student with Roll Number " << searchRollNo << " not found." << endl;
    }

    infile.close();
}

// Main function with a menu-driven program 
int main() {
    string filename = "students.txt";
    int choice;

    do {
        cout << "\nStudent Management System\n";
        cout << "1. Add Student\n";
        cout << "2. Display All Students\n";
        cout << "3. Search Student\n";
        cout << "4. Exit\n";
        cout << "Enter your choice: ";
        cin >> choice;

        switch (choice) {
        case 1:
            addStudent(filename);
            break;
        case 2:
            displayAllStudents(filename);
            break;
        case 3:
            searchStudent(filename);
            break;
        case 4:
            cout << "Exiting..." << endl;
            break;
        default:
            cout << "Invalid choice! Please try again." << endl;
        }
    } while (choice != 4);

    return 0;
}
