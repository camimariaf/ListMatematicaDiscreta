/*Escrever um programa para encontrar a solução de uma congruência do tipo ax ≡
b mod m.*/

#include <stdio.h>
// encontrando mdc de dois numeros inteiros e a combinacao linear
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
// garantindo que x seja entre 0 e m
int positivo(int x, int m){
    if(x > 1){
        return x;
    }
    x += m;
    positivo(x, m);
}
int main() {
    int a, b, m, x, mdc, s, t;
    printf("Digite os valores de a, b e m: ");
    scanf("%d %d %d", &a, &b, &m);

    mdc = euclides(a, m, &s, &t);
    printf("MDC(%d, %d) = %d\n", a, m, mdc);
    printf("%d * %d + %d * %d = %d\n", s, a, t, m, mdc);
    // conferindo se a congruência ax ≡ b mod m tem solução
    if (b % mdc != 0) {
        printf("A congruencia nao tem solucao.\n");
    }
    else{
        if(mdc > 1){
            a /= mdc;
            b /= mdc;
            m /= mdc;
        }
        x = s*b;
        if(x > m){
            x = x%m;
        }
        if(x < 1){
            x = positivo(x, m);
        }
        printf("X = %d\n", x);
        printf("Solucao geral: %d + %d * k", x, m);
    }
    return 0;
}