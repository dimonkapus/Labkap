#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>

int main(void) {
    double a, b;
    scanf("%lf%lf", &a, &b);

    if (a < b) {
        double c = a;
        a = b;
        b = c;
    }

    printf("max: %lf min: %lf\n", a, b);
}
