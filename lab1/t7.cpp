#include <stdio.h>
#include <math.h>

int main(void) {
    float x;
    scanf("%f", &x);


    float x_int1 = (float)(int)x, x_fract1 = x - x_int1;


    float x_int2, x_fract2 = modff(x, &x_int2);

    printf("int1: %f fract1: %f\n", x_int1, x_fract1);
    printf("int2: %f fract2: %f\n", x_int2, x_fract2);
}