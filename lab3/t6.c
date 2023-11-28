#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <math.h>

int main(void) {
    double a, b, c;
    scanf("%lf%lf%lf", &a, &b, &c);

    if (fabs(a) < fabs(b)) {
        double t = a;
        a = b;
        b = t;
    }
    if (fabs(a) < fabs(c)) {
        double t = a;
        a = c;
        c = t;
    }
    if (fabs(c) > fabs(b)) {
        double t = c;
        c = b;
        b = t;
    }

    printf("max: %lf min: %lf\n", a, c);
}