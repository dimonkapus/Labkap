#include <stdio.h>
#include <math.h>

int main() {
    int n;

    printf("Введіть кількість чисел n: ");
    scanf("%d", &n);

    double y[n];
    printf("Введіть %d дійсних чисел: ", n);
    for (int i = 0; i < n; ++i) {
        scanf("%lf", &y[i]);
    }

    double maxAbsZ = 0.0;
    for (int i = 0; i < n; ++i) {
        double zi;
        if (fabs(y[i]) <= 2) {
            zi = fabs(y[i]);
        } else {
            zi = 0.5;
        }

        if (zi > maxAbsZ) {
            maxAbsZ = zi;
        }
    }
    
    printf("Максимальне значення |zi|: %.2lf\n", maxAbsZ);

    return 0;
}

