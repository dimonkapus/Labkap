
#include <stdio.h>
#include <math.h>

double compute_ln_series(double x, double epsilon) {
    double sum = 0.0;
    double term = x;
    int n = 1;

    while (fabs(term) >= epsilon) {
        sum += term;
        term *= -x * n / (n + 1);
        n++;
    }

    return sum;
}

int main() {
    double x, epsilon;

    printf("x (|x| < 1): ");
    scanf("%lf", &x);

    if (fabs(x) >= 1) {
        printf("Error: |x| > 1.\n");
        return 1;
    }

    printf("epsilon (> 0): ");
    scanf("%lf", &epsilon);


    if (epsilon <= 0) {
        printf("Error: epsilon > 0.\n");
        return 1;
    }

    double result = compute_ln_series(x, epsilon);
    printf("ln(1 + %.2f), epsilon = %.5f = %.5f\n", x, epsilon, result);

    return 0;
}
