#ifndef PROJECT1_STUDENT_H
#define PROJECT1_STUDENT_H

#include <string>
using namespace std;

class Student {
public:
    string name;
    int ID;
    int balance;
    Student *left;
    Student *right;
    Student() : name(""), ID(0), balance(0), left(nullptr), right(nullptr) {}
    Student(string n, int x) : name(n), ID(x), left(nullptr), right(nullptr) {}
};

#endif //PROJECT1_STUDENT_H