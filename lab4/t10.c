#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <float.h>

int main(void) {
    printf("%.18lf\n", DBL_EPSILON);

    double a = 1.;
    do {
        a /= 2.;
    } while (1. != a+1.);

    printf("%.18lf\n", a*2.);
}
