#include <stdio.h>

struct Person {
    int nameNumber;
    char gender;
    float height;
};

float averageHeightOfWomen(struct Person L[], struct Person P[], int sizeL, int sizeP) {
    int womenCount = 0;
    float totalHeight = 0;

    for (int i = 0; i < sizeP; ++i) {
        if (P[i].gender == 'F') {
            for (int j = 0; j < sizeL; ++j) {
                if (L[j].nameNumber == P[i].nameNumber) {
                    totalHeight += L[j].height;
                    womenCount++;
                    break;
                }
            }
        }
    }

    if (womenCount > 0) {
        return totalHeight / womenCount;
    } else {
        return 0.0;
    }
}

int main() {
    struct Person L[] = {{1, 'M', 175.5}, {2, 'F', 160.0}, {3, 'M', 180.0}};
    struct Person P[] = {{2, 'F', 165.5}, {1, 'M', 178.0}};

    int sizeL = sizeof(L) / sizeof(L[0]);
    int sizeP = sizeof(P) / sizeof(P[0]);

    float averageWomenHeight = averageHeightOfWomen(L, P, sizeL, sizeP);

    printf("AFH: %.2f\n", averageWomenHeight);

    return 0;
}
