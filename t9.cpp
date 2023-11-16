#include <stdio.h>

int main(void) {
    float a, b;
    scanf("%f %f", &a, &b);
    float av = (a + b) / 2.f;
    float h = 2.f / (1.f / a + 1.f / b);

    printf("av = %f\nh = %f\n", av, h);

    printf("\nav = %e\nh = %e\n", av, h);
}