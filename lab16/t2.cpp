#include <iostream>
#include <vector>
#include <stdexcept>

class Person {
protected:
    std::string name;
    std::string gender;
    int age;

public:
    Person(const std::string& n, const std::string& g, int a) : name(n), gender(g), age(a) {}

    virtual void displayInfo() const {
        std::cout << "Name: " << name << ", Gender: " << gender << ", Age: " << age;
    }
};

class Student : public Person {
private:
    int course;
    std::string group;
    std::string university;

public:
    Student(const std::string& n, const std::string& g, int a, int c, const std::string& gr, const std::string& univ)
            : Person(n, g, a), course(c), group(gr), university(univ) {}

    void displayInfo() const override {
        Person::displayInfo();
        std::cout << ", Course: " << course << ", Group: " << group << ", University: " << university;
    }
};

class Teacher : public Person {
private:
    std::string department;
    std::string position;
    double salary;

public:
    Teacher(const std::string& n, const std::string& g, int a, const std::string& dept, const std::string& pos, double sal)
            : Person(n, g, a), department(dept), position(pos), salary(sal) {}

    void displayInfo() const override {
        Person::displayInfo();
        std::cout << ", Department: " << department << ", Position: " << position << ", Salary: " << salary;
    }
};

class GraduateStudent : public Student, public Teacher {
public:
    GraduateStudent(const std::string& n, const std::string& g, int a, int c, const std::string& gr,
                    const std::string& univ, const std::string& dept, const std::string& pos, double sal)
            : Student(n, g, a, c, gr, univ), Teacher(n, g, a, dept, pos, sal) {}

    void displayInfo() const override {
        Student::displayInfo();
        std::cout << ", Department: " << Teacher::department << ", Position: " << Teacher::position
                  << ", Salary: " << Teacher::salary;
    }
};

int main() {
    std::vector<Person*> people;

    try {
        people.push_back(new Student("John Doe", "Male", 20, 2, "GroupA", "UniversityA"));
        people.push_back(new Teacher("Jane Smith", "Female", 35, "Math", "Professor", 50000.0));
        people.push_back(new GraduateStudent("Bob Johnson", "Male", 28, 3, "GroupB", "UniversityB", "Physics", "TA", 30000.0));

        for (const auto& person : people) {
            person->displayInfo();
            std::cout << std::endl;
        }
    } catch (const std::exception& e) {
        std::cerr << "Error: " << e.what() << std::endl;
    }

    for (const auto& person : people) {
        delete person;
    }

    return 0;
}
