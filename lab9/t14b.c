#include <stdio.h>

struct Person {
    int nameNumber;
    char gender;
    float height;
};

int findTallestMan(struct Person L[], struct Person P[], int sizeL, int sizeP) {
    int tallestManIndex = -1;

    float maxManHeight = 0;

    for (int i = 0; i < sizeP; ++i) {
        if (P[i].gender == 'M') {
            for (int j = 0; j < sizeL; ++j) {
                if (L[j].nameNumber == P[i].nameNumber) {
                    if (P[i].height > maxManHeight) {
                        maxManHeight = P[i].height;
                        tallestManIndex = j;
                    }
                    break;
                }
            }
        }
    }

    return tallestManIndex;
}

int main() {
    struct Person L[] = {{1, 'M', 175.5}, {2, 'F', 160.0}, {3, 'M', 180.0}};
    struct Person P[] = {{2, 'F', 165.5}, {1, 'M', 178.0}, {3, 'M', 185.0}};

    int sizeL = sizeof(L) / sizeof(L[0]);
    int sizeP = sizeof(P) / sizeof(P[0]);
    int indexTallestMan = findTallestMan(L, P, sizeL, sizeP);

    if (indexTallestMan != -1) {
        printf("highest man name: %d\n", L[indexTallestMan].nameNumber);
    } else {
        printf("no high man.\n");
    }

    return 0;
}
