#include <stdio.h>
#include <math.h>

double calculateFunction(double x, double d) {
    return exp(d * x * x);
}

int main() {
    double d, h;

    printf("d: ");
    scanf("%lf", &d);
    printf("h (> 0): ");
    scanf("%lf", &h);

    printf("\n   x      |    y\n");
    printf("-----------|-----------\n");

    for (double x = -3; x <= 3; x += h) {
        printf("%9.3lf | %9.6lf\n", x, calculateFunction(x, d));
    }

    return 0;
}

