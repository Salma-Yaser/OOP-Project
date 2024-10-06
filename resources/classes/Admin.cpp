//#include <bits/stdc++.h>
using namespace std;
#include "User.h"
#include "Student.h"
#include "Teacher.h"
#include "Course.h"
#include "Admin.h"


void clearScreen()
{
#ifdef _WIN32
    system("cls");
#else
    cout << "\033[2J\033[1;1H";
#endif
}

void pauseScreen()
{
    cout << "Press Enter to continue...";
    cin.ignore(numeric_limits<streamsize>::max(), '\n');
    cin.get();
}

void displayLogo()
{
    cout << "\033[1;35m"; // Set text color to magenta
    cout << R"(
  /--------------------------------------------------\
  |                                                  |
  |                                                  |
  |  ,---.                 ,--.                      |
  | '   .-',--. ,--.,---.,-'  '-. ,---. ,--,--,--.   |
  | `.  `-. \  '  /(  .-''-.  .-'| .-. :|        |   |
  | .-'    | \   ' .-'  `) |  |  \   --.|  |  |  |   |
  | -----'.-'  /  `----'  `--'   `----'------'   |   |
  |         `---'                                    |
  |                                                  |
  |                                                  |
  \--------------------------------------------------/
)" << '\n';
    cout << "\033[0m"; // Reset text color
}

//void displayMenu() {
//    cout << "\033[1;36m"; // Set text color to cyan
//    cout << R"(
//+----------------------------------------+
//|               MAIN MENU                |
//+----------------------------------------+
//| 1. Login                               |
//| 2. Add Student                         |
//| 3. Remove Student                      |
//| 4. Add Teacher                         |
//| 5. Remove Teacher                      |
//| 6. Add Course                          |
//| 7. Remove Course                       |
//| 8. Print All Students                  |
//| 9. Print All Teachers                  |
//| 10. Print All Courses                  |
//| 11. Exit                               |
//+----------------------------------------+
//Enter your choice: )";
//    cout << "\033[0m"; // Reset text color
//}

void displayFooter()
{
    cout << "\033[1;33m"; // Set text color to yellow
    cout << R"(
+----------------------------------------+
|        Powered by Salmaa's team        |
+----------------------------------------+
)";
    cout << "\033[0m"; // Reset text color
}


Admin::Admin(int id , string email, string name , string pass )
        :User( id , name, email , pass) {
}

void Admin:: addStudent (Student s){
    students.insert({s.get_id(), s});
}

void Admin:: removeStudent (int id){
    auto it = students.find(id);
    if (it != students.end()) {
        students.erase(it);
        cout << "Deleted student-id: "<< id<<endl;
    }
    else{
        cout<<"Student of ID "<<id<< "not found \n"<<endl;
    }
}
void Admin:: addTeacher (Teacher t){
    teachers.insert({t.get_id(), t});
}
void Admin:: removeTeacher(int id ){
    auto it = teachers.find(id);
    if (it != teachers.end()) {
        teachers.erase(it);
        cout << "Deleted teacher-id: "<< id<<endl;
    }
    else {
        cout<<"Teatcher of ID "<<id<< "not found \n"<<endl;
    }
}
void Admin:: addCourse (Course c){
    courses.insert({c.get_code() , c});
}
void Admin:: removeCourse(string c){
    auto it = courses.find(c);
    if (it != courses.end()) {
        courses.erase(it);
        cout << "Deleted Course Code : "<< c <<endl;
    }
    else {
        cout<<"Course of Code "<<c<< "not found \n"<<endl;
    }
}


void Admin:: printAllStudents()  {
    if (students.empty()) {
        cout << "No students found!" << endl;
    }
    else {
        for(auto it : students){
            cout << "ID: " << it.first << ", Name: " << it.second.get_name() << endl;
        }
    }
}

void Admin:: printAllTeachers()  {
    if (teachers.empty()) {
        cout << "No teachers found!" << endl;
    }
    else {
        for(auto it : teachers){
            cout << "ID: " << it.first << ", Name: " << it.second.get_name() << endl;
        }
    }
}

void Admin:: printAllCourses() {
    if (courses.empty()) {
        cout << "No courses found!" << endl;
    }
    else {
        for(auto it : courses){
            cout << "ID: " << it.first << ", Name: " << it.second.get_title() << endl;
        }
    }
}

void Admin:: adminMenu() {
    int choice;
    do {
        clearScreen();
//        displayLogo();
        choice = readMenu(
                {"Login",
                 "Add Student",
                 "Remove Student",
                 "Add Teacher",
                 "Remove Teacher",
                 "Add Course",
                 "Remove Course",
                 "Print All Students",
                 "Print All Teachers",
                 "Print All Courses",
                 "Exit"
                    },
                "Admin Menu"
                );

        // Ensure any remaining input is cleared
        cin.ignore(numeric_limits<streamsize>::max(), '\n');

        switch (choice) {
            case 2: {
                string name, email, password;
                cout << "Enter student name : ";
                cin >> name;
                cout << "Enter student email : ";
                cin >> email;
                cout << "Enter student password : ";
                cin >> password;

                addStudent(Student(name, email, password, {}));
                break;
            }
            case 3: {
                int id;
                cout << "Enter student ID to remove: ";
                cin >> id;
                removeStudent(id);
                break;
            }
            case 4: {
                string name, email, password, code;
                float salary;

                cout << "\nEnter student name : ";
                cin >> name;
                cout << "\nEnter student email : ";
                cin >> email;
                cout << "\nEnter student password : ";
                cin >> password;
                cout << "\nEnter course code : ";
                cin >> code;
                cout << "\nEnter salary : ";
                cin >> salary;

                addTeacher(Teacher(name, email, password, code, salary));
                break;
            }
            case 5: {
                int id;
                cout << "Enter teacher ID to remove: ";
                cin >> id;
                removeTeacher(id);
                break;
            }
            case 6: {
                string code, name;
                cout << "Enter course ID and name: ";
                cin >> code >> name;
                addCourse(Course(code, name));
                break;
            }
            case 7: {
                string id;
                cout << "Enter course ID to remove: ";
                cin >> id;
                removeCourse(id);
                break;
            }
            case 8:
                printAllStudents();
                break;
            case 9:
                printAllTeachers();
                break;
            case 10:
                printAllCourses();
                break;
            case 11:
                cout << "\033[1;31m> Exiting the program.\033[0m\n";
//                saveData();
                return;
            default:
                cout << "\033[1;31m> Invalid choice. Please select a valid option.\033[0m\n";
                break;
        }
        displayFooter();
        pauseScreen();
        clearScreen();
    } while (choice != 11);
}

