#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>

int main(void) {
    double av = 0., av_h = 0.;

    int i = 0;
    while (1) {
        printf("a[%d]=", i);
        int n;
        scanf("%d", &n);
        if (n == 0) {
            break;
        }
        i++;
        av += n;
        av_h += 1. / n;
    }
    av = av / i;
    av_h = i / av_h;

    printf("av = %lf\n", av);
    printf("av_h = %lf\n", av_h);
}
