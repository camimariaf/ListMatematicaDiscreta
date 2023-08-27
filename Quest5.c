/*Escrever um programa para determinar o mdc de dois números com base no Al-
goritmo de Euclides.*/

#include <stdio.h>

//algoritmo de euclides
int alg(int num1, int num2) {
    int resto;

    while (num2 != 0) {
        resto = num1 % num2;
        num1 = num2;
        num2 = resto;
    }

    return num1;
}
int main() {
    int num1, num2, result;

    printf("Digite o primeiro numero: ");
    scanf("%d", &num1);
    printf("Digite o segundo numero: ");
    scanf("%d", &num2);

    result = alg(num1, num2);

    printf("MDC (%d, %d) = %d.\n", num1, num2, result);

    return 0;
}