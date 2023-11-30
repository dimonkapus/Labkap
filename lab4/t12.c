#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdint.h>   // uint64_t
#include <inttypes.h> // PRIu64

// Lab 4 Task 12

// computes subfactorial of n
// !n = n! * (1/0! - 1/1! + 1/2! - 1/3! ... + (-1)^n/n!)
uint64_t subfact(unsigned n) {
    // !0 = 1
    // !1 = 0
    if (n < 2) {
        return 1-n;
    }
    // n >= 2: !n = !(n-1) * n + (-1)^n
    return subfact(n - 1) * n + (n % 2 == 0 ? 1 : -1);
}

int main(void) {
    unsigned n;
    scanf("%u", &n);

    printf("!%u = %" PRIu64 "\n", n, subfact(n));
}
