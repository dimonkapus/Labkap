#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <math.h>

int main(void) {
    unsigned n;
    // 100 <= n < 1000 according to problem statement
    scanf("%u", &n);

    // digits
    // n = n0 + n1 * 10 + n2 * 100
    unsigned n0 = n % 10;
    n /= 10;
    unsigned n1 = n % 10;
    n /= 10;
    unsigned n2 = n;

    if (n0 == n1 || n1 == n2) {
        puts("digits repetition detected");
        return 0;
    }

    printf(
            "ditigts permut: %d%d%d, %d%d%d, %d%d%d, %d%d%d, %d%d%d, %d%d%d\n",
            // all 6 permutations
            n0, n1, n2,
            n0, n2, n1,
            n1, n0, n2,
            n1, n2, n0,
            n2, n0, n1,
            n2, n1, n0
    );
}
