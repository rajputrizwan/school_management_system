#include <iostream>
#include <string>

using namespace std;

const int MAX_ENTRIES = 100;
const int MAX_CLASSES = 20; // Maximum number of classes

struct Faculty {
    string name;
    int id;
};

struct Student {
    string name;
    int id;
};

struct AdminStaff {
    string name;
    int id;
};

int facultyCount = 0;
int studentCount = 0;
int adminCount = 0;
int classCount = 10; // Initial 10 classes

string classes[MAX_CLASSES] = {"Class 1", "Class 2", "Class 3", "Class 4", "Class 5", 
                               "Class 6", "Class 7", "Class 8", "Class 9", "Class 10"};

// Function declarations
void addFaculty(Faculty facultyList[]);
void viewFaculty(const Faculty facultyList[]);
void deleteFaculty(Faculty facultyList[]);
void facultyMenu(Faculty facultyList[]);

void addStudent(Student studentList[]);
void viewStudents(const Student studentList[]);
void deleteStudent(Student studentList[]);
void studentMenu(Student studentList[]);

void addAdminStaff(AdminStaff adminList[]);
void viewAdminStaff(const AdminStaff adminList[]);
void deleteAdminStaff(AdminStaff adminList[]);
void adminMenu(AdminStaff adminList[]);

void viewClasses();
void addNewClass();

int main() {
    Faculty facultyList[MAX_ENTRIES];
    Student studentList[MAX_ENTRIES];
    AdminStaff adminList[MAX_ENTRIES];
    int choice;

    do {
        cout << "\nPress:\n";
        cout << "1. Faculty detail\n";
        cout << "2. Student detail\n";
        cout << "3. Administration staff detail\n";
        cout << "4. View Classes details\n";
        cout << "5. Add New Class\n";
        cout << "6. Exit\n";
        cout << "Enter your choice: ";
        cin >> choice;

        switch (choice) {
        case 1:
            facultyMenu(facultyList);
            break;
        case 2:
            studentMenu(studentList);
            break;
        case 3:
            adminMenu(adminList);
            break;
        case 4:
            viewClasses();
            break;
        case 5:
            addNewClass();
            break;
        case 6:
            cout << "Exiting the program.\n";
            break;
        default:
            cout << "Invalid option. Please try again.\n";
        }
    } while (choice != 6);

    return 0;
}

// Faculty Functions
void addFaculty(Faculty facultyList[]) {
    if (facultyCount >= MAX_ENTRIES) {
        cout << "Cannot add more faculty members. List is full.\n";
        return;
    }
    Faculty newFaculty;
    cin.ignore(); // Clear input buffer
    cout << "Enter Faculty Name: ";
    getline(cin, newFaculty.name);
    cout << "Enter Faculty ID: ";
    cin >> newFaculty.id;
    facultyList[facultyCount++] = newFaculty;
    cout << "Faculty member added successfully.\n";
}

void viewFaculty(const Faculty facultyList[]) {
    if (facultyCount == 0) {
        cout << "No faculty members to display.\n";
        return;
    }
    cout << "Faculty Members:\n";
    for (int i = 0; i < facultyCount; ++i) {
        cout << "Name: " << facultyList[i].name << ", ID: " << facultyList[i].id << endl;
    }
}

void deleteFaculty(Faculty facultyList[]) {
    int id;
    cout << "Enter Faculty ID to delete: ";
    cin >> id;
    for (int i = 0; i < facultyCount; ++i) {
        if (facultyList[i].id == id) {
            for (int j = i; j < facultyCount - 1; ++j) {
                facultyList[j] = facultyList[j + 1];
            }
            --facultyCount;
            cout << "Faculty member deleted successfully.\n";
            return;
        }
    }
    cout << "Faculty member not found.\n";
}

void facultyMenu(Faculty facultyList[]) {
    char choice;
    do {
        cout << "\nPress:\n";
        cout << "a. Add faculty member\n";
        cout << "b. View faculty member\n";
        cout << "c. Delete faculty member\n";
        cout << "d. Exit\n";
        cout << "Enter your choice: ";
        cin >> choice;

        switch (choice) {
        case 'a':
            addFaculty(facultyList);
            break;
        case 'b':
            viewFaculty(facultyList);
            break;
        case 'c':
            deleteFaculty(facultyList);
            break;
        case 'd':
            cout << "Exiting Faculty Menu.\n";
            break;
        default:
            cout << "Invalid option. Please try again.\n";
        }
    } while (choice != 'd');
}

// Student Functions
void addStudent(Student studentList[]) {
    if (studentCount >= MAX_ENTRIES) {
        cout << "Cannot add more students. List is full.\n";
        return;
    }
    Student newStudent;
    cin.ignore(); // Clear input buffer
    cout << "Enter Student Name: ";
    getline(cin, newStudent.name);
    cout << "Enter Student ID: ";
    cin >> newStudent.id;
    studentList[studentCount++] = newStudent;
    cout << "Student added successfully.\n";
}

void viewStudents(const Student studentList[]) {
    if (studentCount == 0) {
        cout << "No students to display.\n";
        return;
    }
    cout << "Students:\n";
    for (int i = 0; i < studentCount; ++i) {
        cout << "Name: " << studentList[i].name << ", ID: " << studentList[i].id << endl;
    }
}

void deleteStudent(Student studentList[]) {
    int id;
    cout << "Enter Student ID to delete: ";
    cin >> id;
    for (int i = 0; i < studentCount; ++i) {
        if (studentList[i].id == id) {
            for (int j = i; j < studentCount - 1; ++j) {
                studentList[j] = studentList[j + 1];
            }
            --studentCount;
            cout << "Student deleted successfully.\n";
            return;
        }
    }
    cout << "Student not found.\n";
}

void studentMenu(Student studentList[]) {
    char choice;
    do {
        cout << "\nPress:\n";
        cout << "a. Add Students detail\n";
        cout << "b. View Students detail\n";
        cout << "c. Delete Students detail\n";
        cout << "d. Exit\n";
        cout << "Enter your choice: ";
        cin >> choice;

        switch (choice) {
        case 'a':
            addStudent(studentList);
            break;
        case 'b':
            viewStudents(studentList);
            break;
        case 'c':
            deleteStudent(studentList);
            break;
        case 'd':
            cout << "Exiting Student Menu.\n";
            break;
        default:
            cout << "Invalid option. Please try again.\n";
        }
    } while (choice != 'd');
}

// Admin Functions
void addAdminStaff(AdminStaff adminList[]) {
    if (adminCount >= MAX_ENTRIES) {
        cout << "Cannot add more admin staff. List is full.\n";
        return;
    }
    AdminStaff newAdmin;
    cin.ignore(); // Clear input buffer
    cout << "Enter Admin Staff Name: ";
    getline(cin, newAdmin.name);
    cout << "Enter Admin Staff ID: ";
    cin >> newAdmin.id;
    adminList[adminCount++] = newAdmin;
    cout << "Admin staff added successfully.\n";
}

void viewAdminStaff(const AdminStaff adminList[]) {
    if (adminCount == 0) {
        cout << "No administration staff to display.\n";
        return;
    }
    cout << "Administration Staff:\n";
    for (int i = 0; i < adminCount; ++i) {
        cout << "Name: " << adminList[i].name << ", ID: " << adminList[i].id << endl;
    }
}

void deleteAdminStaff(AdminStaff adminList[]) {
    int id;
    cout << "Enter Admin Staff ID to delete: ";
    cin >> id;
    for (int i = 0; i < adminCount; ++i) {
        if (adminList[i].id == id) {
            for (int j = i; j < adminCount - 1; ++j) {
                adminList[j] = adminList[j + 1];
            }
            --adminCount;
            cout << "Admin staff deleted successfully.\n";
            return;
        }
    }
    cout << "Admin staff not found.\n";
}

void adminMenu(AdminStaff adminList[]) {
    char choice;
    do {
        cout << "\nPress:\n";
        cout << "a. Add administration staff detail\n";
        cout << "b. View administration staff detail\n";
        cout << "c. Delete administration staff detail\n";
        cout << "d. Exit\n";
        cout << "Enter your choice: ";
        cin >> choice;

        switch (choice) {
        case 'a':
            addAdminStaff(adminList);
            break;
        case 'b':
            viewAdminStaff(adminList);
            break;
        case 'c':
            deleteAdminStaff(adminList);
            break;
        case 'd':
            cout << "Exiting Administration Staff Menu.\n";
            break;
        default:
            cout << "Invalid option. Please try again.\n";
        }
    } while (choice != 'd');
}

// Class Functions
void viewClasses() {
    cout << "Classes:\n";
    for (int i = 0; i < classCount; ++i) {
        cout << classes[i] << endl;
    }
}

void addNewClass() {
    if (classCount >= MAX_CLASSES) {
        cout << "Cannot add more classes. Maximum limit reached.\n";
        return;
    }
    cin.ignore(); // Clear input buffer
    cout << "Enter new class name: ";
    getline(cin, classes[classCount++]);
    cout << "Class added successfully.\n";
}
