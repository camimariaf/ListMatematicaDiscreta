/* Escrever um programa para decompor um determinado número inteiro em seus
fatores primos. */

#include <stdio.h>
#include <string.h>
#include <math.h>
#include <stdlib.h>

int e_primo(int num, int last) {
    for (int contador = last; contador <= sqrt(num); contador++) {
        if (num % contador == 0) {
            return 0;
        }
    }
    return 1;
}

int proximo_primo(int num, int divisor, int last) {
    for (int i = divisor + 1; i <= sqrt(num); i++) {
        if (e_primo(i, last)) {
            return i;
        }
    }
    return num;
}

void fator_primo(int num, int divisor) {
    if (num / divisor == 1) {
        printf("%d ", divisor);
    } else {
        printf("%d * ", divisor);
    }
}

int main() {
    int num, divisor = 2, last = 2;
    printf("digite um numero: ");
    scanf("%d", &num);

    while (num != 1) {
        if (num % divisor == 0) {
            fator_primo(num, divisor);
            num /= divisor;
            last = divisor;
        } else {
            divisor = proximo_primo(num, divisor, last);
        }
    }
    return 0;
}