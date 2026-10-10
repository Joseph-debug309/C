#include <iostream>
using namespace std;

class Student {
    string name;
    int age;
public:
    // Constructor with initialization list
    Student(string n, int a) : name(n), age(a) {
        cout << "Student created: " << name << ", Age: " << age << endl;
    }
};

int main() {
    Student s("Alice", 20);
    return 0;
}
