#include <iostream>
#include <fstream>
#include <vector>
#include <set>
#include <algorithm>
#include <sstream>

struct Date {
    int day;
    std::string month;
    int year;

    Date(int day, const std::string& month, int year) : day(day), month(month), year(year) {}

    bool operator<(const Date& other) const {
        if (year != other.year) {
            return year < other.year;
        }
        if (month != other.month) {
            return month < other.month;
        }
        return day < other.day;
    }
};

int main() {
    std::ifstream inputFile("dates.txt");
    std::ofstream outputFile("sorted_dates.txt");

    if (!inputFile.is_open() || !outputFile.is_open()) {
        std::cerr << "Unable to open files." << std::endl;
        return 1;
    }

    std::vector<Date> dates;
    std::set<Date> uniqueDates;

    int day, year;
    std::string month;

    while (inputFile >> day >> month >> year) {
        dates.emplace_back(day, month, year);
    }

    for (const auto& date : dates) {
        uniqueDates.insert(date);
    }
    
    for (const auto& date : uniqueDates) {
        outputFile << date.year << "/" << date.month << "/" << date.day << std::endl;
    }

    inputFile.close();
    outputFile.close();

    return 0;
}
