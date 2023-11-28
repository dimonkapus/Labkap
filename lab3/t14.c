#include <stdio.h>
#include <math.h>

int main() {
    double r, a, b, c;

    printf("r: ");
    scanf("%lf", &r);
    printf("a: ");
    scanf("%lf", &a);
    printf("b: ");
    scanf("%lf", &b);
    printf("c: ");
    scanf("%lf", &c);

    if (a + r < 0 || a - r > 0 || c <= 0) {

        printf("no dots.\n");
    } else {

        double y1 = b + c * c;
        double y2 = b - c * c;


        printf("dots:\n");
        printf("(%.2lf, %.2lf)\n", a, y1);
        printf("(%.2lf, %.2lf)\n", a, y2);
    }

    return 0;
}

