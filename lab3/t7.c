#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <math.h>

double* solve_quadratic(double a, double b, double c, double* roots_out) {
    double d = b * b - 4. * a * c;
    const double eps = 1e-9;
    if (d < -eps) {
        return roots_out;
    }
    if (d < eps) { // d = zero
        *roots_out++ = b / a * -0.5;
    } else {
        d = sqrt(d);
        *roots_out++ = 0.5 * (-b - d) / a;
        *roots_out++ = 0.5 * (-b + d) / a;
    }
    return roots_out;
}

void print_roots(size_t n, double* roots, char prefix) {
    if (n == 0) {
        printf("%c) no solutions\n", prefix);
    } else {
        printf("%c)", prefix);
        for (int i = 0; i < n; i++) {
            printf(" x%d = %lf", i, roots[i]);
        }
        putchar('\n');
    }
}

int main(void) {
    // example input: `1 -16 15`

    // a) ax^2 + bx + c = 0
    double a, b, c, quadratic_roots[2], biquadratic_roots[4], * r = biquadratic_roots;
    scanf("%lf%lf%lf", &a, &b, &c);
    size_t roots_count = solve_quadratic(a, b, c, quadratic_roots) - quadratic_roots;
    print_roots(roots_count, quadratic_roots, 'a');

    // b) ax^4 + bx^2 + c = 0
    scanf("%lf%lf%lf", &a, &b, &c);
    roots_count = solve_quadratic(a, b, c, quadratic_roots) - quadratic_roots;
    for (int i = 0; i < roots_count; i++) {
        r = solve_quadratic(1., 0., -quadratic_roots[i], r);
    }
    print_roots(r - biquadratic_roots, biquadratic_roots, 'b');
}
