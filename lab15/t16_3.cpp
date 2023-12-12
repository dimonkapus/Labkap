#include <iostream>
#include <fstream>
#include <string>
#include <vector>

class Person {
protected:
    std::string name;
    unsigned byear;

public:
    Person() : byear(0) {}

    virtual void input() {
        std::cout << "Enter name: ";
        std::cin >> name;
        std::cout << "Enter birth year: ";
        std::cin >> byear;
    }

    virtual void output() const {
        std::cout << "Name: " << name << ", Birth Year: " << byear;
    }

    const std::string& getName() const {
        return name;
    }
};

class Passenger : public Person {
private:
    std::string departure;
    std::string destination;
    int seat;

public:
    Passenger() : seat(0) {}

    void input() override {
        Person::input();
        std::cout << "Enter departure location: ";
        std::cin >> departure;
        std::cout << "Enter destination location: ";
        std::cin >> destination;
        std::cout << "Enter seat number: ";
        std::cin >> seat;
    }

    void output() const override {
        Person::output();
        std::cout << ", Departure: " << departure << ", Destination: " << destination << ", Seat: " << seat;
    }

    int getSeat() const {
        return seat;
    }

    const std::string& getDeparture() const {
        return departure;
    }

    const std::string& getDestination() const {
        return destination;
    }
};

class Kaca {
private:
    std::vector<Passenger> passengers;

public:
    void addPassenger(const Passenger& passenger) {
        passengers.push_back(passenger);
    }

    void displayPassengers() const {
        for (const auto& passenger : passengers) {
            passenger.output();
            std::cout << std::endl;
        }
    }

    const Passenger* findPassengerByName(const std::string& name) const {
        for (const auto& passenger : passengers) {
            if (passenger.getName() == name) {
                return &passenger;
            }
        }
        return nullptr; // Passenger not found
    }

    const Passenger* findPassengerByDeparture(const std::string& departure) const {
        for (const auto& passenger : passengers) {
            if (passenger.getDeparture() == departure) {
                return &passenger;
            }
        }
        return nullptr;

    const Passenger* findPassengerByDestination(const std::string& destination) const {
        for (const auto& passenger : passengers) {
            if (passenger.getDestination() == destination) {
                return &passenger;
            }
        }
        return nullptr;
    }

    const Passenger* findAvailableSeat() const {
        int smallestAvailableSeat = std::numeric_limits<int>::max();
        const Passenger* availablePassenger = nullptr;

        for (const auto& passenger : passengers) {
            if (passenger.getSeat() < smallestAvailableSeat) {
                smallestAvailableSeat = passenger.getSeat();
            }
        }

        if (smallestAvailableSeat != std::numeric_limits<int>::max()) {
            for (const auto& passenger : passengers) {
                if (passenger.getSeat() == smallestAvailableSeat) {
                    availablePassenger = &passenger;
                    break;
                }
            }
        }

        return availablePassenger;
    }
};

int main() {
    Kaca kaca;

    Passenger passenger1;
    passenger1.input();
    kaca.addPassenger(passenger1);

    Passenger passenger2;
    passenger2.input();
    kaca.addPassenger(passenger2);

    Passenger passenger3;
    passenger3.input();
    kaca.addPassenger(passenger3);

    std::cout << "All Passengers:\n";
    kaca.displayPassengers();

    std::string nameToFind = "John Doe";
    const Passenger* foundPassengerByName = kaca.findPassengerByName(nameToFind);
    if (foundPassengerByName != nullptr) {
        std::cout << "Passenger found by name:\n";
        foundPassengerByName->output();
        std::cout << std::endl;
    } else {
        std::cout << "Passenger with name " << nameToFind << " not found.\n";
    }

    std::string departureToFind = "CityA";
    const Passenger* foundPassengerByDeparture = kaca.findPassengerByDeparture(departureToFind);
    if (foundPassengerByDeparture != nullptr) {
        std::cout << "Passenger found by departure:\n";
        foundPassengerByDeparture->output();
        std::cout << std::endl;
    } else {
        std::cout << "Passenger with departure " << departureToFind << " not found.\n";
    }

    std::string destinationToFind = "CityB";
    const Passenger* foundPassengerByDestination = kaca.findPassengerByDestination(destinationToFind);
    if (foundPassengerByDestination != nullptr) {
        std::cout << "Passenger found by destination:\n";
        foundPassengerByDestination->output();
        std::cout << std::endl;
    } else {
        std::cout << "Passenger with destination " << destinationToFind << " not found.\n";
    }

    const Passenger* availableSeat = kaca.findAvailableSeat();
    if (availableSeat != nullptr) {
        std::cout << "Available seat found:\n";
        availableSeat->output();
        std::cout << std::endl;
    } else {
        std::cout << "No available seat found.\n";
    }

    return 0;
}
