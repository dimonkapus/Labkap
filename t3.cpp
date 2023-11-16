#include <stdio.h>

int main(void) {
    char digit;
    scanf("%c", &digit);

    printf(
            "- %c - %c - %c\n"
            "%c | %c | %c\n"
            "- %c - %c - %c\n",
            digit, digit, digit,
            digit, digit, digit,
            digit, digit, digit
    );
}
