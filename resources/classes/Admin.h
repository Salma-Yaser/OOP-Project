//
// Created by hima1 on 5/16/2024.
//

#include <bits/stdc++.h>
#include "User.h"
#include "Student.h"
#include "Teacher.h"
#include "Course.h"
#include "Global.h"
#include "containers/students.h"
#include "containers/teachers.h"
#include "containers/courses.h"

#ifndef OOP_PROJECT_ADMIN_H
#define OOP_PROJECT_ADMIN_H

using namespace std;


class Admin  : public User {
public:
    map<int, Student> students;
    map<int, Teacher> teachers;
    map<string, Course> courses;

    Admin(int id , string email, string name , string pass );
    void addStudent (Student);
    void removeStudent (int);
    void addTeacher (Teacher);
    void removeTeacher(int);
    void addCourse (Course);
    void removeCourse(string);


    void printAllStudents();
    void printAllTeachers();
    void printAllCourses();
    void adminMenu();
//    void login() override;
};

#endif //OOP_PROJECT_ADMIN_H
