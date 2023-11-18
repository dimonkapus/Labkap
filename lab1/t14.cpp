#include <stdio.h>
#include <math.h>

int main() {

    double a, t, v, dis;

    printf("a: ");
    scanf("%lf", &a);

    printf("t: ");
    scanf("%lf", &t);

    dis = 0.5 * a * pow(t, 2);

    v = a * t;

    printf("\nВідстань, пройдена за час %lf секунд: %lf метрів\n", t, dis);
    printf("Час, за який тіло досягне швидкості %lf м/с: %lf секунд\n", v, t);

    return 0;
}