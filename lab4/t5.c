#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>

int main(void) {
    int n;
    scanf("%d", &n);

    // using for loop
    int f2 = 1;
    for (int k = n; k > 1; k -= 2) {
        f2 *= k;
        printf("%d: %d\n", k, f2);
    }
    printf("%d\n", f2);

    // using while loop
    int f = 1;
    while (n > 1) {
        f *= n;
        n -= 2;
    }
    printf("%d\n", f);
}