#include <stdio.h>

double calculate_vi(int n) {
    if (n == 0) {
        return 1; // v0 = 1
    } else if (n == 1) {
        return 0.3; // v1 = 0.3
    } else {
        double v_prev = 1, v_curr = 0.3;

        for (int i = 2; i <= n; ++i) {
            v_curr = (i + 2) * v_prev;
            v_prev = v_curr;
        }

        return v_curr;
    }
}

int main() {
    int n;

    printf("Num n: ");
    scanf("%d", &n);

    if (n < 0) {
        printf("Bad n. Enter not negative.\n");
        return 1;
    }

    double result = calculate_vi(n);

    printf("v_%d: %.6f\n", n, result);

    return 0;
}
