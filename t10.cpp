#include <stdio.h>

int main() {

    int x_values[] = {1, 2, 3, 4, 5};
    float y_values[] = {3.0, 1.0, 5.0, 4.0, 2.1};

    printf("x |");
    for (int i = 0; i < 5; ++i) {
        printf(" %d |", x_values[i]);
    }
    printf("\n");

    printf("- |");
    for (int i = 0; i < 5; ++i) {
        printf(" - - |");
    }
    printf("\n");

    printf("y |");
    for (int i = 0; i < 5; ++i) {
        printf(" %.1f |", y_values[i]);
    }
    printf("\n");

    return 0;
}
