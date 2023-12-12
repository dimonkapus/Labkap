#include <stdio.h>
#include <string.h>

struct Seminar {
    char subject[100];
    char instructor[100];
    int groupNumber;
    char dayOfWeek[20];
    int hours;
    char classroom[20];
};

void inputSeminar(struct Seminar *seminar) {
    printf("subject: ");
    scanf("%s", seminar->subject);

    printf("Prof: ");
    scanf("%s", seminar->instructor);

    printf("Group: ");
    scanf("%d", &(seminar->groupNumber));

    printf("Day: ");
    scanf("%s", seminar->dayOfWeek);

    printf("Hours: ");
    scanf("%d", &(seminar->hours));

    printf("class: ");
    scanf("%s", seminar->classroom);
}

int main() {
    struct Seminar mySeminar;

    inputSeminar(&mySeminar);

    printf("\nData:\n");
    printf("subject: %s\n", mySeminar.subject);
    printf("Prof: %s\n", mySeminar.instructor);
    printf("Group: %d\n", mySeminar.groupNumber);
    printf("Day: %s\n", mySeminar.dayOfWeek);
    printf("Hours: %d\n", mySeminar.hours);
    printf("Class: %s\n", mySeminar.classroom);

    return 0;
}
