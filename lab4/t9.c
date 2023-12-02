#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdint.h>   // uint64_t
#include <inttypes.h> // SCNu64, PRIu64

int main(void) {
    uint64_t n, r = 0;
    scanf("%" SCNu64, &n);

    do {
        r++;
    } while (1llu<<r <= n && r < 64);

    printf("r = %" PRIu64 "\n", r);
}
