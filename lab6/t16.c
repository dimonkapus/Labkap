#include <stdio.h>


double calculateFunctionValue(double x[], int d) {
    double result = 0.0;

    for (int i = 0; i < d; i++) {
        double term1 = 100 * (x[i + 1] - x[i] * x[i]);
        double term2 = x[i] - 1;
        result += term1 * term1 + term2 * term2;
    }

    return result;
}

int main() {

    int d;

    printf("dimension x: ");
    scanf("%d", &d);


    double x[d + 1];

    printf("x:\n");
    for (int i = 0; i <= d; i++) {
        printf("x[%d]: ", i);
        scanf("%lf", &x[i]);
    }

    double result = calculateFunctionValue(x, d);
    printf("f(x): %.4f\n", result);

    return 0;
}

