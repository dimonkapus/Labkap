#include <iostream>

class Time {
private:
    int hours, minutes, seconds;

public:
    Time(int h, int m, int s) : hours(h), minutes(m), seconds(s) {}

    Time difference(const Time& other) const {
        int totalSeconds1 = hours * 3600 + minutes * 60 + seconds;
        int totalSeconds2 = other.hours * 3600 + other.minutes * 60 + other.seconds;

        int diffSeconds = std::abs(totalSeconds1 - totalSeconds2);

        int h = diffSeconds / 3600;
        int m = (diffSeconds % 3600) / 60;
        int s = diffSeconds % 60;

        return Time(h, m, s);
    }

    void display() const {
        std::cout << hours << " hours " << minutes << " min " << seconds << " sec" << std::endl;
    }
};

class Date {
private:
    int year, month, day;
    Date(int y, int m, int d) : year(y), month(m), day(d) {}

public:
    static Date create(int y, int m, int d) {
        static Date instance(y, m, d);
        return instance;
    }

    Date difference(const Date& other) const {
        int diffYears = std::abs(year - other.year);
        int diffMonths = std::abs(month - other.month);
        int diffDays = std::abs(day - other.day);

        return Date::create(diffYears, diffMonths, diffDays);
    }

    void display() const {
        std::cout << year << " years " << month << " months " << day << "days" << std::endl;
    }
};

int main() {
    Time time1(10, 30, 45);
    Time time2(8, 15, 20);

    Time timeDifference = time1.difference(time2);

    std::cout << "dif between t1 and t2: ";
    timeDifference.display();

    Date date1 = Date::create(2022, 5, 15);
    Date date2 = Date::create(2020, 2, 10);

    Date dateDifference = date1.difference(date2);

    std::cout << "dif between date1 and date2 : ";
    dateDifference.display();

    return 0;
}
