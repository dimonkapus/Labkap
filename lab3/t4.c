#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdint.h>

uint16_t uint8mul(uint8_t a, uint8_t b) {
    return (uint16_t)a * (uint16_t)b;
}

int main(void) {
    uint8_t a, b;
    scanf("%hhu%hhu", &a, &b);
    printf("%hu", uint8mul(a, b));
}
