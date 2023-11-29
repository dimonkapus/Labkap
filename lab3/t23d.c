#include <stdio.h>

double sReLu(double tl, double tr, double al, double ar, double x) {
    if (x <= tl) {
        return tl + al * (x - tl);
    } else if (x < tr) {
        return 0.0;
    } else {
        return tr + ar * (x - tr);
    }
}

double sReLu_derivative(double tl, double tr, double al, double ar, double x) {
    if (x <= tl) {
        return al;
    } else if (x < tr) {
        return 0.0;
    } else {
        return ar;
    }
}

int main() {
    double tl, tr, al, ar, x;
    
    printf("tl: ");
    scanf("%lf", &tl);
    printf("tr: ");
    scanf("%lf", &tr);
    printf("al: ");
    scanf("%lf", &al);
    printf("ar: ");
    scanf("%lf", &ar);
    printf("x: ");
    scanf("%lf", &x);

    printf("sReLu(%.2lf, %.2lf, %.2lf, %.2lf, %.2lf) = %.2lf\n", tl, tr, al, ar, x, sReLu(tl, tr, al, ar, x));
    printf("derivative sReLu(%.2lf, %.2lf, %.2lf, %.2lf, %.2lf) = %.2lf\n", tl, tr, al, ar, x, sReLu_derivative(tl, tr, al, ar, x));

    return 0;
}

