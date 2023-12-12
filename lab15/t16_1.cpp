#include <iostream>
#include <fstream>
#include <string>

class Person {
    std::string name;
    unsigned byear;

public:
    int input() {
        std::cout << "Enter name: ";
        std::cin >> name;

        std::cout << "Enter birth year: ";
        std::cin >> byear;

        return 0;
    }

    void show() const {
        std::cout << "Name: " << name << ", Birth Year: " << byear;
    }

    friend std::ostream& operator<<(std::ostream& os, const Person& person) {
        os << person.name << " " << person.byear;
        return os;
    }

    friend std::istream& operator>>(std::istream& is, Person& person) {
        is >> person.name >> person.byear;
        return is;
    }
};

class Friend : public Person {
    std::string phoneNumber;

public:
    int input() {
        Person::input();

        std::cout << "Enter phone number: ";
        std::cin >> phoneNumber;

        return 0;
    }

    void show() const {
        Person::show();
        std::cout << ", Phone Number: " << phoneNumber;
    }

    friend std::ostream& operator<<(std::ostream& os, const Friend& friendObj) {
        os << static_cast<const Person&>(friendObj) << " " << friendObj.phoneNumber;
        return os;
    }

    friend std::istream& operator>>(std::istream& is, Friend& friendObj) {
        is >> static_cast<Person&>(friendObj) >> friendObj.phoneNumber;
        return is;
    }
};

class PhoneBook {
    Friend friends[100];
    int count;

public:
    PhoneBook() : count(0) {}

    int addFriend(const Friend& friendObj) {
        if (count < 100) {
            friends[count++] = friendObj;
            return 0;
        } else {
            return -1;
        }
    }

    std::string findPhoneNumber(const std::string& name) const {
        for (int i = 0; i < count; ++i) {
            if (friends[i].name == name) {
                return friends[i].phoneNumber;
            }
        }

        return "Not found";
    }

    int updatePhoneNumber(const std::string& name, const std::string& newPhoneNumber) {
        for (int i = 0; i < count; ++i) {
            if (friends[i].name == name) {
                friends[i].phoneNumber = newPhoneNumber;
                return 0;
            }
        }

        return -1;
    }

    void saveToFile(const std::string& filename) const {
        std::ofstream outputFile(filename);

        if (!outputFile.is_open()) {
            std::cerr << "Unable to open file for writing." << std::endl;
            return;
        }

        for (int i = 0; i < count; ++i) {
            outputFile << friends[i] << "\n";
        }

        outputFile.close();
    }
};

int main() {
    PhoneBook phoneBook;
    Friend friend1;
    friend1.input();
    phoneBook.addFriend(friend1)
    Friend friend2;
    friend2.input();
    phoneBook.addFriend(friend2);
    phoneBook.saveToFile("phonebook.txt");
    std::string nameToFind = "John Doe";
    std::string newPhoneNumber = "555-1234";

    std::cout << "Phone number for " << nameToFind << ": " << phoneBook.findPhoneNumber(nameToFind) << std::endl;

    if (phoneBook.updatePhoneNumber(nameToFind, newPhoneNumber) == 0) {
        std::cout << "Phone number updated successfully." << std::endl;
    } else {
        std::cout << "Failed to update phone number. Entry not found." << std::endl;
    }

    std::cout << "Phonebook after update:\n";
    for (int i = 0; i < phoneBook.getCount(); ++i) {
        phoneBook.getFriend(i).show();
        std::cout << std::endl;
    }

    return 0;
}
