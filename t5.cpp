#include <stdio.h>

int main(void) {
    const float x = 1.426f;

    float a0 = x * x;
    float a1 = a0 * a0;

    float b0 = x * x;
    float b1 = b0 * b0 * b0;

    float c0 = x * x * x;
    float c1 = c0 * c0 * c0;

    float d0 = x * x;
    float d1 = d0 * d0 * x;
    float d2 = d1 * d1 * d1;

    float e0 = x * x;
    float e1 = e0 * e0 * e0 * x;
    float e2 = e1 * e1;
    float e3 = e2 * e2;

    float f0 = x * x;
    float f1 = f0 * f0;
    float f2 = f1 * f1;
    float f3 = f2 * f2;
    float f4 = f3 * f3;
    float f5 = f4 * f4;

    printf("x=%f\n"
           "a) x^4=%f\nb) x^6=%f\nc) x^9=%f\n"
           "d) x^15=%f\ne) x^28=%f\nf) x^64=%f\n",
           x, a1, b1, c1, d2, e3, f5
    );
}
