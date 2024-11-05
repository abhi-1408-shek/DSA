#include <iostream>
#include <string>
using namespace std;

class Student {
private:
    string name;
    string parentage;
    string reg_no;
    int age;
    int semester;
    int roll_number;
    int classes_attended;
    const int total_classes = 50;
    float marks[5];

public:
    void showDetails() const {
        cout << "Details for Roll No: " << roll_number << endl;
        cout << "Name: " << name << endl;
        cout << "Parentage: " << parentage << endl;
        cout << "Registration Number: " << reg_no << endl;
        cout << "Age: " << age << endl;
        cout << "Semester: " << semester << endl;
        cout << "Classes Attended: " << classes_attended << "/" << total_classes << endl;
        cout << "Marks: ";
        for (int i = 0; i < 5; ++i) {
            cout << marks[i] << " ";
        }
        cout << endl;
    }

    void getDetails() {
        cout << "Enter student's name: ";
        getline(cin, name);

        cout << "Enter parent's name: ";
        getline(cin, parentage);

        cout << "Enter registration number: ";
        getline(cin, reg_no);

        cout << "Enter student's age: ";
        cin >> age;

        cout << "Enter semester: ";
        cin >> semester;

        cout << "Enter roll number: ";
        cin >> roll_number;

        cout << "Enter number of classes attended (out of 50): ";
        cin >> classes_attended;

        cout << "Enter marks for 5 subjects:\n";
        for (int i = 0; i < 5; ++i) {
            cout << "Subject " << i + 1 << ": ";
            cin >> marks[i];
        }
        cin.ignore();
    }

    float getAttendancePercentage() const {
        return (float)classes_attended / total_classes * 100;
    }

    void printAttendance() const {
        cout << "Roll No: " << roll_number << ", Name: " << name << ", Attendance: " << getAttendancePercentage() << "%\n";
    }

    bool hasAttendanceShortage() const {
        return getAttendancePercentage() < 75;
    }

    float getAverageMarks() const {
        float totalMarks = 0;
        for (int i = 0; i < 5; ++i) {
            totalMarks += marks[i];
        }
        return totalMarks / 5;
    }

    bool hasHighAverageMarks() const {
        return getAverageMarks() >= 90;
    }

    int getRollNumber() const { return roll_number; }
    string getName() const { return name; }
};

void showTop5(Student students[], int n) {
    for (int i = 0; i < n - 1; ++i) {
        for (int j = 0; j < n - i - 1; ++j) {
            if (students[j].getAverageMarks() < students[j + 1].getAverageMarks()) {
                swap(students[j], students[j + 1]);
            }
        }
    }

    cout << "Top 5 Students (by average marks):\n";
    for (int i = 0; i < 5 && i < n; ++i) {
        cout << "Roll No: " << students[i].getRollNumber() << ", Name: " << students[i].getName()
             << ", Average Marks: " << students[i].getAverageMarks() << endl;
    }
}

int main() {
    int n;

    cout << "Enter number of students: ";
    cin >> n;
    cin.ignore();

    Student students[100];

    for (int i = 0; i < n; ++i) {
        cout << "Enter details for student " << i + 1 << ":\n";
        students[i].getDetails();
    }

    cout << "Details of all students:\n";
    for (int i = 0; i < n; ++i) {
        students[i].showDetails();
    }

    cout << "Attendance of all students:\n";
    for (int i = 0; i < n; ++i) {
        students[i].printAttendance();
    }

    cout << "Students with attendance shortage (< 75%):\n";
    bool shortage = false;
    for (int i = 0; i < n; ++i) {
        if (students[i].hasAttendanceShortage()) {
            cout << "Roll No: " << students[i].getRollNumber() << ", Name: " << students[i].getName() << endl;
            shortage = true;
        }
    }
    if (!shortage) {
        cout << "No students with attendance shortage.\n";
    }

    showTop5(students, n);

    cout << "Students with 90% or more average marks:\n";
    bool highAverage = false;
    for (int i = 0; i < n; ++i) {
        if (students[i].hasHighAverageMarks()) {
            cout << "Roll No: " << students[i].getRollNumber() << ", Name: " << students[i].getName()
                 << ", Average Marks: " << students[i].getAverageMarks() << endl;
            highAverage = true;
        }
    }
    if (!highAverage) {
        cout << "No students with 90% or more average marks.\n";
    }

    return 0;
}
