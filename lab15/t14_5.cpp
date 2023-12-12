#include <iostream>
#include <fstream>
#include <vector>
#include <sstream>
#include <algorithm>
#include <limits>

struct Student {
    std::string surname;
    int course;
    std::string group;
    std::vector<int> grades;
};

double calculateAverageGrade(const Student& student) {
    if (student.grades.empty()) {
        return 0.0;
    }

    int sum = std::accumulate(student.grades.begin(), student.grades.end(), 0);
    return static_cast<double>(sum) / student.grades.size();
}

std::string findStudentWithLowestAverage(const std::vector<Student>& students) {
    double lowestAverage = std::numeric_limits<double>::max();
    std::string lowestSurname;

    for (const auto& student : students) {
        double average = calculateAverageGrade(student);
        if (average < lowestAverage) {
            lowestAverage = average;
            lowestSurname = student.surname;
        }
    }

    return lowestSurname;
}

void createStudentFile(const std::string& filename, const std::vector<Student>& students) {
    std::ofstream outputFile(filename);

    if (!outputFile.is_open()) {
        std::cerr << "Не вдалося відкрити файл для запису." << std::endl;
        return;
    }

    for (const auto& student : students) {
        outputFile << student.surname << " " << student.course << " " << student.group << " ";
        for (const auto& grade : student.grades) {
            outputFile << grade << ",";
        }
        outputFile << "\n";
    }

    outputFile.close();
}

int main() {
    std::vector<Student> students = {
            {"Kondrashov", 2, "A1", {85, 90, 78}},
            {"Schevchenko", 3, "B2", {92, 88, 76}},
            {"Matseniuk", 1, "C3", {80, 95, 82}}
    };

    createStudentFile("students.txt", students);
    std::string lowestSurname = findStudentWithLowestAverage(students);
    std::cout << "Студент з найгіршою середньою оцінкою: " << lowestSurname << std::endl;

    return 0;
}
