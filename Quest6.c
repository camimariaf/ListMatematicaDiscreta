/*Escrever um programa para encontrar os coeficientes s e t da combinação linear
mdc(a, b) = s · a + t · b.*/

#include <stdio.h>

int euclides(int a, int b, int *s, int *t) {
    if (b == 0) {
        *s = 1;
        *t = 0;
        return a;
    }

    int s1, t1, mdc;
    mdc = euclides(b, a % b, &s1, &t1);
    *s = t1;
    *t = s1 - (a / b) * t1;
    return mdc;
}

int main() {
    int a, b, s, t, mdc;

    printf("Digite dois numeros inteiros positivos:\n");
    scanf("%d %d", &a, &b);

    mdc = euclides(a, b, &s, &t);
    printf("MDC(%d, %d) = %d\n", a, b, mdc);
    printf("%d * %d + %d * %d = %d\n", s, a, t, b, mdc);

    return 0;
}