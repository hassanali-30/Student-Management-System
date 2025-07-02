#include <iostream>
#include <fstream>
#include <string>
using namespace std;

struct Student {
    string name;
    int rollNo;
    float marks[5];
};

void addStudent() {
    ofstream fout("data.txt", ios::app);
    Student s;
    cout << "Enter student name: ";
    getline(cin, s.name);
    cout << "Enter roll number: ";
    cin >> s.rollNo;
    cout << "Enter marks in 5 subjects: ";
    for (int i = 0; i < 5; i++) {
        cin >> s.marks[i];
    }
    fout.write((char*)&s, sizeof(s));
    fout.close();
    cout << "Student added successfully!" << endl;
}

void displayStudent() {
    ifstream fin("data.txt");
    int rollNo;
    cout << "Enter roll number: ";
    cin >> rollNo;
    Student s;
    bool found = false;
    while (fin.read((char*)&s, sizeof(s))) {
        if (s.rollNo == rollNo) {
            found = true;
            cout << "Name: " << s.name << endl;
            cout << "Roll No: " << s.rollNo << endl;
            cout << "Marks: ";
            for (int i = 0; i < 5; i++) {
                cout << s.marks[i] << " ";
            }
            cout << endl;
            break;
        }
    }
    if (!found) {
        cout << "Student not found!" << endl;
    }
    fin.close();
}

void deleteStudent() {
    ifstream fin("data.txt");
    ofstream fout("temp.txt");
    int rollNo;
    cout << "Enter roll number: ";
    cin >> rollNo;
    Student s;
    bool found = false;
    while (fin.read((char*)&s, sizeof(s))) {
        if (s.rollNo != rollNo) {
            fout.write((char*)&s, sizeof(s));
        } else {
            found = true;
        }
    }
    fin.close();
    fout.close();
    remove("data.txt");
    rename("temp.txt", "students.txt");
    if (found) {
        cout << "Student deleted successfully!" << endl;
    } else {
        cout << "Student not found!" << endl;
    }
}

void updateStudent() {
    ifstream fin("data.txt");
    ofstream fout("data.txt");
    int rollNo;
    cout << "Enter roll number: ";
    cin >> rollNo;
    Student s;
    bool found = false;
    while (fin.read((char*)&s, sizeof(s))) {
        if (s.rollNo != rollNo) {
            fout.write((char*)&s, sizeof(s));
        } else {
            found = true;
            cout << "Enter new marks in 5 subjects: ";
            for (int i = 0; i < 5; i++) {
                cin >> s.marks[i];
            }
            fout.write((char*)&s, sizeof(s));
        }
    }
    fin.close();
    fout.close();
    remove("data.txt");
    rename("data.txt", "students.txt");
    if (found) {
        cout << "Student updated successfully!" << endl;
    } else {
        cout << "Student not found!" << endl;
    }
}

void showAllStudents() {
    ifstream fin("data.txt");
    Student s;
    while (fin.read((char*)&s, sizeof(s))) {
        cout << "Name: " << s.name << endl;
        cout << "Roll No: " << s.rollNo << endl;
        cout << "Marks: ";
        for (int i = 0; i < 5; i++) {
            cout << s.marks[i] << " ";
        }
        cout << endl;
    }
    fin.close();
}

int main() {
    int choice;
    do {
        cout << "Enter the choice:" << endl;
        cout << "1. Enter new student data" << endl;
        cout << "2. Display individual student marks sheet" << endl;
        cout << "3. Delete student" << endl;
        cout << "4. Update an individual student record" << endl;
        cout << "5. Show all students record" << endl;
        cout << "6. Exit" << endl;
        cin >> choice;
        cin.ignore();
        switch (choice) {
            case 1:
                addStudent();
                break;
            case 2:
                displayStudent();
                break;
            case 3:
                deleteStudent();
                break;
            case 4:
                updateStudent();
                break;
            case 5:
                showAllStudents();
                break;
            case 6:
                cout << "Exiting..." << endl;
                break;
            default:
                cout << "Invalid choice!" << endl;
        }
    } while (choice != 6);
    return 0;
}
