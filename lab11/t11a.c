#include <stdio.h>
#include <stdlib.h>

struct Passenger {
    char surname[50];
};

struct Luggage {
    int passengerNumber;
    int numberOfItems;
    float totalWeight;
};

void findPassengerByWeightDifference(struct Passenger passengers[], struct Luggage luggage[], int numPassengers, int numLuggage, float a) {
    float totalWeightSum = 0;
    int totalItems = 0;

    for (int i = 0; i < numLuggage; ++i) {
        totalWeightSum += luggage[i].totalWeight;
        totalItems += luggage[i].numberOfItems;
    }

    float averageWeight = totalWeightSum / totalItems;

    for (int i = 0; i < numLuggage; ++i) {
        float passengerAverageWeight = luggage[i].totalWeight / luggage[i].numberOfItems;

        if (abs(passengerAverageWeight - averageWeight) <= a) {
            printf("found: %s (№: %d)\n", passengers[luggage[i].passengerNumber].surname, luggage[i].passengerNumber);
        }
    }
}

int main() {
    struct Passenger passengers[] = {{"Petrachuk"}, {"Boyko"}, {"Schevchuk"}};
    struct Luggage luggage[] = {{0, 2, 20.0}, {1, 3, 30.0}, {2, 1, 10.0}};

    int numPassengers = sizeof(passengers) / sizeof(passengers[0]);
    int numLuggage = sizeof(luggage) / sizeof(luggage[0]);

    float a;
    printf("max m: ");
    scanf("%f", &a);

    findPassengerByWeightDifference(passengers, luggage, numPassengers, numLuggage, a);

    return 0;
}
