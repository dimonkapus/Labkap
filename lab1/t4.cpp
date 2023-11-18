#include <stdio.h>
#include <math.h>

// Lab 1 Task 4

int main(void) {
    // "inputs"
    const long double m1 = 42e3;
    const long double m2 = 26e3;
    const long double gamma = 6.673e-11L;
    const long double r = 15.;
    // force
    long double f = gamma * m1 * m2 / (r * r);

    printf("F = %Le\n", f);
}
