//
// Created by hima1 on 5/16/2024.
//

#include "Teacher.h"

void Teacher::login() {
    int choice = readMenu({"view all info", "show students", "manage grade", "modify info", "Exit"}, "choose an option...");
    switch (choice)
    {
        case 1: {
            cout << "The course code is: " << courseCode << endl;
            cout << "Name is: " << get_name() << endl;
            cout << "The email is: " << get_email() << endl;
            cout << "your password is: " << get_password() << endl;
            cout << "the salary is:" << salary << endl;
            break;
        }
        case 2: {
            printStudentSheet();
            break;
        }
        case 3: {
            int id, points;
            cout << "Enter the id of student you want to change" << endl;
            cin >> id;
            cout << "Enter the new points" << endl;
            changeGradeOfStudent(id, points);
            cout << "The info changed successfully." << endl;
            break;
        }
        case 4: {
            modifyInfo();
            break;
        }
        case 5:
            break;
    }
}

Teacher::Teacher(string Name, string Email, string Password, string Code, float Salary) : User(TeacherIDCounter++, Name, Email, Password){
    courseCode = Code, salary = Salary;
}

void Teacher::changeGradeOfStudent(int studentID, int points) {
    auto s = students.find(studentID);
    s->second.changeCoursePoints(courseCode, points);
}

string Teacher::getCourseCode() {
    return courseCode;
}

float Teacher::getSalary() {
    return salary;
}

void Teacher::setSalary(float Salary) {
    salary = Salary;
}

vector<Student> Teacher::studentsSheet() {
    vector <Student> studentsSheet;
    Course TeacherCourse = courses.find(courseCode)->second;

    for(auto &studentID : TeacherCourse.getStudentIDs()){
        studentsSheet.push_back(students.find(studentID)->second);
    }
    return studentsSheet;
}


void Teacher::printStudentSheet()
{
    vector<Student> students_sheet = studentsSheet();
    for (int i = 0; i < students_sheet.size(); i++)
    {
        cout << students_sheet[i].get_name() << endl;
    }
}

void Teacher::modifyInfo()
{

    int choice = readMenu({"name", "Email", "password"}, "choose what you want to change!");
    switch (choice) {
        case 1: {
            cout << "Enter the new name" << endl;
            cin >> name;
            setName(name);
            break;
        }
        case 2: {
            cout << "Enter the new email" << endl;
            cin >> email;
            setEmail(email);
            break;
        }
        default: {
            cout << "Enter the new password";
            string pass;
            cin >> pass;
            setPassword(pass);
        }
    }
}

