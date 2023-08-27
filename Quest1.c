//Escrever um programa que determina se um dado número inteiro é primo ou não.

#include <stdio.h>
#include <string.h>
#include <math.h>
#include <stdlib.h>


// calcula se o numero é primo
void primo(int num, int contador) {
    if (contador == num){
        printf("%d e um numero primo.\n"    , num);
        return;
    }
    if (num % contador == 0 || num < 2) {
        printf("%d nao e numero primo. \n", num);
        return;
    }
    primo(num, contador+1);
}
int main(){
    int contador = 2, num;
    printf("Digite um numero: ");
    scanf("%d", &num);
    primo(num,contador);
    return 0;
}