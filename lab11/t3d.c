#include <stdio.h>
#include <stdlib.h>

int isPalindrome(int number) {
    int originalNumber = number;
    int reversedNumber = 0;

    while (number > 0) {
        int digit = number % 10;
        reversedNumber = reversedNumber * 10 + digit;
        number /= 10;
    }

    return originalNumber == reversedNumber;
}

int main() {
    FILE *fileF, *fileG;
    int inputNumber;

    fileF = fopen("F.txt", "w");
    if (fileF == NULL) {
        fprintf(stderr, "error F\n");
        return 1;
    }

    printf("enter Z numbers (0 after done): ");
    while (1) {
        scanf("%d", &inputNumber);
        0
        if (inputNumber == 0) {
            break;
        }

        fprintf(fileF, "%d\n", inputNumber);
    }

    fclose(fileF);

    fileG = fopen("G.txt", "w");
    if (fileG == NULL) {
        fprintf(stderr, "error G\n");
        return 1;
    }

    fileF = fopen("F.txt", "r");
    if (fileF == NULL) {
        fprintf(stderr, "error F for reading\n");
        fclose(fileG);
        return 1;
    }

    while (fscanf(fileF, "%d", &inputNumber) != EOF) {
        if (isPalindrome(inputNumber)) {
            fprintf(fileG, "%d\n", inputNumber);
        }
    }

    fclose(fileF);
    fclose(fileG);

    printf("process's over F.txt та G.txt.\n");

    return 0;
}
