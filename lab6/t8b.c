#include <stdio.h>

int main() {

    int N;

    printf("N: ");
    scanf("%d", &N);

    int numbers[N];

    printf("Enter %d nat num:\n", N);
    for (int i = 0; i < N; i++) {
        scanf("%d", &numbers[i]);
    }

    int count = 0;
    for (int i = 0; i < N; i++) {
        int cubeRoot = 0;
        while (cubeRoot * cubeRoot * cubeRoot < numbers[i]) {
            cubeRoot++;
        }


        if (cubeRoot * cubeRoot * cubeRoot == numbers[i] && cubeRoot % 2 == 0) {
            count++;
        }
    }


    printf("Num of cubes: %d\n", count);

    return 0;
}

